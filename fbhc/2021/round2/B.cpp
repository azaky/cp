#include <bits/stdc++.h>
using namespace std;

/** Lowest Common Ancestor **/
/* complexity : LCApre : O(N log N), LCAquery : O(log N) */
/* legend:
 * N : number of vertices. WARNING: zero based
 * T : direct parent. T[v] is parent of v
 * L : L[v] is the level of v. zero/one based is okay
 * P : dp table of size [MAXN][LOGMAXN]. P[v][i] is the 2^i-th parent of v
 */
int N;
int T[800800], L[800800];
int P[800800][30];
void LCApre() {
  int i, j;

  //we initialize every element in P with -1
  for (i = 0; i < N; i++)
    for (j = 0; 1 << j < N; j++)
      P[i][j] = -1;

  //the first ancestor of every node i is T[i]
  for (i = 0; i < N; i++)
    P[i][0] = T[i];

  //bottom up dynamic programing
  for (j = 1; 1 << j < N; j++)
    for (i = 0; i < N; i++)
      if (P[i][j - 1] != -1)
        P[i][j] = P[P[i][j - 1]][j - 1];
}
int LCAquery(int p, int q) {
  int log, i;

  //if p is situated on a higher level than q then we swap them
  if (L[p] < L[q]) swap(p, q);

  //we compute the value of [log(L[p)]
  for (log = 1; 1 << log <= L[p]; log++);
  log--;

  //we find the ancestor of node p situated on the same level
  //with q using the values in P
  for (i = log; i >= 0; i--)
    if (L[p] - (1 << i) >= L[q])
      p = P[p][i];

  if (p == q) return p;

  //we compute LCA(p, q) using the values in P
  for (i = log; i >= 0; i--)
    if (P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q = P[q][i];

  return T[p];
}

vector<vector<int>> adj;
vector<int> f;
vector<vector<int>> fi;
vector<int> val;
int ans;

void base_dfs(int v, int p, int depth) {
  T[v] = p;
  L[v] = depth;
  for (int c : adj[v]) {
    if (c != p) {
      base_dfs(c, v, depth+1);
    }
  }
}

int dfs(int v) {
  int total = 0;
  for (int c : adj[v]) {
    if (T[v] == c) continue;
    int vc = dfs(c);
    if (vc == 0) {
      ans++;
    }
    total += vc;
  }
  total += val[v];
  // printf("dfs(%d) = %d\n", v, total);
  assert(total >= 0);
  return total;
}

void solve() {
  scanf("%d", &N);

  adj.clear();
  adj.resize(N);
  f.resize(N);
  fi.clear();
  fi.resize(N);
  val.clear();
  val.resize(N);
  ans = 0;

  for (int i = 0; i < N-1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 0; i < N; ++i) {
    scanf("%d", &f[i]);
    f[i]--;
    fi[f[i]].push_back(i);
  }

  base_dfs(0, -1, 0);
  LCApre();

  for (int c = 0; c < N; ++c) {
    if (fi[c].size() <= 1) continue;
    int lca = fi[c].front();
    for (int x : fi[c]) {
      lca = LCAquery(lca, x);
    }
    int nc = fi[c].size();
    if (f[lca] == c) {
      nc--;
    }
    val[lca] -= nc;
    for (int x : fi[c]) {
      if (x != lca) {
        val[x]++;
      }
    }
  }
  // for (int i = 0; i < N; ++i) {
  //   printf("%d ", val[i]);
  // }
  // printf("\n");

  assert(dfs(0) == 0);
  printf("%d\n", ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}