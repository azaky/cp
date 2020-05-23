#include <bits/stdc++.h>
using namespace std;

int n;
long long d, a[1005];

void solve() {
  scanf("%d%lld", &n, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = n-1; i >= 0; --i) {
    d = d / a[i] * a[i];
  }
  printf("%lld\n", d);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}