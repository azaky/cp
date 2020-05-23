#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

double lnf[MAXN+5];

void precompute() {
  lnf[0] = 0;
  for (int i = 1; i <= MAXN; ++i) {
    lnf[i] = lnf[i - 1] + log(i);
  }
}

double calc(int u, int l, int r) {
  double ans = 0;
  for (int i = l; i <= r; ++i) {
    // C(u + i - 3, u - 2, i - 1) / 2 ^ (u + i - 3)
    double ln = lnf[u + i - 3] - lnf[u - 2] - lnf[i - 1] - log(2) * (u + i - 3);
    ans += exp(ln);
  }
  return ans / 2.;
}

double solve() {
  int w, h, l, u, r, d;
  scanf("%d%d%d%d%d%d", &w, &h, &l, &u, &r, &d);
  // special case: blocked
  if ((l == 1 && r == w) || (u == 1 && d == h)) {
    return 0;
  }
  // hole on the right / bottom
  if (r == w) {
    return 1. - calc(l, 1, d);
  }
  if (d == h) {
    return 1. - calc(u, 1, r);
  }
  double ans = 1.;
  if (u > 1) {
    ans -= calc(u, l, r);
  }
  if (l > 1) {
    ans -= calc(l, u, d);
  }
  return ans;
}

int main() {
  precompute();
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: %.17lf\n", itc, solve());
  }
}