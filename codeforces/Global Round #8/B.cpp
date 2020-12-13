#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  scanf("%lld", &n);
  vector<long long> c(10, 1);
  while (true) {
    long long p = 1;
    for (int x : c) p *= x;
    if (p >= n) break;
    c[min_element(c.begin(), c.end()) - c.begin()]++;
  }
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < c[i]; ++j) {
      putchar("codeforces"[i]);
    }
  }
  putchar('\n');
}