#include <bits/stdc++.h>
using namespace std;

void solve() {
  scanf("%d%d", &n, &p);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &k[i]);
  }
  if (p == 1) {
    if (n % 2) {
      puts("1");
    } else {
      puts("0");
    }
    return;
  }
  sort(k, k + n);
  for (int i = 0; i < n; ++i) {
    int t = k[i];
    c[t]++;
    while (c[t] == p) {
      c[t] = 0;
      c[++t]++;
    }
    v[i] = t;
  }
}

 10
 10
  1
  1
110

 10
  1
  1
  1
101

 10
  1
  1
  1
  1

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    solve();
  }
}


5 3
2 1 1 1 1

last = 2
rdiff = 1
diff = 1