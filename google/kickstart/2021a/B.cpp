#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int r, c, a[MAXN][MAXN];
int sra[MAXN][MAXN];
int srb[MAXN][MAXN];
int sca[MAXN][MAXN];
int scb[MAXN][MAXN];

int L(int x, int y) {
  if (!x || !y) return 0;
  return max(min(x, y/2)-1, 0) + max(min(x/2, y) - 1, 0);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    memset(sra, 0, sizeof(sra));
    memset(srb, 0, sizeof(srb));
    memset(sca, 0, sizeof(sca));
    memset(scb, 0, sizeof(scb));
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        if (a[i][j]) {
          sra[i][j] = 1 + sra[i][j-1];
          sca[i][j] = 1 + sca[i-1][j];
        }
      }
    }
    for (int i = r; i >= 1; --i) {
      for (int j = c; j >= 1; --j) {
        if (a[i][j]) {
          srb[i][j] = 1 + srb[i][j+1];
          scb[i][j] = 1 + scb[i+1][j];
        }
      }
    }
    long long ans = 0;
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        if (a[i][j]) {
          int dans = 0;
          dans += L(sra[i][j], sca[i][j]);
          dans += L(sra[i][j], scb[i][j]);
          dans += L(srb[i][j], sca[i][j]);
          dans += L(srb[i][j], scb[i][j]);
          // printf("[%d][%d] = %d\n", i, j, dans);
          ans += dans;
        }
      }
    }
    printf("Case #%d: %lld\n", itc, ans);
  }
}