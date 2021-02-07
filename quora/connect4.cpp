#include <bits/stdc++.h>
using namespace std;

int a[10][10];

const int diff[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

int check() {
  for (int r = 1; r <= 6; ++r) {
    for (int c = 1; c <= 7; ++c) {
      if (!a[r][c]) continue;
      for (int d = 0; d < 4; ++d) {
        int nr = r, nc = c;
        bool valid = true;
        for (int i = 0; i < 3 && valid; ++i) {
          nr += diff[d][0];
          nc += diff[d][1];
          if (nr < 1 || nr > 6) valid = false;
          if (nc < 1 || nc > 7) valid = false;
          if (a[nr][nc] != a[r][c]) valid = false;
        }
        if (valid) return a[r][c];
      }
    }
  }
  return 0;
}

int main() {
  int turn = 1;
  int cnt = 0;
  int r, c;
  while (scanf("%d", &c) == 1) {
    cnt++;
    r = 1;
    while (a[r][c]) r++;
    a[r][c] = turn;
    // printf("%d\n", cnt);
    // for (int i = 1; i <= 6; ++i) {
    //   for (int j = 1; j <= 7; ++j) {
    //     printf("%d", a[i][j]);
    //   }
    //   puts("");
    // }
    // puts("");
    if (check()) {
      printf("%s %d\n", turn == 1 ? "RED" : "YELLOW", cnt);
      return 0;
    }

    turn = 3-turn;
  }
  puts("DRAW");
}