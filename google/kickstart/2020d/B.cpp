#include <bits/stdc++.h>
using namespace std;

int n, a[10100];

void solve() {
  scanf("%d", &n);
  int ans = 0;
  int dir = 0, cot = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    int cdir = i == 0 ? 0 : a[i] > a[i-1] ? 1 : a[i] < a[i-1] ? -1 : 0;
    if (cdir == 0) continue;
    if (cdir == dir) {
      cot++;
    } else {
      ans += (cot - 1) / 4;
      cot = 2;
    }
    dir = cdir;
  }
  ans += (cot - 1) / 4;
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