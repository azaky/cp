#include <bits/stdc++.h>
using namespace std;

#define MAXN 50
#define MAXP 1500

int n, k, p, dp[MAXN+5][MAXP+5];

void solve() {
  scanf("%d%d%d", &n, &k, &p);
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    int a, s = 0;
    for (int t = 0; t <= p; ++t) {
      dp[i][t] = dp[i - 1][t];
    }
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &a);
      s += a;
      for (int t = j; t <= p; ++t) {
        dp[i][t] = max(dp[i][t], dp[i - 1][t - j] + s);
      }
    }
  }
  printf("%d\n", dp[n][p]);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}