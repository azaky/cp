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

  vector<int> a = {1, 2};
  for (int x = 3; x <= n; ++x) {
    int L = 0, R = a.size();
    while (L < R) {
      if (L+1 == R) {
        if (L == 0) {
          int m = query(a[L], x, a.back());
          if (m == a[L]) {
            R = L;
          } else if (m == x) {
            L = R;
          } else assert(false);
        } else {
          int m = query(a[0], a[L], x);
          if (m == a[L]) {
            L = R;
          } else if (m == x) {
            R = L;
          } else assert(false);
        }
        break;
      }

      int l = L + (R-L-2) / 3;
      int r = L + 2 * ((R-L-2) / 3) + 1;

      // printf("[%d, %d] -> (%d, %d)\n", L, R, l, r);

      assert(0 <= l && l < r && r < a.size());

      int m = query(a[l], a[r], x);
      if (m == a[l]) {
        R = l;
      } else if (m == a[r]) {
        L = r+1;
      } else {
        L = l+1;
        R = r;
      }
    }
    assert(L == R);
    a.insert(a.begin() + L, x);

    // bool first = true;
    // for (int x : a) {
    //   if (!first) putchar(' ');
    //   first = false;
    //   printf("%d", x);
    // }
    // putchar('\n');
  }

  bool first = true;
  for (int x : a) {
    if (!first) putchar(' ');
    first = false;
    printf("%d", x);
  }
  putchar('\n');

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