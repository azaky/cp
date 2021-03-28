#include <bits/stdc++.h>
using namespace std;

int n, a[111];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int cost = 0;
  for (int i = 0; i+1 < n; ++i) {
    int j = min_element(a+i, a+n) - a;
    cost += j-i+1;
    reverse(a+i, a+j+1);
  }
  printf("%d\n", cost);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}