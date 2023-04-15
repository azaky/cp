#include <bits/stdc++.h>
using namespace std;

constexpr int LIMIT = 1e6;
long long t[LIMIT], u[LIMIT];

void solve(int tc) {
  long long n;
  scanf("%lld", &n);
  // Find i, s.t. u[i] < n && n <= u[i+1]
  // Too lazy for binser lol
  int i = 0;
  for (; i + 1 < LIMIT; i++) {
    if (u[i] < n && n <= u[i + 1]) {
      break;
    }
  }
  n -= u[i];
  int c = (n - 1) / (i + 1);
  printf("Case #%d: %c\n", tc, 'A' + c);
}

int main() {
  t[0] = 0;
  u[0] = 0;
  for (int i = 1; i < LIMIT; i++) {
    t[i] = t[i - 1] + 26;
    u[i] = u[i - 1] + t[i];
  }

  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; itc++) {
    solve(itc);
  }
}