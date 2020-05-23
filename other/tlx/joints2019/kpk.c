#include <stdio.h>

int t, n;
long long t1, t2, t3;
#define MOD 1000000007
#define MAGIC 125000001

long long power3(int p) {
  long long t = 3, r = 1;
  while (p > 0) {
    if (p & 1) r = (r * t) % MOD;
    p >>= 1;
    t = (t * t) % MOD;
  }
  return r;
}

int main() {
  scanf("%d", &t);
  for (int tc = 1; tc <= t; ++tc) {
    scanf("%d", &n);
    t1 = power3(n);
    t2 = (t1 * 3) % MOD;
    t3 = (t1 * t1) % MOD;
    t3 = ((t3 - 1) * t2) % MOD;
    printf("Kasus #%d: %lld\n", tc, (t3 * MAGIC + t1) % MOD);
  }

  return 0;
}