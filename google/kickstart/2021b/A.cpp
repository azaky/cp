#include <bits/stdc++.h>
using namespace std;

void solve() {
  static char s[200200];
  int n, p = 1;
  scanf("%d%s", &n, s);
  putchar('1');
  for (char* c = s+1; *c; ++c) {
    if (*c <= *(c-1)) {
      p = 0;
    }
    printf(" %d", ++p);
  }
  putchar('\n');
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}