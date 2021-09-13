#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int ans[55][55];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int shortestPath(int sr, int sc, int tr, int tc) {
  int dis[55][55];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dis[i][j] = 1000000000;
    }
  }
  dis[sr][sc] = ans[sr][sc];
  priority_queue<pair<int,pair<int,int>>> q;
  q.emplace(-ans[sr][sc], make_pair(sr, sc));
  while (!q.empty()) {
    auto f = q.top(); q.pop();
    int r = f.second.first, c = f.second.second;
    int d = -f.first;
    if (dis[r][c] != d) {
      assert(dis[r][c] < d);
      continue;
    }
    for (int dir = 0; dir < 4; ++dir) {
      int nr = r + dx[dir];
      int nc = c + dy[dir];
      if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
      int nd = d + ans[nr][nc];
      if (nd < dis[nr][nc]) {
        dis[nr][nc] = nd;
        q.emplace(-nd, make_pair(nr, nc));
      }
    }
  }
  return dis[tr][tc];
}

void solve() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  if (a < n + m - 1 || b < n + m - 1) {
    puts("Impossible");
    return;
  }
  puts("Possible");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == n-1 || j == 0 || j == m-1) {
        ans[i][j] = 1;
      } else {
        ans[i][j] = 1000;
      }
    }
  }
  ans[0][0] = a - m - n + 2;
  ans[0][m-1] = b - m - n + 2;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j) printf(" ");
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }

  assert(shortestPath(0, 0, n-1, m-1) == a);
  assert(shortestPath(0, m-1, n-1, 0) == b);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}