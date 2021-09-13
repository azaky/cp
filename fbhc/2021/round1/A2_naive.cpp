#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int n;
char s[800800];

void solve() {
  scanf("%d", &n);
  scanf("%s", s);
  if (n > 500) {
    puts("-1");
    return;
  }
  int ans = 0;
  for (int r = 0; r < n; ++r) {
    int changes = 0;
    for (int l = 0; l <= r; ++l) {
      char last = 'F';
      for (int i = l; i <= r; ++i) {
        if (s[i] == 'F') continue;
        if (last != s[i] && last != 'F') changes++;
        last = s[i];
      }
    }
    changes %= MOD;
    ans += changes;
    ans %= MOD;
  }
  printf("%d\n", ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}