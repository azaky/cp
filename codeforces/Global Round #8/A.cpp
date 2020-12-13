#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, n;
  scanf("%d%d%d", &a, &b, &n);
  int op = 0;
  while (a <= n && b <= n) {
    if (a < b) {
      a += b;
    } else {
      b += a;
    }
    op++;
  }
  printf("%d\n", op);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    // printf("Case #%d: ", itc);
    solve();
  }
}