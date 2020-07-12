#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 100000, q = 100000, tc = 10;
  vector<int> a;
  for (int i = 0; i < n-1; ++i) {
    a.push_back(i+1);
  }
  random_shuffle(a.begin(), a.end());

  printf("%d\n", tc);
  for (int itc = 0; itc < tc; ++itc) {
    printf("%d %d\n", n, q);
    for (int i = 0; i < n-1; ++i) {
      printf("%d ", a[i]);
    }
    putchar('\n');
    for (int i = 0; i < q; ++i) {
      printf("%d %d\n", rand() % n + 1, rand() % n + 1);
    }
  }
}