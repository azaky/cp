'''
Input arguments are input file (easy.in / hard.in) and a corresponding
answers file (easy.answers / hard.answers).
'''
import sys


class Clue(object):
    def __init__(self, r, c, d, answers):
        self.r = r
        self.c = c
        self.d = d
        self.answers = answers

    def __len__(self):
        return len(self.answers)


def in_bounds(r, c):
    return r >= 0 and r < R and c >= 0 and c < C


dr, dc = [0, 1], [1, 0]  # 0 - horizontal; 1 - vertical
def can_place(r, c, d, word):
    for i in xrange(len(word)):
        if not in_bounds(r, c) or board[r][c] not in ('#', word[i]):
            return False
        r += dr[d]
        c += dc[d]
    return not in_bounds(r, c) or board[r][c] == '.'


def place(r, c, d, word):
    for i in xrange(len(word)):
        board[r][c] = word[i]
        r += dr[d]
        c += dc[d]


def parse_input(line):
    '''Parse input line into tokens:
        row column clue
    '''
    s1 = line.find(' ')
    s2 = line.find(' ', s1+1)
    return int(line[:s1]), int(line[s1+1:s2]), line[s2+1:]


input_fn = sys.argv[1]
answers_fn = sys.argv[2]

# read answers file
answers = {}
with open(answers_fn, 'r') as f:
    for line in f:
        tokens = line.strip().split(';')
        clue, ans = tokens[0], tokens[1:]
        answers[clue] = ans


# read input
with open(input_fn, 'r') as f:
    R, C = map(int, f.readline().split())
    board = []
    for i in xrange(R):
        board.append(list(f.readline().strip()))
    clues = []
    # read horizontal clues
    n = int(f.readline())
    for i in xrange(n):
        r, c, clue = parse_input(f.readline().strip())
        clues.append(Clue(r, c, 0, answers[clue]))
    # read vertical clues
    n = int(f.readline())
    for i in xrange(n):
        r, c, clue = parse_input(f.readline().strip())
        clues.append(Clue(r, c, 1, answers[clue]))


# solve
while clues:
    unplaced = []
    for clue in clues:
        good = []
        for ans in clue.answers:
            if can_place(clue.r, clue.c, clue.d, ans):
                good.append(ans)
        if len(good) == 1:
            place(clue.r, clue.c, clue.d, good[0])
        else:
            unplaced.append(clue)
    clues = unplaced


for row in board:
    print ''.join(row)
