#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
int n;
long long d[MAXN+5], s[MAXN+5];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &d[i]);
    s[i] = s[i-1] + d[i];
  }
  for (int t = n; t > 2; --t) {
    if (s[n] % t) continue;
    long long len = s[n] / t;

    vector<int> v(n+1, 0), c(n+1, 0);
    bool valid = false;
    for (int i = 1; i <= n; ++i) {
      long long z;
      if (s[i] >= len) {
        z = s[i] - len;
      } else {
        z = s[n] - (len - s[i]);
      }
      int idx = lower_bound(s, s+n+1, z) - s;
      if (idx > n || s[idx] != z) continue;
      if (idx > i) {
        assert(s[i] < len);
        c[i] = 1;
      } else if (idx == 0) {
        c[i] = 1;
      } else if (c[idx]) {
        c[i] = c[idx] + 1;
      }
      if (c[i] == t) {
        valid = true;
        break;
      }
    }
    if (valid) {
      printf("%d\n", n-t);
      return 0;
    }
  }
  puts("-1");
}