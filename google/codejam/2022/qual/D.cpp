#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n;
long long f[MAXN];
vector<int> adj[MAXN];

pair<long long, long long> dfs(int v) {
  if (adj[v].empty()) {
    return make_pair(f[v], f[v]);
  }
  long long sum = 0, best = -1;
  for (int u : adj[v]) {
    auto p = dfs(u);
    sum += p.first;
    if (best == -1 || p.second < best) {
      best = p.second;
    }
  }
  long long maxf = max(f[v], best);
  return make_pair(sum - best + maxf, maxf);
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    adj[i].clear();
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &f[i]);
  }
  vector<int> roots;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    if (x) {
      adj[x].push_back(i);
    } else {
      roots.push_back(i);
    }
  }
  long long ans = 0;
  for (int root : roots) {
    ans += dfs(root).first;
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