#include <bits/stdc++.h>
using namespace std;

#define MAXN 111

int n, q;
bool ismin[MAXN];

map<vector<int>, int> cache;

int check_cache(int x, int y, int z) {
  int t[] = { x, y, z };
  sort(t, t + 3);
  if (cache.count({ t[0], t[1], t[2] })) {
    return cache[{t[0], t[1], t[2]}];
  } else {
    return -1;
  }
}

void insert_cache(int x, int y, int z, int m) {
  int t[] = { x, y, z };
  sort(t, t + 3);
  cache[{t[0], t[1], t[2]}] = m;
}

int query(int x, int y, int z) {
  int m = check_cache(x, y, z);
  if (m != -1) {
    return m;
  }

  assert(q--);
  printf("%d %d %d\n", x, y, z);
  fflush(stdout);

  scanf("%d", &m);
  assert(m == x || m == y || m == z);
  insert_cache(x, y, z, m);
  return m;
}

void solve() {
  // reset
  cache.clear();
  fill(ismin+1, ismin+n+1, true);

  // first, find min value
  vector<int> x = {1, 2, 3};
  for (int i = 0; i < n-2; ++i) {
    int m = query(x[0], x[1], x[2]);
    ismin[m] = false;
    x.clear();
    for (int j = 1; j <= n; ++j) {
      if (ismin[j]) x.push_back(j);
    }
  }

  vector<int> mins;
  for (int i = 1; i <= n; ++i) {
    if (ismin[i]) {
      mins.push_back(i);
    }
  }
  assert(mins.size() == 2);
  int imin = mins[0], imax = mins[1];

  // now sort as usual
  vector<int> a;
  for (int i = 1; i <= n; ++i) {
    if (i != imin && i != imax) a.push_back(i);
  }

  stable_sort(a.begin(), a.end(), [&](const int a, const int b) {
    // check if cache exists
    int m = check_cache(a, b, imax);
    if (m != -1) {
      assert(m == a || m == b);
      return m == a;
    }
    m = check_cache(a, b, imax);
    if (m != -1) {
      assert(m == a || m == b);
      return m == b;
    }
    int m = query(imin, a, b);
    assert(m == a || m == b);
    insert_cache(a, b, imax, a + b - m);
    return m == a;
  });

  printf("%d", imin);
  for (int x : a) {
    printf(" %d", x);
  }
  printf(" %d\n", imax);

  fflush(stdout);

  int res;
  scanf("%d", &res);
  assert(res == 1);
}

int main() {
  int ntc;
  scanf("%d%d%d", &ntc, &n, &q);
  q = 170 * ntc;
  for (int itc = 1; itc <= ntc; ++itc) {
    solve();
  }
}