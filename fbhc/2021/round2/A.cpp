#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  multiset<int> s[2], t[2];
  int x = 0, y = 1;
  for (int i = 0; i < m; ++i) {
    int a;
    scanf("%d", &a);
    s[x].insert(a);
  }
  int ans = 0;

  // printf("\ns:");
  // for (auto w : s[x]) printf(" %d", w);
  // printf("\n");

  for (int i = 0; i < n; ++i) {
    assert(s[x].size() + t[x].size() == m);

    s[y].clear(); t[y].clear();
    vector<int> a(m), v(m, 0);
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[j]);
    }
    // first pass: t
    for (int j = 0; j < m; ++j) {
      if (v[j]) continue;
      auto it = t[x].find(a[j]);
      if (it != t[x].end()) {
        v[j] = 1;
        t[x].erase(it);
        t[y].insert(a[j]);
      }
    }
    // second pass: s
    for (int j = 0; j < m; ++j) {
      if (v[j]) continue;
      auto it = s[x].find(a[j]);
      if (it != s[x].end()) {
        v[j] = 1;
        s[x].erase(it);
        s[y].insert(a[j]);
      }
    }
    // final pass: the rest
    ans += t[x].size();
    for (int j = 0; j < m; ++j) {
      if (!v[j]) {
        t[y].insert(a[j]);
      }
    }

    // printf("s:");
    // for (auto w : s[y]) printf(" %d", w);
    // printf(" | t:");
    // for (auto w : t[y]) printf(" %d", w);
    // printf("\n");

    swap(x, y);
  }

  assert(s[x].size() + t[x].size() == m);
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