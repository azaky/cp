#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  int m, r, n;
  scanf("%d%d%d", &m, &r, &n);
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[i] = { x - r, x + r };
  }
  sort(a.begin(), a.end());
  int last = 0, k = 0, ans = 0;
  while (k < n && last < m) {
    while (k < n && a[k].first <= last) k++;
    k--;
    if (a[k].second <= last) break;
    last = a[k].second;
    ans++;
    k++;
  }
  if (last < m) {
    printf("Case #%d: IMPOSSIBLE\n", tc);
  }
  else {
    printf("Case #%d: %d\n", tc, ans);
  }
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; itc++) {
    solve(itc);
  }
}