#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

void solve() {
  int n;
  scanf("%d", &n);
  vector<vector<pair<int,int>>> adj(n+1);
  for (int i = 0; i < n-1; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    adj[x].emplace_back(y, z);
    adj[y].emplace_back(x, z);
  }

  vector<vector<int>> up(n+1), down(n+1);

  function<vector<int>(int, int)> dfs1 = [&](int v, int p) -> vector<int> {
    fflush(stdout);
    vector<int> d(21);
    for (auto c : adj[v]) {
      if (c.first == p) continue;
      int u = c.first, e = c.second;
      vector<int> du = dfs1(u, v);
      for (int i = 1; i <= 20; ++i) {
        d[min(e, i)] += du[i];
      }
    }
    d[20]++;
    down[v] = d;
    return d;
  };

  dfs1(1, -1);

  function<vector<int>(int, int, int)> dfs2 = [&](int v, int p, int pe) -> vector<int> {
    vector<int> uv(21);
    for (int i = 1; i <= 20; ++i) {
      uv[min(pe, i)] += up[v][i];
    }
    uv[20]++;
    for (auto c : adj[v]) {
      if (c.first == p) continue;
      int u = c.first, e = c.second;
      for (int i = 1; i <= 20; ++i) {
        uv[min(e, i)] += down[u][i];
      }
    }
    for (auto c : adj[v]) {
      if (c.first == p) continue;
      int u = c.first, e = c.second;
      up[u] = uv;
      for (int i = 1; i <= 20; ++i) {
        up[u][min(e, i)] -= down[u][i];
      }
      dfs2(u, v, e);
    }
    return up[v];
  };

  up[1] = vector<int>(21, 0);
  dfs2(1, -1, 20);

  long long total = 0;

  function<void(int, int)> dfs3 = [&](int v, int p) -> void {
    for (int i = 1; i <= 20; ++i) {
      total += (long long)i * down[v][i];
    }
    total -= 20;
    for (auto c : adj[v]) {
      if (c.first == p) continue;
      int u = c.first, e = c.second;
      for (int i = 1; i <= 20; ++i) {
        total += min(i, e) * up[u][i];
      }
      dfs3(u, v);
    }
  };
  dfs3(1, -1);
  assert(total % 2 == 0);
  total /= 2;

  long long ans = 1;
  function<void(int, int)> dfs4 = [&](int v, int p) -> void {
    for (auto c : adj[v]) {
      if (c.first == p) continue;
      int u = c.first, e = c.second;
      long long ansu = 0;
      for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= 20; ++j) {
          ansu += (long long)up[u][i] * (long long) down[u][j] * min(min(i, j), e);
        }
      }
      // printf("down[%d] =", u);
      // for (int i = 1; i <= 20; ++i) {
      //   if (down[u][i]) {
      //     printf(" %d=%d", i, down[u][i]);
      //   }
      // }
      // puts("");
      // printf("up[%d] =", u);
      // for (int i = 1; i <= 20; ++i) {
      //   if (up[u][i]) {
      //     printf(" %d=%d", i, up[u][i]);
      //   }
      // }
      // puts("");
      // printf("S[%d] = %lld\n", u, total - ansu);
      ans *= (total - ansu + MOD) % MOD;
      ans %= MOD;

      dfs4(u, v);
    }
  };

  dfs4(1, -1);
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