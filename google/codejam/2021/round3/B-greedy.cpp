#include <bits/stdc++.h>
using namespace std;

void solve() {
  int R, C;
  scanf("%d%d", &R, &C);
  vector<int> S(R), D(C);

  int Ssum = 0, Dsum = 0;
  for (int i = 0; i < R; ++i) {
    scanf("%d", &S[i]);
    Ssum += S[i];
  }
  for (int i = 0; i < C; ++i) {
    scanf("%d", &D[i]);
    Dsum += D[i];
  }

  if (Ssum != Dsum) {
    puts("IMPOSSIBLE");
    return;
  }

  vector<vector<char>> A(R, vector<char>(C, '\\'));

  auto printBoard = [&]() {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        putchar(A[i][j] == '/' ? '1' : '0');
      }
      putchar('\n');
    }
  };

  while (Ssum > 0) {
    int bi = -1, bj = -1;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (A[i][j] == '\\' && S[i] && D[j]) {
          if (bi == -1 || S[i] > S[bi] || (S[i] == S[bi] && D[j] > D[bj])) {
            bi = i;
            bj = j;
          }
        }
      }
    }

    if (bi == -1) {
      puts("IMPOSSIBLE");
      return;
    }

    S[bi]--;
    D[bj]--;
    Ssum--; Dsum--;
    A[bi][bj] = '/';

    printf("flipping (%d, %d)\n", bi, bj);
    printBoard();
    puts("");
  }
  // puts("");

  auto findSquare = [&]() -> pair<int,pair<int,int>> {
    for (int s = 1; s <= min(R, C)/2; ++s) {
      for (int i = 0; i + 2*s <= R; ++i) {
        for (int j = 0; j + 2*s <= C; ++j) {
          bool square = true;
          for (int k = 0; k < s && square; ++k) {
            // left-top
            if (A[i + (s-1) - k][j + k] == '\\') square = false;
            // top-right
            if (A[i + k][j + s + k] == '/') square = false;
            // right-bottom
            if (A[i + s + (s-1) - k][j + s + k] == '\\') square = false;
            // left-bottom
            if (A[i + s + k][j + k] == '/') square = false;
          }
          if (square) {
            return make_pair(s, make_pair(i, j));
          }
        }
      }
    }
    return make_pair(0, make_pair(0, 0));
  };

  while (true) {
    // printBoard();

    auto square = findSquare();

    int s = square.first;
    int i = square.second.first;
    int j = square.second.second;

    if (s == 0) break;
    
    // printf("found square s = %d, (%d, %d)\n", s, i, j);

    swap(A[i][j + s-1], A[i][j + s]);
    swap(A[i + 2*s - 1][j + s-1], A[i + 2*s - 1][j + s]);
  }

  puts("POSSIBLE");
  printBoard();
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}