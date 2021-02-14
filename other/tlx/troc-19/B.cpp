#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, ans;
  scanf("%d%d", &n, &m);
  ans = 1;
  for (int i = 1; i < n*m; ++i) {
    ans = (ans << 1) % 998244353;
  }
  printf("%d\n", ans);
}