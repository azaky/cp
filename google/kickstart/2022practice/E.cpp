#include <bits/stdc++.h>
using namespace std;

constexpr long long MOD = 1e9 + 7;

long long powmod(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1 % mod;
  }
  long long tmp = powmod((a * a) % mod, b / 2, mod);
  if (b % 2) {
    tmp = (tmp * a) % mod;
  }
  return tmp;
}

long long solve(long long a, long long b, long long n, long long k) {
  // number of pairs (i, j) s.t.:
  // 1. 1 <= a, b <= n
  // 2. a != b
  // 3. i^a + j^b == 0 mod k
  vector<long long> cb(k, 0);
  for (int i = 0; i < k; i++) {
    long long cnt = n / k;
    if (i > 0 && i <= (n % k)) {
      cnt++;
    }
    cnt %= MOD;
    int pb = powmod(i, b, k);
    cb[pb] += cnt;
    cb[pb] %= MOD;
  }
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    int pa = powmod(i, a, k);
    int rest = (k - pa) % k;
    long long cnt = n / k;
    if (i > 0 && i <= (n % k)) {
      cnt++;
    }
    cnt %= MOD;
    ans += cnt * cb[rest];
    ans %= MOD;
  }
  // reduce the cases where i == j
  for (int i = 0; i < k; i++) {
    long long cnt = n / k;
    if (i > 0 && i <= (n % k)) {
      cnt++;
    }
    cnt %= MOD;
    int pb = powmod(i, b, k);
    int pa = powmod(i, a, k);
    if ((pa + pb) % k == 0) {
      ans += MOD - cnt;
      ans %= MOD;
    }
  }
  return ans;
}

long long brute(long long a, long long b, long long n, long long k) {
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (i != j && (powmod(i, a, k) + powmod(j, b, k)) % k == 0) {
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  // int N = 100;
  // for (int A = 0; A <= 100; A++) {
  //   for (int B = 0; B <= 100; B++) {
  //     for (int K = 1; K <= 100; K++) {
  //       long long ans = solve(A, B, N, K);
  //       long long expected = brute(A, B, N, K);
  //       if (ans != expected) {
  //         printf("A = %d, B = %d, N = %d, K = %d, expected = %lld, got %lld\n", A, B, N, K, expected, ans);
  //         exit(1);
  //       }
  //     }
  //   }
  // }

  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; itc++) {
    long long a, b, n, k;
    scanf("%lld%lld%lld%lld", &a, &b, &n, &k);
    long long ans = solve(a, b, n, k);
    printf("Case #%d: %lld\n", itc, ans);
  }

  return 0;
}