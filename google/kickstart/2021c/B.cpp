#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long g;
  scanf("%lld", &g);

  // (k + k + x - 1) * x / 2 = g
  // (2k + x - 1) * x = 2g
  // A * B = 2g, A and B having different parity

  while (g % 2 == 0) g >>= 1;
  int ans = 1;
  long long p = 2;
  while (g > 1) {
    while (p * p <= g && g % p) p++;
    if (g % p == 0) {
      int k = 1;
      while (g % p == 0) {
        k++;
        g /= p;
      }
      ans *= k;
    } else {
      ans *= 2;
      break;
    }
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