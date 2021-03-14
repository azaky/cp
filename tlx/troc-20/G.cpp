#include <bits/stdc++.h>
using namespace std;

int n;
#define MOD 998244353LL

#define MAXN 100100

long long f[MAXN];

long long pmod(long long a, long long b) {
  if (b == 0) return 1;
  if (b & 1) return (a * pmod(a, b-1)) % MOD;
  return pmod((a * a) % MOD, b / 2);
}

long long inv(long long a) {
  return pmod(a, MOD-2);
}

int main() {
  scanf("%d", &n);

  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
  // https://oeis.org/A206603
  // a(n) = Sum_{k=0..n} C(n,floor(k/2)) * (k-n/2).
  // a(n) is odd iff n = 2^m and m > 0.
  long long a = 0;

  for (int k = 0; k <= n; ++k) {
    // C[n][k/2];
    long long c = f[n];
    c *= inv(f[k/2]);
    c %= MOD;
    c *= inv(f[n - k/2]);
    c %= MOD;
    long long t = (k - inv(2) * n);
    t %= MOD;
    t += MOD;
    t %= MOD;
    c *= t;
    c %= MOD;
    a += c;
    a %= MOD;
  }

  // printf("%lld\n", a);

  a *= inv(pmod(2, n));
  a %= MOD;

  printf("%lld\n", a);

  return 0;
}