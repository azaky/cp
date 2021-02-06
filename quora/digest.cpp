#include <bits/stdc++.h>
using namespace std;

#define MAXN 202

int n, m, p, q, c[MAXN], a[MAXN][MAXN], b[MAXN][MAXN], d[MAXN][MAXN];
vector<int> fs[MAXN];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
    b[c[i]][i] = 2;
    d[c[i]][i] = -1;
  }
  scanf("%d%d", &p, &q);
  for (int i = 0; i < p; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x][y] = 3;
  }
  for (int i = 0; i < q; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    fs[y].push_back(x);
    if (b[x][y] == 0) {
      b[x][y] = 1;
    }
    d[x][y] = -1;
    if (a[x][c[y]] == 0) {
      a[x][c[y]] = 2;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j : fs[i]) {
      for (int k : fs[i]) {
        if (j != k && a[j][k] == 0) {
          a[j][k] = 1;
        }
      }
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     printf("a[%d][%d] = %d\n", i, j, a[i][j]);
  //   }
  // }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     printf("b[%d][%d] = %d\n", i, j, b[i][j]);
  //   }
  // }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (d[i][j] == -1) continue;
      for (int k = 1; k <= m; ++k) {
        d[i][j] += a[i][k] * b[k][j];
      }
    }
    vector<pair<int,int>> s;
    for (int j = 1; j <= n; ++j) {
      s.emplace_back(-d[i][j], j);
      // printf("d[%d][%d] = %d\n", i, j, d[i][j]);
    }
    sort(s.begin(), s.end());
    printf("%d %d %d\n", s[0].second, s[1].second, s[2].second);
  }
}