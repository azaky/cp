#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int findSet(int x, vector<int> &p) {
  if (p[x] == x) return x;
  return p[x] = findSet(p[x], p);
}

vector<int> pl(2000001), pr(2000001);

void solve(int itc) {
  int n, m;
  scanf("%d%d", &n, &m);

  fprintf(stderr, "case #%d: n = %d, m = %d\n", itc, n, m);

  long long S = (long long)n * (n - 1) / 2;
  long long ans = 1;

  for (int i = 1; i <= n; ++i) {
    pl[i] = i;
    pr[i] = i;
  }

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    x = findSet(x, pr);
    y = findSet(y, pr);
    int tmpx = x;
    int s = y - findSet(x, pl) + 1;
    S += (long long)s * (s - 1) / 2;
    while (x != y) {
      s = x - findSet(x, pl) + 1;
      S -= (long long)s * (s - 1) / 2;
      x = findSet(x+1, pr);
    }
    s = x - findSet(x, pl) + 1;
    S -= (long long)s * (s - 1) / 2;
    ans *= (S % MOD);
    ans %= MOD;

    x = tmpx;
    while (x != y) {
      int xl = findSet(x, pl);
      int xr = findSet(x, pr);
      int nx = xr + 1;
      int nxl = findSet(nx, pl);
      assert(nxl == nx);
      int nxr = findSet(nx, pr);
      pl[nxl] = xl;
      pr[xr] = nxr;
      x = nxr;
    }
  }

  printf("%lld\n", ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve(itc);
  }
}