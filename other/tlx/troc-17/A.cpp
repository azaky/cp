#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int p = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    p ^= (x & 1);
  }
  printf("%d\n", p);
}