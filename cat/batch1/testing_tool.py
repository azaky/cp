#!/usr/bin/env python3
"""
Untuk menjalankan alat bantu testing, jalankan:

    python testing_tool.py [--verbose] <input file> <program> <arguments>

dengan `<arguments>` adalah argumen opsional untuk menjalankan program peserta.
Sebagai contoh:

    python testing_tool.py test.in ./myprogram
    python testing_tool.py test.in java -cp . Main
    python testing_tool.py test.in python myprogram.py

Jika argumen `--verbose` diberikan, maka alat bantu testing akan mengeluarkan
interaksi dengan program peserta.
"""

import argparse
from dataclasses import dataclass
import subprocess
import sys
from typing import List, Tuple, TextIO

MIN_N = 3
MAX_N = 2000
MAX_QUERY_COUNT = 3000

QUERY_ACTION = "?"
ANSWER_ACTION = "!"
WRONG_ANSWER = -1
CORRECT_ANSWER = 1


class WrongAnswer(RuntimeError):
    """Raised whenever an incorrect answer is received."""
    pass


def vprint(*args, verbose: bool, file: TextIO, **kwargs) -> None:
    """Print to `file`, and also to stdout if `verbose` is true."""
    if verbose:
        print("< ", end="")
        print(*args, **kwargs)
        sys.stdout.flush()
    print(*args, file=file, flush=True, **kwargs)


def vreadline(data: TextIO, *, verbose: bool) -> str:
    """Read a line from `data`, and also log it to stdout if `verbose` is true."""
    line = data.readline()
    if verbose and line:
        print(">", line.rstrip("\n"))
    return line


@dataclass(frozen=True)
class Point:
    x: int
    y: int

    def __sub__(self, other: 'Point') -> 'Point':
        return Point(self.x - other.x, self.y - other.y)

    def cross(self, other: 'Point') -> int:
        return self.x * other.y - self.y * other.x

    def __str__(self) -> str:
        return f"({self.x}, {self.y})"


class Line:

    def __init__(self, p: Point, q: Point):
        # line: a * y = b * x + c
        if p.x > q.x:
            p, q = q, p
        self.a = q.x - p.x
        self.b = q.y - p.y
        self.c = self.a * p.y - self.b * p.x

    def is_point_above_line(self, p: Point) -> int:
        return self.a * p.y > self.b * p.x + self.c


@dataclass(frozen=True)
class ConvexPolygon:
    n: int
    points: List[Point]
    order: List[int]

    def query(self, p: int, q: int) -> int:
        # change to 0-index
        p, q = p - 1, q - 1
        line = Line(self.points[p], self.points[q])
        count = 0
        for point in self.points:
            if line.is_point_above_line(point):
                count += 1
        return count

    def check_answer(self, answer: List[int]) -> bool:
        if self.order[0] not in answer:
            return False
        idx = answer.index(self.order[0])

        # shift to have the same starting point
        shifted = answer[idx:] + answer[:idx]
        if shifted == self.order:
            return True

        # reverse direction (keeping the starting point the same)
        shifted_reversed = [shifted[0]] + list(reversed(shifted[1:]))
        return shifted_reversed == self.order


def sign(x: int) -> int:
    if x == 0:
        return 0
    return 1 if x > 0 else -1


def direction(a: Point, b: Point, c: Point) -> int:
    return sign((b - a).cross(c - b))


def is_intersect(a: Point, b: Point, p: Point, q: Point) -> bool:
    if direction(a, b, p) * direction(a, b, q) > 0:
        return False
    if direction(p, q, a) * direction(p, q, b) > 0:
        return False
    return True


def is_permutation(perm: List[int]) -> bool:
    n = len(perm)
    return sorted(perm) == list(range(1, n + 1))


def invalid_input(error_msg: str) -> None:
    raise ValueError(f"Input tidak valid: {error_msg}")


def validate_polygon(polygon: ConvexPolygon) -> None:
    n = polygon.n
    if not (MIN_N <= n <= MAX_N):
        invalid_input("Banyaknya titik sudut tidak valid")
    if not is_permutation(polygon.order):
        invalid_input("Barisan B bukan sebuah permutasi yang valid")
    all_x = set()
    for p in polygon.points:
        if p.x in all_x:
            invalid_input(
                "Terdapat 2 titik sudut dengan koordinat x yang sama")
        all_x.add(p.x)
    ordered_points = []
    for i in range(n):
        ordered_points.append(polygon.points[polygon.order[i] - 1])
    ordered_points.append(ordered_points[0])
    ordered_points.append(ordered_points[1])
    order_direction = direction(*ordered_points[:3])
    for i in range(n):
        a, b, c = ordered_points[i:i + 3]
        if direction(a, b, c) != order_direction:
            invalid_input("Terdapat sudut interior dalam poligon yang tidak"
                          " kurang dari 180 derajat")
        until = n if i > 0 else n - 1
        for j in range(i + 2, until):
            p, q = ordered_points[j:j + 2]
            if is_intersect(a, b, p, q):
                invalid_input(
                    f"Sisi [{a} - {b}] berpotongan dengan sisi [{p} - {q}]")


def parse_and_validate_input(lines: List[str]) -> ConvexPolygon:

    def parse_ints(line: str, size: int) -> List[int]:
        tokens = line.split()
        if len(tokens) != size:
            invalid_input(
                f"Banyaknya bilangan tidak sesuai pada '{line[:100].strip()}'"
                f" (diharapkan ada {size} bilangan)")
        try:
            return list(map(int, tokens))
        except ValueError as exc:
            invalid_input(
                f"Terdapat selain bilangan bulat pada baris '{line[:100].strip()}'"
            )

    if not lines:
        invalid_input("Input kosong")
    n = parse_ints(lines[0], 1)[0]
    if len(lines) < n + 2:
        invalid_input("Banyaknya baris tidak sesuai")
    points = []
    for i in range(n):
        x, y = parse_ints(lines[i + 1], 2)
        points.append(Point(x, y))
    order = parse_ints(lines[n + 1], n)

    polygon = ConvexPolygon(n=n, points=points, order=order)
    validate_polygon(polygon)
    return polygon


def interact(process: subprocess.Popen, polygon: ConvexPolygon, *,
             verbose: bool) -> int:

    def parse_int(token: str, name: str) -> int:
        try:
            return int(token)
        except ValueError as exc:
            raise WrongAnswer(
                f"{name} bukan merupakan bilangan bulat") from exc

    n = polygon.n
    vprint(n, file=process.stdin, verbose=verbose)

    query_count = 0
    try:
        while True:
            line = vreadline(process.stdout, verbose=verbose)
            if not line:
                vprint(WRONG_ANSWER, file=process.stdin, verbose=verbose)
                raise WrongAnswer("Tidak ada aksi yang diberikan")

            tokens = line.split()
            if not tokens:
                continue

            action = tokens[0]
            if action == QUERY_ACTION:
                if len(tokens) < 3:
                    vprint(WRONG_ANSWER, file=process.stdin, verbose=verbose)
                    raise WrongAnswer("p atau q tidak diberikan")

                p = parse_int(tokens[1], "p")
                q = parse_int(tokens[2], "q")

                if p < 1 or p > n or q < 1 or q > n:
                    vprint(WRONG_ANSWER, file=process.stdin, verbose=verbose)
                    raise WrongAnswer("p atau q di luar batas")
                if p == q:
                    vprint(WRONG_ANSWER, file=process.stdin, verbose=verbose)
                    raise WrongAnswer("p sama dengan q")

                query_count += 1
                if query_count > MAX_QUERY_COUNT:
                    vprint(WRONG_ANSWER, file=process.stdin, verbose=verbose)
                    raise WrongAnswer("Batas pertanyaan terlampaui")

                result = polygon.query(p, q)
                vprint(result, file=process.stdin, verbose=verbose)

            elif action == ANSWER_ACTION:
                if len(tokens) != n + 1:
                    vprint(WRONG_ANSWER, file=process.stdin, verbose=verbose)
                    raise WrongAnswer("Ukuran permutasi bukan n")

                answer = [
                    parse_int(tokens[i + 1], f"A[{i + 1}]") for i in range(n)
                ]
                if polygon.check_answer(answer):
                    vprint(CORRECT_ANSWER, file=process.stdin, verbose=verbose)
                    break
                else:
                    vprint(WRONG_ANSWER, file=process.stdin, verbose=verbose)
                    raise WrongAnswer("Jawaban urutan salah")
            else:
                vprint(WRONG_ANSWER, file=process.stdin, verbose=verbose)
                raise WrongAnswer(f"Aksi tidak diketahui: {action}")

    except BrokenPipeError as exc:
        raise WrongAnswer("Tidak dapat mengirim masukan ke program peserta"
                          " - mungkin sudah berhenti") from exc

    line = vreadline(process.stdout, verbose=verbose)
    if line.strip() != "":
        raise WrongAnswer("Terdapat keluaran berlebih dari program peserta")
    return query_count


def main() -> int:
    parser = argparse.ArgumentParser(
        usage="%(prog)s [--verbose] data.in program [args...]")
    parser.add_argument("--verbose",
                        "-v",
                        action="store_true",
                        help="Keluarkan interaksi")
    parser.add_argument("data")
    parser.add_argument("program", nargs=argparse.REMAINDER)

    args = parser.parse_args()
    if not args.program:
        parser.error("Harus sebutkan program untuk dijalankan")

    with open(args.data, "r", encoding="utf-8") as data:
        lines = data.readlines()
        polygon = parse_and_validate_input(lines)

    process = subprocess.Popen(
        args.program,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        encoding="utf-8",
        errors="surrogateescape",
    )
    try:
        try:
            query_count = interact(process, polygon, verbose=args.verbose)
        except WrongAnswer as exc:
            print("Wrong answer ({})".format(exc))
            return 1
        process.wait()
    finally:
        if process.poll() is None:
            try:
                process.terminate()
            except ProcessLookupError:
                pass
        process.wait()
    if process.returncode < 0:
        print(
            f"Run-time error (process exited with signal {-process.returncode})"
        )
        return 1
    if process.returncode > 0:
        print(
            f"Run-time error (process exited with status {process.returncode})"
        )
        return 1

    print(f"Accepted (dengan {query_count} pertanyaan)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
