#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

#define MAXN 200000
#define MAXK 20
#define MAXT (1<<MAXK)
#define MAXS 4845
vector<int> masks;
int imask[MAXT];
vector<int> maskt[MAXS];

char buffer[MAXK + 1];
int n, k, s;
int m[MAXK];
int win[MAXS][MAXK];
int S;

pii q[MAXN];

int dp[2][MAXS];
int cm[MAXK];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < 4; ++i) {
    int x;
    scanf("%d", &x);
    s ^= (1 << (x - 1));
  }

  memset(imask, -1, sizeof(imask));
  for (int mask = 0; mask < (1 << k); mask++) {
    if (__builtin_popcount(mask) != 4) continue;
    imask[mask] = masks.size();
    masks.push_back(mask);
  }
  S = masks.size();

  for (int i = 0; i < S; ++i) {
    for (int j = 0; j < S; ++j) {
      if (i == j || __builtin_popcount(masks[i] ^ masks[j]) == 2) {
        maskt[i].push_back(j);
      }
    }
  }

  for (int i = 0; i < k; ++i) {
    scanf("%s", buffer);
    for (int j = 0; j < k; ++j) {
      if (buffer[j] == '1') {
        m[j] ^= (1 << i);
      }
    }
  }

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < S; ++j) {
      if (m[i] & masks[j]) {
        win[j][i] = 1;
      }
    }
  }

  int clib = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &q[i].A);
    if (q[i].A == 1) {
      scanf("%d", &q[i].B);
      q[i].B--;
    }
    else clib++;
  }

  int x = 0, y = 1;
  memset(dp[x], -1, sizeof(dp[x]));
  dp[x][imask[s]] = 0;

  if (clib <= 3) {
    for (int iq = 0; iq < n; ++iq) {
      if (q[iq].A == 1) {
        cm[q[iq].B]++;
      }
      else {
        // fight "buffered" monsters
        for (int i = 0; i < S; ++i) {
          if (dp[x][i] == -1) continue;
          for (int j = 0; j < k; ++j) {
            if (win[i][j]) {
              dp[x][i] += cm[j];
            }
          }
        }
        for (int i = 0; i < k; ++i)
          cm[i] = 0;

        for (int i = 0; i < S; ++i) {
          dp[y][i] = -1;
        }
        for (int i = 0; i < S; ++i) {
          for (int j : maskt[i]) {
            dp[y][j] = max(dp[y][j], dp[x][i]);
          }
        }
        x = 1 - x;
        y = 1 - y;
      }
    }
    for (int i = 0; i < S; ++i) {
      if (dp[x][i] == -1) continue;
      for (int j = 0; j < k; ++j) {
        if (win[i][j]) {
          dp[x][i] += cm[j];
        }
      }
    }
  }
  else {
    for (int iq = 0; iq < n; ++iq) {
      if (q[iq].A == 1) {
        for (int i = 0; i < S; ++i) {
          if (dp[x][i] != -1 && win[i][q[iq].B]) {
            dp[x][i]++;
          }
        }
      }
      else {
        for (int i = 0; i < S; ++i) {
          dp[y][i] = -1;
        }
        for (int i = 0; i < S; ++i) {
          for (int j : maskt[i]) {
            dp[y][j] = max(dp[y][j], dp[x][i]);
          }
        }
        x = 1 - x;
        y = 1 - y;
      }
    }
  }


  printf("%d\n", *max_element(dp[x], dp[x] + S));

}
