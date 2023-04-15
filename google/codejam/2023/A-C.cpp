#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  int n;
  scanf("%d", &n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  c.resize(unique(c.begin(), c.end()) - c.begin());
  set<int> u(c.begin(), c.end());
  if (u.size() == c.size()) {
    printf("Case #%d:", tc);
    for (int i : c) {
      printf(" %d", i);
    }
    printf("\n");
  }
  else {
    printf("Case #%d: IMPOSSIBLE\n", tc);
  }
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; itc++) {
    solve(itc);
  }
}