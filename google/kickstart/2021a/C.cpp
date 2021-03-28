#include <bits/stdc++.h>
using namespace std;

#define MAXN 303

int r, c, a[MAXN][MAXN], v[MAXN][MAXN];

const int dd[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    scanf("%d%d", &r, &c);
    priority_queue<pair<int,pair<int,int>>> pq;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        scanf("%d", &a[i][j]);
        v[i][j] = 0;
        pq.push(make_pair(a[i][j], make_pair(i, j)));
      }
    }
    long long ans = 0;
    while (!pq.empty()) {
      auto top = pq.top(); pq.pop();
      int h = top.first;
      int i = top.second.first;
      int j = top.second.second;
      if (v[i][j]) continue;
      // printf("(%d, %d) = %d\n", i, j, h);
      v[i][j] = 1;
      ans += h - a[i][j];
      for (int d = 0; d < 4; ++d) {
        int ni = i + dd[d][0];
        int nj = j + dd[d][1];
        if (ni < 0 || ni == r) continue;
        if (nj < 0 || nj == c) continue;
        int nh = max(h-1, a[ni][nj]);
        pq.push(make_pair(nh, make_pair(ni, nj)));
      }
    }
    printf("Case #%d: %lld\n", itc, ans);
  }
}