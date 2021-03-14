#include <bits/stdc++.h>
using namespace std;

#define MAXN 200200

int n, m, a[MAXN];
vector<pair<int,int>> c[MAXN][3];
map<pair<pair<int,int>,int>,vector<int>> cm;
set<pair<pair<int,int>,pair<int,int>>> cs;

bool cmp(int a, int b, int t) {
  if (t == 1) {
    return a > b;
  }
  if (t == 2) {
    return a < b;
  }
  assert(false);
}

bool icmp(int a, int b, int t) {
  return cmp(a, b, 3 - t);
}

int cmx(int a, int b, int t) {
  if (t == 1) {
    return max(a, b);
  }
  if (t == 2) {
    return min(a, b);
  }
  assert(false);
}

int icmx(int a, int b, int t) {
  return cmx(a, b, 3 - t);
}

void impossible() {
  puts("NO");
  exit(0);
}

int tb[MAXN][3];
int v[MAXN];

void dfs(int x) {
  assert(a[x] != -1);
  if (v[x]) return;
  v[x] = 1;
  for (int t = 1; t <= 2; ++t) {
    for (auto yz : c[x][t]) {
      int y = yz.first;
      int z = yz.second;
      if (a[y] != -1) {
        if (cmx(a[x], a[y], t) != z) {
          impossible();
        }
      } else {
        if (cmp(a[x], z, t)) {
          impossible();
        }
        if (cmp(z, a[x], t)) {
          a[y] = z;
          dfs(y);
        }
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    a[i] = -1;
  }
  for (int i = 0; i < m; ++i) {
    int _t, _x, _y, _z;
    scanf("%d%d%d%d", &_t, &_x, &_y, &_z);
    if (_x > _y) swap(_x, _y);
    if (cs.count(make_pair(make_pair(_x, _y), make_pair(_t, _z)))) continue;
    cs.insert(make_pair(make_pair(_x, _y), make_pair(_t, _z)));
    cm[make_pair(make_pair(_x, _y), _t)].push_back(_z);
    c[_x][_t].push_back(make_pair(_y, _z));
    c[_y][_t].push_back(make_pair(_x, _z));
  }
  // zeroth pass: cm count
  for (auto it : cm) {
    if (it.second.size() > 1) {
      impossible();
    }
  }
  puts("zeroth pass done");
  // first pass: max(a, b) > max(a, c) -> b = max(a, b)
  for (int i = 1; i <= n; ++i) {
    for (int t = 1; t <= 2; ++t) {
      if (c[i][t].empty()) continue;
      sort(c[i][t].begin(), c[i][t].end(), [&](const pair<int,int> &a, const pair<int,int> &b) -> bool {
        return icmp(a.second, b.second, t);
      });
      while (icmp(c[i][t].front().second, c[i][t].back().second, t)) {
        auto xz = c[i][t].back(); c[i][t].pop_back();
        int x = xz.first;
        int z = xz.second;
        if (a[x] != -1 && a[x] != z) {
          impossible();
        }
        a[x] = z;
      }
    }
  }
  puts("first pass done");

  // now, all c[x][t] has same z
  // second pass: dfs for filled values
  for (int i = 1; i <= n; ++i) {
    if (a[i] == -1) continue;
    dfs(i);
  }
  puts("second pass done");

  // now what?
  for (int i = 1; i <= n; ++i) {
    printf("%d ", a[i]);
  }
  puts("");

  puts("YES");

  return 0;
}