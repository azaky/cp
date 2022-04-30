#include <bits/stdc++.h>
using namespace std;


void solve() {
  int a[4][3];
  int ans[3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      scanf("%d", &a[j][i]);
    }
  }
  int sum = 0;
  for (int i = 0; i < 4; ++i) {
    ans[i] = *min_element(a[i], a[i]+3);
    sum += ans[i];
  }
  int target = 1000000;
  if (sum < target) {
    puts("IMPOSSIBLE");
    return;
  }
  for (int i = 0; i < 4; ++i) {
    int excess = sum - target;
    int reduction = min(excess, ans[i]);
    sum -= reduction;
    ans[i] -= reduction;
  }
  assert(sum == target);
  printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}