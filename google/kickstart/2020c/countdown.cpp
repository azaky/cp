#include <bits/stdc++.h>
using namespace std;

int main() {
  int ntc, n, k;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    scanf("%d%d", &n, &k);
    int c = k, ans = 0;
    for (int i = 0; i < n; ++i) {
      int x; scanf("%d", &x);
      if (x == c) {
        c--;
        if (c == 0) {
          c = k;
          ans++;
        }
      } else {
        c = k;
        if (x == k) {
          c--;
        }
      }
    }
    printf("Case #%d: %d\n", itc, ans);
  }
}