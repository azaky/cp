#include <bits/stdc++.h>
using namespace std;

#define OFFSET 10000000
#define MAXN 100100

int a[MAXN], s[MAXN], c[OFFSET + OFFSET + 2];

int main() {
  int ntc, n;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    scanf("%d", &n);
    long long ans = 0;
    c[OFFSET] = 1;
    int mins = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      s[i] = s[i - 1] + a[i];
      int limit = s[i] - mins;
      for (int j = 0; j * j <= limit; j++) {
        ans += c[s[i] - j * j + OFFSET];
      }
      c[s[i] + OFFSET]++;
      if (s[i] < mins) {
        mins = s[i];
      }
    }
    for (int i = 0; i <= n; ++i) {
      c[s[i] + OFFSET] = 0;
    }
    printf("Case #%d: %lld\n", itc, ans);
  }
}