#include <bits/stdc++.h>
using namespace std;

#define MAXN 50000
#define MAXK 400

int n, m, k, h[MAXN + 1];
vector<int> hk[MAXN + 1];
int hi[MAXN + 1];
int dpprev[MAXN + 1][MAXK + 1];
int dpans[MAXN + 1][MAXK + 1];

int main() {
  scanf("%d%d%d", &n, &m, &k);

  if (k >= n) {
    puts("0");
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &h[i]);
    hi[i] = hk[h[i]].size();
    hk[h[i]].push_back(i);
  }

  set<int> uk;
  uk.insert(0);

  // N^2K DP
  for (int i = 1; i <= n; ++i) {
    // for (int ik = 0; ik <= k; ++ik) {
    //   dp[i][ik] = i;
    // }

    // determine critical points
    int prevhi = hi[i] - m;
    if (prevhi >= 0) {
      uk.insert(hk[h[i]][prevhi]);
      while (uk.size() > k + 1) {
        uk.erase(uk.begin());
      }
    }

    // printf("i = %d:", i);
    // for (int u : uk) printf(" %d", u);
    // puts("");

    int ck = 0, last;
    for (auto it = uk.rbegin(); it != uk.rend(); it++, ck++) {
      int ukv = *it;
      dpprev[i][ck] = ukv;
      last = ukv;
      // for (int ik = ck; ik <= k; ++ik) {
      //   dp[i][ik] = min(dp[i][ik], dp[ukv][ik - ck] + 1);
      // }
    }
    for (int ik = ck; ik <= k; ik++) {
      dpprev[i][ik] = last;
    }

    // for (int ik = 0; ik <= k; ++ik) {
    //   printf("\tdp[%d][%d] = %d\n", i, ik, dp[i][ik]);
    // }
  }

  if (*max_element(h + 1, h + n + 1) == 1) {
    printf("%d\n", (n - k + m - 1) / m);
    return 0;
  }

  int ans = 1;
  for (int ik = 0; ik <= k; ++ik) {
    dpans[ans][ik] = dpprev[n][ik];
  }
  while (dpans[ans][k] > 0) {
    ans++;
    for (int ik = 0; ik <= k; ++ik) {
      dpans[ans][ik] = n;
      for (int jk = 0; jk <= ik; ++jk) {
        dpans[ans][ik] = min(dpans[ans][ik], dpprev[dpans[ans - 1][jk]][ik - jk]);
      }
    }
  }

  printf("%d\n", ans);
}
