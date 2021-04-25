#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> &a) {
  int n = a.size(), best = 2;
  vector<bool> q(n);
  q[0] = 1;
  for (int s = 0; s+1 < n; ++s) {
    if (!q[s]) continue;
    int i = s;
    int d = a[i+1] - a[i];
    while (i+1 < n && a[i+1] - a[i] == d) i++;
    // printf("STAGE1: s = %d, i = %d\n", s, i);
    if (i+1 < n) {
      q[i] = q[i+1] = 1;
      // printf("\ts = %d, put %d %d\n", s, i, i+1);
      int old = a[i+1], j = i+1;
      a[i+1] = 2*a[i] - a[i-1];
      while (i+1 < n && a[i+1] - a[i] == d) i++;
      // printf("STAGE2: s = %d, i = %d\n", s, i);
      if (i+1 < n) {
        q[i+1] = 1;
        // printf("\ts = %d, put %d\n", s, i);
      }
      a[j] = old;
    }
    // printf("s = %d, i = %d, len = %d\n", s, i, i-s+1);
    best = max(best, i-s+1);
  }
  return best;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int ans1 = calc(a);
  reverse(a.begin(), a.end());
  int ans2 = calc(a);
  printf("%d\n", max(ans1, ans2));
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}