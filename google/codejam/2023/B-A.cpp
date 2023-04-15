#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  int n, la, ra, lb, rb;
  scanf("%d", &n);
  vector<long long> a(n);
  vector<long long> s(n + 1);
  s[0] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    s[i + 1] = s[i] + a[i];
  }
  scanf("%d%d%d%d", &la, &ra, &lb, &rb);

  auto check = [&](int alice, int bob) -> long long {
    if (bob < lb || bob > rb || alice == bob) return 1e18;
    if (alice < bob) {
      int mid = (alice + bob) / 2;
      return s[mid];
    }
    else {
      int mid = (alice + bob + 1) / 2;
      return s[n] - s[mid - 1];
    }
  };

  // Brute force Alice.
  long long ans = 0;
  for (int p = la; p <= ra; p++) {
    // Only 4 choices for bob:
    // p-1, p+1, lb, rb.
    long long alice = min({ check(p, p - 1), check(p, p + 1), check(p, lb), check(p, rb) });
    ans = max(ans, alice);
  }
  printf("Case #%d: %lld\n", tc, ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; itc++) {
    solve(itc);
  }
}