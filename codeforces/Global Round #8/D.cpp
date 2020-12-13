#include <bits/stdc++.h>
using namespace std;

#define MAXN 200200

int n, a[MAXN], b[22][MAXN];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    for (int j = 0; j < 20; ++j) {
      if (a[i] & (1 << j)) b[j][i] = 1;
    }
  }
  for (int i = 0; i < 20; ++i) sort(b[i], b[i]+n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    long long x = 0;
    for (int j = 0; j < 20; ++j) x |= b[j][i] << j;
    ans += x*x;
  }
  printf("%lld\n", ans);
}