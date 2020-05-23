#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
int n, b, a[MAXN+5];

void solve() {
  scanf("%d%d", &n, &b);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    b -= a[i];
    if (b < 0) {
      printf("%d\n", i);
      return;
    }
  }
  printf("%d\n", n);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}