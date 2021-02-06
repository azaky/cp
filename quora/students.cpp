#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, vector<int>> adj;
map<int, bool> vi;

#define MAXM 200200

vector<int> V;
vector<int> Vdeg;
map<int, int> Vm;
vector<int> Vadj[MAXM];
int VN, Vvis[MAXM], cc[MAXM];

void dfs0(int v)
{
  if (vi[v])
    return;
  vi[v] = 1;
  int idx = V.size();
  Vm[v] = idx;
  V.push_back(v);
  Vdeg.push_back(adj[v].size());
  for (int a : adj[v])
  {
    dfs0(a);
  }
  // second iteration to fill in Vm
  // all adjacent nodes must already be visited, so it must be present in Vm
  for (int a : adj[v])
  {
    Vadj[idx].push_back(Vm[a]);
  }
}

int c[2];

void dfs01(int v, int x) {
  if (Vvis[v]) return;
  Vvis[v] = 1;
  c[x]++;
  for (int u : Vadj[v]) {
    dfs01(u, 1-x);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--; y1--; x2--; y2--;
    int a1 = x1 * n + y1;
    int a2 = x2 * n + y2;
    adj[a1].push_back(a2);
    adj[a2].push_back(a1);
  }

  int N = n*n;
  int ans = 0;
  for (int ii = 0; ii < N; ++ii) {
    if (adj.find(ii) == adj.end()) {
      ans++;
      continue;
    }
    if (vi[ii]) continue;

    // we shall now work with "smaller" set

    // First, list all participating nodes.
    V.clear();
    Vm.clear();
    Vdeg.clear();
    dfs0(ii);
    VN = V.size();

    // if (VN == 2) {
    //   ans++;
    //   continue;
    // }

    // conjecture: a leaf can always be set to 1
    // bfs all the way up
    queue<pair<int, int>> q;
    for (int i = 0; i < VN; ++i)
    {
      Vvis[i] = 0;
      cc[i] = -1;
    }
    for (int i = 0; i < VN; ++i) {
      if (Vdeg[i] == 1) {
        q.emplace(i, 1);
        Vvis[i] = 1;
      }
    }
    // for (int i = 0; i < VN; ++i) {
    //   printf("V[%d] = %d\n", i, V[i]);
    // }
    while (!q.empty()) {
      auto top = q.front(); q.pop();
      int v = top.first;
      int x = top.second;
      // printf("in queue: (%d, %d)\n", v, x);
      // if (Vvis[v]) continue;
      if (x) {
        // check neighbor first
        bool valid = true;
        for (int u : Vadj[v]) {
          if (cc[u] == 1) {
            valid = false;
            break;
          }
        }
        // printf("check %d: %d\n", v, valid);
        if (!valid) {
          x = 0;
          cc[v] = 0;
        } else {
          ans++;
          cc[v] = 1;
        }
      } else {
        cc[v] = 0;
      }
      for (int u : Vadj[v]) {
        if (Vvis[u]) continue;
        Vdeg[u]--;
        // printf("adj: %d, deg = %d\n", u, Vdeg[u]);
        // if x == 0, u is free. only add when it is leaf
        if (x == 0) {
          if (Vdeg[u] <= 1 && !Vvis[u])
          {
            // printf("added: (%d, %d)\n", u, 1);
            Vvis[u] = 1;
            q.emplace(u, 1);
          }
        } else if (!Vvis[u])
        {
          // printf("added: (%d, %d)\n", u, 0);
          Vvis[u] = 1;
          q.emplace(u, 0);
        }
      }
    }
    // greedily fill the rest
    for (int i = 0; i < VN; ++i) {
      if (!Vvis[i]) {
        c[0] = c[1] = 0;
        dfs01(i, 0);
        ans += max(c[0], c[1]);
      }
    }
    // printf("ans = %d\n", ans);
  }

  printf("%d\n", ans);
}