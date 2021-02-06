#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, vector<int>> adj;
map<int, bool> vi;

#define MAXM 200200

vector<int> V;
map<int, int> Vm;
vector<int> Vadj[MAXM];
int VN;

void dfs0(int v)
{
  if (vi[v])
    return;
  vi[v] = 1;
  int idx = V.size();
  Vm[v] = idx;
  V.push_back(v);
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

/** Tarjan's Directed Strongly Connected Component **/
/* complexity : O(|V| + |E|) */
/* modified to work with undirected graph */
void sccDFS(int u, int *dfs_low, int *dfs_num, int *visited, vector<vector<int>> &SCCList, vector<int> &s, int p = -1)
{
  static int dfsNumberCounter;
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  s.push_back(u);
  visited[u] = 1;
  for (int j = 0; j < (int)Vadj[u].size(); ++j)
  {
    int v = Vadj[u][j];
    if (v == p) continue;
    if (dfs_num[v] == -1)
    {
      sccDFS(v, dfs_low, dfs_num, visited, SCCList, s, u);
    }
    if (visited[v])
    {
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
  }
  if (dfs_low[u] == dfs_num[u])
  {
    vector<int> temp;
    int v = -1;
    while (u != v)
    {
      v = s.back();
      s.pop_back();
      visited[v] = 0;
      temp.push_back(v);
    }
    SCCList.push_back(temp);
  }
}
vector<vector<int>> scc(int n)
{
  int dfs_num[n + 5], dfs_low[n + 5], visited[n + 5];
  vector<vector<int>> SCCList;
  vector<int> s;
  for (int i = 0; i < n; ++i)
  {
    dfs_num[i] = -1;
    dfs_low[i] = visited[i] = 0;
  }
  for (int i = 0; i < n; ++i)
  {
    if (dfs_num[i] == -1)
    {
      sccDFS(i, dfs_low, dfs_num, visited, SCCList, s);
    }
  }
  return SCCList;
}

vector<vector<int>> s;
int sccn;
int sccm[MAXM];
vector<int> tree[MAXM];

int dp[MAXM][2], vdp[MAXM][2], pdp[MAXM][2];

int c[MAXM], vis[MAXM];

void dfs01(int v, int x, int p, int vs) {
  if (vis[v]) return;
  if (sccm[v] != vs) return;
  vis[v] = 1;
  c[v] = x;
  for (int u : Vadj[v]) {
    if (u == p) continue;
    dfs01(u, 1-x, v, vs);
  }
}

// v is not SCC index! v is node index
int calc(int v, int x, int p = -1) {
  int vs = sccm[v];

  if (vdp[vs][x]){
    // make sure there's no cycle
    assert(pdp[vs][x] == 0);
    return dp[vs][x];
  }
  pdp[vs][x] = 1;
  vdp[vs][x] = 1;

  for (int i : s[vs]) vis[i] = 0;
  dfs01(v, x, -1, vs);

  dp[vs][x] = 0;

  for (int i : s[vs]) {
    if (c[i]) dp[vs][x]++;
    for (int u : Vadj[i]) {
      int us = sccm[u];
      if (us == vs || us == p) continue;

      if (c[i] == 0) {
        // this is free
        dp[vs][x] += max(calc(u, 0, vs), calc(u, 1, vs));
      } else {
        // must be 0
        dp[vs][x] += calc(u, 0, vs);
      }
    }
  }

  pdp[vs][x] = 0;
  return dp[vs][x];
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
    dfs0(ii);
    VN = V.size();

    // SCC
    s = scc(VN);
    sccn = s.size();
    // printf("SCC START\n");
    for (int i = 0; i < sccn; ++i) {
      // printf("%d:", i);
      for (int v : s[i]) {
        sccm[v] = i;
        // printf(" %d", V[v]);
      }
      // printf("\n");
    }
    // printf("SCC END\n");

    // dp on tree
    for (int i = 0; i < sccn; ++i) {
      dp[i][0] = dp[i][1] = 0;
      vdp[i][0] = vdp[i][1] = 0;
      pdp[i][0] = pdp[i][1] = 0;
    }

    int addum = max(calc(0, 0), calc(0, 1));
    ans += addum;
    // printf("dp += %d\n", addum);

    // cleanup
    for (int i = 0; i < VN; ++i)
    {
      Vadj[i].clear();
      tree[i].clear();
    }
  }

  printf("%d\n", ans);
}