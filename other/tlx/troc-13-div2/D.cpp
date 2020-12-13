#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
  DSU(int n): p(vector<int>(n+1)), n(n) {
    for (int i = 1; i <= n; ++i) {
      p[i] = i;
    }
  }

  int findSet(int x) {
    return p[x] == x ? x : p[x] = findSet(p[x]);
  }

  void mergeSet(int x, int y) {
    p[findSet(x)] = findSet(y);
  }

  bool isSameSet(int x, int y) {
    return findSet(x) == findSet(y);
  }

private:
  vector<int> p;
  int n;
};

#define MAXN 300

const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int n, m, a[MAXN+5][MAXN+5], v[MAXN+5][MAXN+5];
vector<pair<int, pair<int, int>>> p;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
      p.push_back(make_pair(a[i][j], make_pair(i, j)));
    }
  }
  sort(p.rbegin(), p.rend());
  DSU dsu((m+1)*(n+1));
  int narea = 0;
  int ans = 1;
  for (int t = 0; t < p.size();) {
    int h = p[t].first;
    int first = t;
    while (t < p.size() && p[t].first == h) {
      narea++;
      int r = p[t].second.first;
      int c = p[t].second.second;
      int idx = r * m + c;
      for (int d = 0; d < 4; ++d) {
        int nr = r + dir[d][0];
        int nc = c + dir[d][1];
        if (nr > n || nr < 1) continue;
        if (nc > m || nc < 1) continue;
        if (!v[nr][nc]) continue;
        int nidx = nr * m + nc;
        int s = dsu.findSet(idx);
        int ns = dsu.findSet(nidx);
        if (s != ns) {
          narea--;
          dsu.mergeSet(idx, nidx);
        }
      }
      v[r][c] = 1;
      t++;
    }
    // printf("h = %d, area = %d\n", h, narea);
    ans = max(ans, narea);
  }
  printf("%d\n", ans);
}