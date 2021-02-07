#include <bits/stdc++.h>
using namespace std;

/** Tarjan's Directed Strongly Connected Component **/
/* complexity : O(|V| + |E|) */
void directedSCCDFS(int u, vector<int> *AdjList, int *dfs_low, int *dfs_num, int *visited, vector<vector<int>> &SCCList, vector<int> &s)
{
  static int dfsNumberCounter;
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  s.push_back(u);
  visited[u] = 1;
  for (int j = 0; j < (int)AdjList[u].size(); ++j)
  {
    int v = AdjList[u][j];
    if (dfs_num[v] == -1)
    {
      directedSCCDFS(v, AdjList, dfs_low, dfs_num, visited, SCCList, s);
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
vector<vector<int>> directedSCC(int n, vector<int> *AdjList)
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
      directedSCCDFS(i, AdjList, dfs_low, dfs_num, visited, SCCList, s);
    }
  }
  return SCCList;
}

#define MAXN 1000005

int n, m;
vector<int> adj[MAXN];
int idx[MAXN];
int leaf[MAXN], root[MAXN];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--; y--;
    adj[x].push_back(y);
  }
  auto scc = directedSCC(n, adj);
  // if (scc.size() == 1) {
  //   puts("0");
  //   return 0;
  // }
  for (int i = 0; i < scc.size(); ++i) {
    for (int v : scc[i]) {
      idx[v] = i;
    }
  }
  for (int i = 0; i < scc.size(); ++i) {
    leaf[i] = 1;
    root[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int v : adj[i]) {
      if (idx[i] != idx[v]) {
        leaf[idx[i]] = 0;
        root[idx[v]] = 0;
      }
    }
  }
  vector<int> roots, leafs;
  for (int i = 0; i < scc.size(); ++i) {
    if (root[i]) {
      // assert(!leaf[i]);
      roots.push_back(i);
    }
    if (leaf[i]) {
      // assert(!root[i]);
      leafs.push_back(i);
    }
  }
  assert(!roots.empty());
  assert(!leafs.empty());

  vector<pair<int,int>> ans;
  for (int i : leafs) {
    if (i != roots[0]) {
      ans.emplace_back(scc[i][0], scc[roots[0]][0]);
    }
  }
  for (int i = 1; i < roots.size(); ++i) {
    ans.emplace_back(scc[roots[0]][0], scc[roots[i]][0]);
  }

  printf("%d\n", (int)ans.size());
  for (auto p : ans) {
    printf("%d %d\n", p.first+1, p.second+1);
  }
}