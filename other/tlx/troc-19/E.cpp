#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define MAXC 1000000

int n, a[MAXN], b[MAXN], c[MAXN], d[MAXN];
vector<pair<pair<int,int>,int>> x[MAXC+1], y[MAXC+1];
long long area[MAXN];
vector<pair<long long,pair<int,int>>> edges;

bool overlap(int _a, int _b, int _c, int _d) {
  if (_b <= _c) return false;
  if (_d <= _a) return false;
  return true;
}

void connect(int i, vector<pair<pair<int,int>,int>> &x, int b, int d) {
  if (x.empty()) return;

  auto l = lower_bound(x.begin(), x.end(), make_pair(make_pair(b, b), 0));
  auto r = lower_bound(x.begin(), x.end(), make_pair(make_pair(d, d), 0));
  if (l != x.begin()) l--;
  if (r != x.end()) r++;
  for (auto it = l; it != r; it++) {
    if (overlap(b, d, it->first.first, it->first.second))
    {
      edges.emplace_back(abs(area[i] - area[it->second]), make_pair(i, it->second));
    }
  }
}

int p[MAXN], num_components = 0;
void dsu_init(int n) {
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
  }
  num_components = n;
}
int dsu_find(int x) {
  if (p[x] == x) return x;
  return p[x] = dsu_find(p[x]);
}
int dsu_merge(int x, int y) {
  int px = dsu_find(x);
  int py = dsu_find(y);
  if (px == py) return num_components;
  p[px] = py;
  return --num_components;
}

int main() {
  scanf("%d", &n);
  if (n == 2) {
    puts("0");
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    x[a[i]].push_back(make_pair(make_pair(b[i], d[i]), i));
    y[b[i]].push_back(make_pair(make_pair(a[i], c[i]), i));
    area[i] = (long long)(c[i] - a[i]) * (long long)(d[i] - b[i]);
  }

  for (int i = 1; i <= MAXC; ++i) {
    sort(x[i].begin(), x[i].end());
    sort(y[i].begin(), y[i].end());
  }

  for (int i = 1; i <= n; ++i) {
    connect(i, x[c[i]], b[i], d[i]);
    connect(i, y[d[i]], a[i], c[i]);
  }

  long long ans = 0;
  sort(edges.begin(), edges.end());

  // for (auto edge : edges) {
  //   printf("%d - %d\n", edge.second.first, edge.second.second);
  // }

  dsu_init(n);

  for (auto edge : edges) {
    // printf("merging %d - %d\n", edge.second.first, edge.second.second);
    if (dsu_find(edge.second.first) == dsu_find(edge.second.second)) continue;
    dsu_merge(edge.second.first, edge.second.second);
    ans += edge.first;
    if (num_components == 2) break;
  }

  if (num_components != 2) {
    puts("-1");
  } else {
    printf("%lld\n", ans);
  }

}
