#include <bits/stdc++.h>
using namespace std;

int n, a[200200];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int ans = 0, cmax = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] > cmax && (i == n-1 || a[i] > a[i+1])) ans++;
    cmax = max(cmax, a[i]);
  }
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