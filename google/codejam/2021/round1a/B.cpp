#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int n;
long long p[MAXN], c[MAXN];

void solve() {
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", &p[i], &c[i]);
    sum += p[i] * c[i];
  }
  for (long long s = sum; s > sum-5000 && s > 0; s--) {
    vector<int> f(n);
    long long t = s, ts = 0;
    bool valid = true;
    for (int i = 0; i < n; ++i) {
      while (t % p[i] == 0) {
        t /= p[i];
        f[i]++;
        ts += p[i];
      }
      valid &= (f[i] <= c[i]);
    }
    if (valid && t == 1 && ts + s == sum) {
      printf("%lld\n", s);
      return;
    }
  }
  printf("0\n");
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}