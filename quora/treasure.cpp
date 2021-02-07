#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int n;
char s[MAXN];
int a[MAXN][MAXN], dp[MAXN][MAXN], w[MAXN][MAXN];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    for (int j = 0; j < n; ++j) {
      a[i][j+1] = s[j]-'0';
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == 1 && j == 1) {
        dp[i][j] = a[i][j];
        w[i][j] = 1;
        continue;
      }
      dp[i][j] = 0;
      w[i][j] = 0;
      if (i > 1) {
        if (dp[i-1][j] > dp[i][j]) {
          dp[i][j] = dp[i-1][j];
          w[i][j] = w[i-1][j];
        } else if (dp[i-1][j] == dp[i][j]) {
          w[i][j] += w[i-1][j];
          w[i][j] %= 1000000007;
        }
      }
      if (j > 1) {
        if (dp[i][j-1] > dp[i][j]) {
          dp[i][j] = dp[i][j-1];
          w[i][j] = w[i][j-1];
        } else if (dp[i][j-1] == dp[i][j]) {
          w[i][j] += w[i][j-1];
          w[i][j] %= 1000000007;
        }
      }
      dp[i][j] += a[i][j];
    }
  }
  printf("%d %d\n", dp[n][n], w[n][n]);
}