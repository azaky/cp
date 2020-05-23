#include <bits/stdc++.h>
using namespace std;

char a[50][50], ans[50];
int v[50], p[50][50];

int main() {
  int ntc, r, c, n;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i) {
      scanf("%s", a[i]);
    }
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        p[i][j] = 0;
      }
      v[i] = 0;
    }
    n = 0;
    for (int ic = 0; ic < c; ++ic) {
      for (int ar = 0; ar < r; ++ar) {
        if (!v[a[ar][ic] - 'A']) {
          v[a[ar][ic] - 'A'] = 1;
          n++;
        }
        for (int br = ar + 1; br < r; ++br) {
          p[a[br][ic] - 'A'][a[ar][ic] - 'A'] = 1;
        }
      }
    }
    bool valid = true;
    ans[n] = 0;
    for (int i = 0; i < n; ++i) {
      int f = -1;
      for (int j = 0; j < 26; ++j) {
        if (!v[j]) continue;
        bool can = true;
        for (int k = 0; k < 26; ++k) {
          if (p[k][j] && k != j) {
            can = false;
            break;
          }
        }
        if (can) {
          f = j;
          break;
        }
      }
      if (f == -1) {
        valid = false;
        break;
      }
      ans[i] = 'A' + f;
      for (int k = 0; k < 26; ++k) {
        p[f][k] = 0;
      }
      v[f] = 0;
    }
    if (valid) {
      printf("Case #%d: %s\n", itc, ans);
    } else {
      printf("Case #%d: -1\n", itc);
    }
  }
}