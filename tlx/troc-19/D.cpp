#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> cached;

int q(int l, int r) {
  if (l == r) return 1;
  if (l > r) {
    assert(l == r+1);
    return 0;
  }
  if (cached.find({l, r}) != cached.end()) {
    return cached[{l, r}];
  }
  printf("? %d %d\n", l, r);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  cached[{l, r}] = x;
  return x;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (q(1, i - 1) == q(1, i) - 1 && q(i + 1, n) == q(i, n) - 1) {
      ans.push_back(i);
    }
  }
  printf("! %d", ans.size());
  for (int x : ans) printf(" %d", x);
  putchar('\n');
}