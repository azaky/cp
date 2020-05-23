#include <bits/stdc++.h>
using namespace std;

int main() {
  int ntc, n;
  ntc = 100;
  printf("%d\n", ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    n = itc <= 5 ? 100000 : 1000;
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
      printf("%d", rand() % 201 - 100);
      putchar(i == n - 1 ? '\n' : ' ');
    }
  }
}