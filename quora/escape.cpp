#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
#define MAXG 10100

int n, m, k;
char buf[MAXN];
bool a[MAXN][MAXN];
int sr, sc, er, ec;
int gr[MAXG], gc[MAXG], gd[MAXG];
int gx[MAXN][MAXN], dd[MAXN][MAXN], v[MAXN][MAXN];

const int diff[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    for (int j = 0; j < m; ++j) {
      if (buf[j] == '#') {
        a[i+1][j+1] = 1;
      } else if (buf[j] == 'S') {
        sr = i+1;
        sc = j+1;
      } else if (buf[j] == 'E') {
        er = i+1;
        ec = j+1;
      }
    }
  }

  memset(gx, -1, sizeof(gx));
  priority_queue<pair<int, pair<int,int>>> pq;
  for (int i = 0; i < k; ++i) {
    scanf("%d%d%d", &gr[i], &gc[i], &gd[i]);
    pq.push(make_pair(gd[i], make_pair(gr[i], gc[i])));
    // gx[gr[i]][gc[i]] = gd[i];
  }

  while (!pq.empty()) {
    auto top = pq.top(); pq.pop();
    int d = top.first;
    int r = top.second.first;
    int c = top.second.second;

    if (gx[r][c] >= d) continue;
    gx[r][c] = d;
    if (d <= 0) continue;
    for (int i = 0; i < 4; ++i) {
      int nr = r + diff[i][0];
      int nc = c + diff[i][1];
      if (nr < 1 || nr > n) continue;
      if (nc < 1 || nc > m) continue;
      if (a[nr][nc]) continue;
      if (gx[nr][nc] >= d-1) continue;
      pq.push(make_pair(d-1, make_pair(nr, nc)));
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     printf("%3d", gx[i][j]);
  //   }
  //   puts("");
  // }

  memset(dd, -1, sizeof(dd));
  queue<pair<int,int>> q;
  q.emplace(sr, sc);
  dd[sr][sc] = 0;
  while (!q.empty()) {
    auto top = q.front(); q.pop();
    int r = top.first;
    int c = top.second;
    if (v[r][c]) continue;
    if (gx[r][c] != -1) continue;
    v[r][c] = 1;
    int d = dd[r][c];
    for (int i = 0; i < 4; ++i) {
      int nr = r + diff[i][0];
      int nc = c + diff[i][1];
      if (nr < 1 || nr > n) continue;
      if (nc < 1 || nc > m) continue;
      if (a[nr][nc]) continue;
      if (gx[nr][nc] != -1) continue;
      if (v[nr][nc]) continue;
      if (dd[nr][nc] == -1) {
        dd[nr][nc] = d+1;
        q.emplace(nr, nc);
      }
    }
  }

  if (dd[er][ec] == -1) {
    puts("IMPOSSIBLE");
  } else {
    printf("%d\n", dd[er][ec]);
  }
}
