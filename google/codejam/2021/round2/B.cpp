#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001
int a[MAXN];

int calc(int n) {
  if (a[n] != -1) return a[n];

  a[n] = 1;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i) continue;
    if (i < n-i) {
      a[n] = max(a[n], calc(n/i-1)+1);
    }
    if (n/i < n-n/i) {
      a[n] = max(a[n], calc(i-1)+1);
    }
  }

  return a[n];
}

void solve() {
  int n;
  scanf("%d", &n);

  int ans = 1;
  for (int i = 3; i * i <= n; ++i) {
    if (n % i) continue;
    ans = max(ans, calc(n / i - 1) + 1);
    ans = max(ans, calc(i - 1) + 1);
  }

  printf("%d\n", ans);
}

int main() {
  fill(a, a+MAXN, -1);

  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}