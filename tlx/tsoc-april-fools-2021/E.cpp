#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, res;
  scanf("%d", &n);
  char d = 'N';
  for (int r = 1; r <= n; ++r) {
    for (int c = 1; c < n; ++c) {
      if (d == 'S') {
        puts("N -1");
      }
      else {
        puts("N 1");
      }
      fflush(stdout);
      scanf("%d", &res);
      if (res) exit(0);
    }
    printf("%c %d\n", 'E', 1);
    fflush(stdout);
    scanf("%d", &res);
    if (res) exit(0);
    if (d == 'N') {
      d = 'S';
    }
    else {
      d = 'N';
    }
  }
}