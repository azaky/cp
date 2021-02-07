#include <bits/stdc++.h>
using namespace std;

int r() {
  int x = rand() % 1000;
  x *= 1000;
  x += rand() % 1000;
  x *= 1000;
  x += rand() % 1000;
  return x;
}

int main() {
  int n = 500000;
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", r(), r());
  }
}