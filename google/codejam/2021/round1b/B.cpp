#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  int d = __gcd(a, b);
  int u[n+1];
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &u[i]);
    if (u[i]) {
      d = __gcd(d, i);
    }
  }
  for (int s = n+1; s <= n + 2000; ++s) {
    static int c[2200];
    for (int i = 1; i <= s; ++i) {
      c[i] = 0;
    }
    c[s] = 1;
    for (int j = s; j >= 1; --j) {
      int e = c[j];
      if (j <= n) {
        e = max(0, e - u[j]);
      }
      for (int x : {j-a, j-b}) {
        if (x < 1) continue;
        c[x] += e;
        c[x] = min(c[x], 2000);
      }
    }
    bool valid = true;
    for (int i = 1; i <= n; ++i) {
      if (c[i] < u[i]) valid = false;
    }
    if (valid) {
      printf("%d\n", s);
      return;
    }
  }
  puts("IMPOSSIBLE");
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}