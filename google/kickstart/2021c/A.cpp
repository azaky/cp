#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

long long power(long long a, long long b) {
  if (b == 0) {
    return 1;
  } else if (b & 1) {
    return power(a, b-1) * a % MOD;
  } else {
    long long tmp = power(a, b >> 1);
    return tmp * tmp % MOD;
  }
}

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  static char s[100100], t[100100];
  scanf("%s", s);
  long long ans = 0;
  for (int i = 0; i < (n+1)/2; ++i) {
    ans += power(k, (n+1)/2 - i - 1) * (s[i] - 'a');
    ans %= MOD;
    t[i] = t[n-1-i] = s[i];
  }
  t[n] = 0;
  if (strcmp(t, s) < 0) {
    ans++;
    ans %= MOD;
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