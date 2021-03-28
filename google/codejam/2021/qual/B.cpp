#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int n, c[2][2], dp[MAXN][2];
char s[MAXN];

void solve() {
  scanf("%d%d", &c[0][1], &c[1][0]);
  scanf("%s", s);
  n = strlen(s);

  for (int i = 1; i < n; ++i) {
    // C=0, J=1
    // 01 = X, 10 = Y
    dp[i][0] = dp[i][1] = 1000000;
  }

  dp[0][0] = dp[0][1] = 0;
  for (int i = 0; i < 2; ++i) {
    if (s[0] != '?' && "CJ"[i] != s[0]) {
      dp[0][i] = 1000000;
    }
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (s[i] != '?' && "CJ"[j] != s[i]) continue;
      for (int k = 0; k < 2; ++k) {
        dp[i][j] = min(dp[i][j], dp[i-1][k] + c[k][j]);
      }
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < 2; ++j) {
  //     printf("dp[%d][%c] = %d\n", i, "CJ"[j], dp[i][j]);
  //   }
  // }

  printf("%d\n", min(dp[n-1][0], dp[n-1][1]));
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}