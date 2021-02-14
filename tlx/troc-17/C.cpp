#include <bits/stdc++.h>
using namespace std;

int n, a[200200];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  if (n > 2000) {
    puts("0");
    return 0;
  }
  long long p = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      p *= a[i] ^ a[j];
      p %= 998244353;
    }
  }
  printf("%lld\n", p);
}