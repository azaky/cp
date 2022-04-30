#include <bits/stdc++.h>
using namespace std;

bool is_squary(const vector<long long> &a) {
  __int128_t A = 0, A2 = 0;
  for (long long x : a) {
    A += x;
    A2 += (__int128_t)x * x;
  }

  return A2 == A * A;
}

vector<long long> solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }

  long long A = 0, A2 = 0;
  for (int x : a) {
    A += x;
    A2 += x * x;
  }

  if (A2 == A * A) {
    return {0};
  }

  // Try k == 1 first.

  // k = 1
  // (A + x)^2 = A2 + x^2
  // A^2 + 2Ax = A2
  // if A = 0:
  //   any if A2 = 0, else nothing
  // else:
  //   x = (A2 - A^2) / 2A

  vector<long long> ans1;
  if (A == 0) {
    if (A2 == 0) {
      ans1 = {0};
    } else {
      ans1 = {};
    }
  } else {
    long long numer = A2 - A * A;
    if (numer % (A * 2) == 0) {
      ans1 = {numer / (A * 2)};
    } else {
      ans1 = {};
    }
  }

  if (k == 1 || !ans1.empty()) {
    if (!ans1.empty()) {
      a.push_back(ans1[0]);
      assert(is_squary(a));
    }
    return ans1;
  }

  // k > 1.
  // A: [-1e6, 1e6]
  // A^2: [-1e12, 1e12]
  // A2: [0, 1e9]
  // Is it always possible using k = 2?
  // (A + x + y)^2 = A2 + x^2 + y^2
  // A^2 + 2xy + 2A(x + y) = A2
  // note that A2 and A^2 parity always the same.
  // xy + A(x + y) = (A2 - A^2) / 2 = K
  // xy + A(x + y) + A^2 = K + A^2
  // (x + A)(y + A) = K + A^2 = 1 (K + A^2)
  // x = K + A^2 - A = (A2 + A^2) / 2 - A
  // y = 1 - A

  long long x = (A2 + A*A) / 2 - A;
  long long y = 1 - A;

  a.push_back(x);
  a.push_back(y);
  assert(is_squary(a));
  return {x, y};
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d:", itc);
    auto ans = solve();
    if (ans.empty()) {
      puts(" IMPOSSIBLE");
    } else {
      for (auto x : ans) {
        printf(" %lld", x);
      }
      putchar('\n');
    }
  }
}