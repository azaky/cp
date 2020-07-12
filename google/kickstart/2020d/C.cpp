#include <bits/stdc++.h>
using namespace std;

#define MAXN 500000
#define MAXP 20

int n, a, b;
int p[MAXN+5][MAXP+1], pa[MAXN+5], pb[MAXN+5];
vector<int> ca[MAXN+5], cb[MAXN+5];
int va[MAXN+5], vb[MAXN+5], ta[MAXN+5], tb[MAXN+5];

int findParent(int v, int x) {
  for (int d = 0; d <= MAXP; ++d) {
    if (x & 1) {
      v = p[v][d];
      if (v == -1) return -1;
    }
    x >>= 1;
  }
  return v;
}

void dfs(int x, vector<int> *c, int *v, int *t) {
  if (v[x]) return;
  v[x] = 1;
  t[x] = 1;
  for (int ch : c[x]) {
    dfs(ch, c, v, t);
    t[x] += t[ch];
  }
}

void solve() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &p[i][0]);
  }
  p[1][0] = -1;
  for (int d = 1; d <= MAXP; ++d) {
    for (int i = 1; i <= n; ++i) {
      p[i][d] = p[max(p[i][d-1], 1)][d-1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    pa[i] = findParent(i, a);
    pb[i] = findParent(i, b);
  }
  for (int i = 1; i <= n; ++i) {
    ca[i].clear();
    cb[i].clear();
    va[i] = vb[i] = 0;
    ta[i] = tb[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (pa[i] != -1) {
      ca[pa[i]].push_back(i);
    }
    if (pb[i] != -1) {
      cb[pb[i]].push_back(i);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!va[i]) dfs(i, ca, va, ta);
    if (!vb[i]) dfs(i, cb, vb, tb);
  }

  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    double pa = (double)ta[i] / n;
    double pb = (double)tb[i] / n;
    ans += pa + pb - pa*pb;
  }
  printf("%.17lf\n", ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}