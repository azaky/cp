#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, r;
  scanf("%d%d%d", &n, &m, &r);
  r = r * 2 + 1;
  printf("%d\n", (min(n, m) + r - 1) / r);
}