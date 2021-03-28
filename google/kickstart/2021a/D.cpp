#include <bits/stdc++.h>
using namespace std;

#define MAXN 505
#define INF 1000000000

int n;
int a[MAXN][MAXN], b[MAXN][MAXN];
int c[MAXN+MAXN], used[MAXN+MAXN];

int ans = 0;

void kruskal(int v) {
  if (v < n) {
    for (int i = 0; i < n; ++i) {
      c[n+i] = b[v][i];
    }
  } else {
    for (int i = 0; i < n; ++i) {
      c[i] = b[i][v-n];
    }
  }
  used[v] = 1;
  while (true) {
    int maxk = -1;
    for (int k = 0; k < 2*n; ++k) {
      if (!used[k] && (maxk == -1 || c[k] > c[maxk])) {
        maxk = k;
      }
    }
    if (maxk == -1 || c[maxk] == 0) break;
    // printf("maxk = %d, cost = %d\n", maxk, c[maxk]);
    ans -= c[maxk];
    used[maxk] = 1;
    if (maxk < n) {
      for (int i = 0; i < n; ++i) {
        c[n+i] = max(c[n+i], b[maxk][i]);
      }
    } else {
      for (int i = 0; i < n; ++i) {
        c[i] = max(c[i], b[i][maxk-n]);
      }
    }
  }
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &b[i][j]);
      }
    }
    // we don't really need checksums
    for (int i = 0; i < n; ++i) {
      int _x;
      scanf("%d", &_x);
    }
    for (int i = 0; i < n; ++i) {
      int _x;
      scanf("%d", &_x);
    }

    ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == -1) {
          ans += b[i][j];
        }
      }
    }
    for (int i = 0; i < 2*n; ++i) {
      c[i] = 0;
      used[i] = 0;
    }
    for (int i = 0; i < 2*n; ++i) {
      if (!used[i]) {
        kruskal(i);
      }
    }

    printf("Case #%d: %d\n", itc, ans);
  }
}