#include <bits/stdc++.h>
using namespace std;

int a[111];

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  for (int i = 1; i + 1 < n; ++i) {
    if (a[i] > a[i-1] && a[i] > a[i+1]) {
      ans++;
    }
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