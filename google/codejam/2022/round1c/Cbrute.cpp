#include <bits/stdc++.h>
using namespace std;

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
public:
  dsu() : _n(0) {}
  dsu(int n) : _n(n), parent_or_size(n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
      std::remove_if(result.begin(), result.end(),
        [&](const std::vector<int>& v) { return v.empty(); }),
      result.end());
    return result;
  }

private:
  int _n;
  // root node: -1 * component size
  // otherwise: parent
  std::vector<int> parent_or_size;
};

void solve() {
  int m, k;
  scanf("%d%d", &m, &k);
  vector<int> adj;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < i; ++j) {
      adj.push_back(adj.size());
    }
  }
  long long total = 0, totalk = 0;
  do {
    int c = 0;
    vector<vector<int>> mat(m, vector<int>(m, -1));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < i; ++j) {
        int e = adj[c++];
        mat[i][j] = mat[j][i] = e;
      }
    }
    dsu s(m);
    for (int i = 0; i < m; ++i) {
      int best = -1;
      for (int j = 0; j < m; ++j) {
        if (best == -1 || mat[i][j] > mat[i][best]) {
          best = j;
        }
      }
      s.merge(i, best);
    }
    if (s.groups().size() == k) {
      totalk++;
    }
    total++;
  } while (next_permutation(adj.begin(), adj.end()));

  long long d = __gcd(total, totalk);
  total /= d;
  totalk /= d;
  printf("%lld/%lld\n", totalk, total);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}