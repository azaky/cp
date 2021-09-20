#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<int> L(n), R(n), A(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &L[i], &R[i], &A[i]);
  }
  vector<int> adj(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x] |= (1 << y);
    adj[y] |= (1 << x);
  }
  vector<long long> dp(1 << n);
  long long ans = 0;
  for (int mask = 1; mask < (1 << n); ++mask) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        sum += A[i];
      }
    }
    if (sum > k) continue;
    if (__builtin_popcount(mask) == 1) {
      dp[mask] = 1;
    } else {
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          int umask = (1 << i) ^ mask;
          if (dp[umask] == 0) continue;
          if (!((L[i] <= (sum - A[i]) && (sum - A[i]) <= R[i]))) continue;
          bool valid = false;
          for (int j = 0; j < n; ++j) {
            if (mask & adj[i] & (1 << j)) {
              valid = true;
              break;
            }
          }
          if (valid) {
            dp[mask] += dp[umask];
          }
        }
      }
    }
    if (sum == k) {
      ans += dp[mask];
    }
  }
  printf("%lld\n", ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}