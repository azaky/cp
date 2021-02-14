#include <bits/stdc++.h>
using namespace std;

int n, a[200200];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a+n);
  int nu = unique(a, a+n) - a;
  if (nu == n) {
    printf("%d\n", n);
  } else if (nu == 1) {
    printf("%d\n", 1);
  } else {
    printf("%d\n", n-1);
  }
}