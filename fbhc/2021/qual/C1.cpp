#include <bits/stdc++.h>
using namespace std;

int n, c[55];
vector<int> adj[55];

int dfs(int v, int p) {
  int s = c[v];
  int best = 0;
  for (int x : adj[v]) {
    if (x == p) continue;
    best = max(best, dfs(x, v));
  }
  return s + best;
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
  }
  for (int i = 1; i <= n; ++i) {
    adj[i].clear();
  }
  for (int i = 0; i < n-1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> p;
  for (int c : adj[1]) {
    p.push_back(dfs(c, 1));
  }
  p.push_back(0);
  p.push_back(0);
  sort(p.rbegin(), p.rend());
  printf("%d\n", c[1] + p[0] + p[1]);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}