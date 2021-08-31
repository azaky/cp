#include <bits/stdc++.h>
using namespace std;

char s[5000];
int n;
int c[26][26];

bool isVowel(int a) {
  return a == 4 || a == 8 || a == 20 || a == 14 || a == 0;
}

void solve() {
  scanf("%s", s);
  n = strlen(s);

  for (int a = 0; a < 26; ++a) {
    for (int b = 0; b < 26; ++b) {
      c[a][b] = -1;
    }
    c[a][a] = 0;
  }
  for (int a = 0; a < 26; ++a) {
    for (int b = 0; b < 26; ++b) {
      if (isVowel(a) ^ isVowel(b)) {
        c[a][b] = 1;
      }
    }
  }
  for (int k = 0; k < 26; ++k) {
    for (int a = 0; a < 26; ++a) {
      for (int b = 0; b < 26; ++b) {
        if (c[a][k] != -1 && c[k][b] != -1) {
          int d = c[a][k] + c[k][b];
          if (c[a][b] == -1 || c[a][b] > d) {
            c[a][b] = d;
          }
        }
      }
    }
  }

  int best = -1;
  for (int t = 0; t < 26; ++t) {
    int cost = 0;
    for (int i = 0; i < n; ++i) {
      int d = c[s[i] - 'A'][t];
      if (d == -1) {
        cost = -1;
        break;
      } else {
        cost += d;
      }
    }
    if (best == -1 || cost < best) {
      best = cost;
    }
  }
  printf("%d\n", best);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}