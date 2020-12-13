#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int n, k, a[2002];

int main() {
  scanf("%d%d", &n, &k);
  memset(a, -1, sizeof(a));
  for (int i = 0; i < k; ++i) {
    int t, x;
    scanf("%d%d", &t, &x);
    a[x] = t;
  }
  long long ans = 1;
  for (int i = n; i > 0; --i) {
    if (a[i] == -1) {
      ans *= i;
      ans %= MOD;
    }
  }
  printf("%lld\n", ans);
}