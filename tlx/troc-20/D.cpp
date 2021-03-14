#include <bits/stdc++.h>
using namespace std;

int n, a[100100];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  if (n <= 4) {
    puts("YES");
    return 0;
  }
  // in one move, A should be able to make everything identical
  int flips = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i-1]) flips++;
  }
  puts(flips <= 2 ? "YES" : "NO");

  return 0;
}