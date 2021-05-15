#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i;
  }
  for (int i = 1; i < 100; ++i) {
    printf("M %d 100\n", i);
    fflush(stdout);
    int m;
    scanf("%d", &m);
    if (i != m) {
      swap(a[i-1], a[m-1]);
      printf("S %d %d\n", i, m);
      fflush(stdout);
      int c;
      scanf("%d", &c);
    }
  }
  puts("D");
  fflush(stdout);
  int res;
  scanf("%d", &res);
  assert(res == 1);
}

int main() {
  int ntc, n;
  scanf("%d%d", &ntc, &n);
  for (int itc = 1; itc <= ntc; ++itc) {
    solve(n);
  }
}