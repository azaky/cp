#include <bits/stdc++.h>
using namespace std;

int n, c, a[111], m[111];

void solve() {
  scanf("%d%d", &n, &c);
  int maxcost = n*(n+1)/2 - 1;
  int mincost = n-1;
  if (c > maxcost || c < mincost) {
    puts("IMPOSSIBLE");
    return;
  }

  // simulate the whole process
  int origc = c;
  c -= n-1;
  for (int i = 0; i+1 < n; ++i) {
    // max cost now = n-i
    int now = n-i-1;
    if (now > c) {
      now = 0;
    }
    m[i] = i + now;
    c -= now;
  }
  assert(c == 0);
  for (int i = 0; i < n; ++i) {
    a[i] = i+1;
  }
  for (int i = n-2; i >= 0; --i) {
    reverse(a+i, a+m[i]+1);
  }
  for (int i = 0; i < n; ++i) {
    if (i) putchar(' ');
    printf("%d", a[i]);
  }
  putchar('\n');

  // validate
  int cost = 0;
  for (int i = 0; i + 1 < n; ++i) {
    int j = min_element(a + i, a + n) - a;
    cost += j - i + 1;
    reverse(a + i, a + j + 1);
  }
  assert(cost == origc);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}