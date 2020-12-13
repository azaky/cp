#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> plli;
typedef pair<int, int> pii;
#define A first
#define B second

#define MAXN 100000

int n, s[2], f[2];
int x[MAXN], y[MAXN], r[MAXN], c[MAXN];
vector<pair<pii, int>> vv[2];

int nnodes;
int inodes[2][MAXN];
pii rnodes[2][MAXN];
int bnodes[2][MAXN];
pii nodes[MAXN << 1];

vector<pii> adj[MAXN << 1];

long long cost[MAXN << 1];
bool visited[MAXN << 1];

int main() {
  scanf("%d%d%d%d%d", &n, &s[0], &s[1], &f[0], &f[1]);
  if (s[1] == f[1]) {
    puts("0");
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d%d", &x[i], &y[i], &r[i], &c[i]);
    vv[0].push_back({ { x[i] - r[i], x[i] + r[i] }, i });
    vv[1].push_back({ { y[i] - r[i], y[i] + r[i] }, i });
  }

  for (int d = 0; d < 2; ++d) {
    sort(vv[d].begin(), vv[d].end());

    auto last = vv[d].front().A;
    int idx = 0;
    for (auto w : vv[d]) {
      if (w.A.A > last.B) {
        idx++;
        last = w.A;
      }
      last.B = max(last.B, w.A.B);
      inodes[d][w.B] = idx;
      rnodes[d][idx] = last;
    }
    for (int i = 0; i <= idx; ++i) {
      // printf("nodes[%d][%d] = (%d, %d)\n", d, i, rnodes[d][i].A, rnodes[d][i].B);
      bnodes[d][i] = nnodes;
      nodes[nnodes++] = { d, i };
    }
  }

  for (int i = 0; i < n; ++i) {
    int n0 = bnodes[0][inodes[0][i]];
    int n1 = bnodes[1][inodes[1][i]];
    adj[n0].emplace_back(n1, c[i]);
    adj[n1].emplace_back(n0, c[i]);
  }

  int si = -1;
  for (int i = 0; i < nnodes; ++i) {
    if (nodes[i].A == 0) continue;
    if (rnodes[1][nodes[i].B].A <= s[1] && s[1] <= rnodes[1][nodes[i].B].B) {
      si = i;
      break;
    }
  }
  if (si == -1) {
    puts("-1");
    return 0;
  }
  // printf("si = %d\n", si);
  // printf("   = (%d, %d)\n", nodes[si].A, nodes[si].B);

  for (int i = 0; i < nnodes; ++i) {
    cost[i] = 1e15;
    visited[i] = false;
  }
  cost[si] = 0;

  auto finish = [&](int v) -> bool {
    int d = nodes[v].A;
    pii rg = rnodes[d][nodes[v].B];
    return (rg.A <= f[d] && f[d] <= rg.B);
  };

  priority_queue < plli, vector<plli>, greater<plli>> pq;
  pq.emplace(0, si);
  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();

    long long costv = top.A;
    int v = top.B;
    if (visited[v]) continue;

    if (finish(v)) {
      printf("%lld\n", costv);
      return 0;
    }

    for (auto ad : adj[v]) {
      int u = ad.A;
      int cu = ad.B;

      if (costv + cu < cost[u]) {
        cost[u] = costv + cu;
        pq.emplace(cost[u], u);
      }
    }
  }

  puts("-1");
}