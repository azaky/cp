#include <bits/stdc++.h>
using namespace std;

int R, C, K;
vector<string> G;
int ans;

void calc() {
  vector<vector<int>> h(R, vector<int>(C));
  for (int c = 0; c < C; ++c) {
    int b = 0;
    for (int r = 0; r < K; ++r) {
      if (G[r][c] == 'X') {
        b++;
      }
    }
    for (int r = K; r < R; ++r) {
      if (G[r][c] == 'X') {
        b++;
      }
      if (b > K || G[r][c] == 'X') {
        h[r-K][c] = 1;
      } else {
        h[r-K][c] = 0;
      }
    }
    for (int r = R-K; r < R; ++r) {
      if (b > K) {
        h[r][c] = 1;
      } else {
        h[r][c] = 0;
      }
    }
  }

  // puts("");
  // for (int r  = 0; r < R; ++r) {
  //   for (int c = 0; c < C; ++c) {
  //     printf("%d ", h[r][c]);
  //   }
  //   printf("\n");
  // }

  for (int m = 0; m < R; ++m) {
    int moves = m;
    for (int i = 0; i < C; ++i) {
      moves += h[m][i];
    }
    ans = min(ans, moves);
  }
}

char buffer[2000200];

void solve() {
  scanf("%d%d%d", &R, &C, &K);
  K--;
  G.clear();
  for (int i = 0; i < R; ++i) {
    scanf("%s", buffer);
    G.push_back(buffer);
  }
  ans = C;
  calc();
  reverse(G.begin(), G.end());
  K = R-K-1;
  calc();
  printf("%d\n", ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}