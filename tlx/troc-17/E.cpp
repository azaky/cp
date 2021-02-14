#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

long long powmod(long long a, long long b) {
  if (!b) return 1;
  if (b & 1) return (a * powmod(a, b-1)) % MOD;
  return powmod((a * a) % MOD, b >> 1);
}

int n, a[100100], p[32];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  long long ans = 1;
  for (int i = 0; i < 32; ++i) {
    p[i] = n+1;
  }
  for (int m = n; m > 0; --m) {
    vector<int> c;
    for (int i = 0; i < 32; ++i) {
      if (a[m] & (1 << i)) p[i] = m;
      if (p[i] <= n) c.push_back(p[i]);
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    c.push_back(n+1);
    int lastv = 0, last = m;
    for (int x : c) {
      ans *= powmod(lastv, x - last);
      ans %= MOD;
      lastv |= a[x];
      last = x;
    }
  }
  printf("%lld\n", ans);
}