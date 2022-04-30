#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < 2*n+1; ++i) {
    for (int j = 0; j < 2*m+1; ++j) {
      // top-left corner
      if (i < 2 && j < 2) {
        putchar('.');
      }
      // +
      else if (i % 2 == 0 && j % 2 == 0) {
        putchar('+');
      }
      // .
      else if (i % 2 == 1 && j % 2 == 1) {
        putchar('.');
      }
      // -
      else if (i % 2 == 0) {
        putchar('-');
      }
      // |
      else if (j % 2 == 0) {
        putchar('|');
      }
      else assert(false);
    }
    putchar('\n');
  }
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d:\n", itc);
    solve();
  }
}