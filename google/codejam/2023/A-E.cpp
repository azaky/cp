#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  static char s[1010];
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      s[i] = 0;
    }
    else if (s[i] == 'P') {
      s[i] = 1;
    }
    else {
      s[i] = 2;
    }
  }
  // dp? too overkill, no?
  // dp[k][first][last]
  int dp[n + 1][3][3];
  for (int i = 1; i <= n; i++) {
    for (int f = 0; f < 3; f++) {
      for (int l = 0; l < 3; l++) {
        dp[i][f][l] = 1e9;
      }
    }
  }
  dp[1][0][0] = dp[1][1][1] = dp[1][2][2] = 1;
  dp[1][s[0]][s[0]] = 0;
  for (int k = 2; k <= n; k++) {
    for (int f = 0; f < 3; f++) {
      for (int r = 0; r < 3; r++) {
        if (k == n && f == r) continue;
        for (int l = 0; l < 3; l++) {
          if (l == r) continue;
          int cost = s[k - 1] == r ? 0 : 1;
          dp[k][f][r] = min(dp[k][f][r], dp[k - 1][f][l] + cost);
        }
      }
    }
  }
  int ans = 1e9;
  for (int f = 0; f < 3; f++) {
    for (int l = 0; l < 3; l++) {
      ans = min(ans, dp[n][f][l]);
    }
  }
  printf("Case #%d: %d\n", tc, ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; itc++) {
    solve(itc);
  }
}