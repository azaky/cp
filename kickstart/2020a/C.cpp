#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int n, k, a[MAXN+5], d[MAXN+5];

bool valid(int m) {
  int c = 0;
  for (int i = 1; i < n; ++i) {
    c += (d[i] - 1) / m;
  }
  return c <= k;
}

void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int md = 0;
  for (int i = 1; i < n; ++i) {
    d[i] = a[i] - a[i-1];
    if (d[i] > md) {
      md = d[i];
    }
  }
  int l = 1, r = md;
  while (l < r) {
    int m = (l + r) / 2;
    if (valid(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  printf("%d\n", l);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}