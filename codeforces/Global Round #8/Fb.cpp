#include <bits/stdc++.h>
using namespace std;

int main() {
  for (int n = 4; n <= 1000; ++n) {
    int b = 1;
    while (b * b <= n) b++;
    b--;

    int m = 0, c = 0;
    for (int i = 2; i < n; ++i) {
      int ni = n - (n + i - 1) / i - (i-1);
      if (ni > m) {
        c = i;
        m = ni;
      }
    }
    int r = n - (n + b - 1) / b - (b - 1);
    if (m != r) {
      printf("n = %d\n\tb = %d: r = %d\n\tb = %d, r = %d\n", n, b, r, c, m);
    }

  }
}