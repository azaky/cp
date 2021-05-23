#include <bits/stdc++.h>
using namespace std;

#define N 60

double expected(const string &ans, const int w, const int e) {
  int r = 0, s = 0, p = 0;
  assert(ans.length() == N);
  double x = 0;
  for (int i = 0; i < N; ++i) {
    double pp, pr, ps;
    if (i == 0) {
      pp = pr = ps = 1. / 3.;
    } else {
      pp = (double)r / i;
      pr = (double)s / i;
      ps = (double)p / i;
    }

    assert(fabs(pp + pr + ps - 1) < 1e-12);

    if (ans[i] == 'R') {
      x += pr * e + ps * w;
    } else if (ans[i] == 'P') {
      x += pp * e + pr * w;
    } else if (ans[i] == 'S') {
      x += ps * e + pp * w;
    }

    if (ans[i] == 'R') {
      r++;
    } else if (ans[i] == 'S') {
      s++;
    } else if (ans[i] == 'P') {
      p++;
    } else assert(false);
  }

  return x;
}

double total;

void solve() {
  double w, e;
  scanf("%lf%lf", &w, &e);

  // dp[r][s][p]
  static double dp[61][61][61];
  static char dpc[61][61][61];

  double best = 0;
  int br, bs, bp;
  for (int r = 0; r <= N; ++r) {
    for (int s = 0; s <= N; ++s) {
      for (int p = 0; p <= N; ++p) {
        int i = r + s + p;
        if (i > N || i == 0) continue;

        if (r + s + p == 1) {
          dp[r][s][p] = (w + e) / 3.;
          dpc[r][s][p] = r == 1 ? 'R' : s == 1 ? 'S' : 'P';
          continue;
        }

        dp[r][s][p] = 0;

        double pp = (double)r / (i-1);
        double pr = (double)s / (i-1);
        double ps = (double)p / (i-1);

        if (r > 0) {
          double x = w * ps + e * pr + dp[r-1][s][p];
          if (x > dp[r][s][p]) {
            dp[r][s][p] = x;
            dpc[r][s][p] = 'R';
          }
        }
        
        if (s > 0) {
          double x = w * pp + e * ps + dp[r][s-1][p];
          if (x > dp[r][s][p]) {
            dp[r][s][p] = x;
            dpc[r][s][p] = 'S';
          }
        }
        
        if (p > 0) {
          double x = w * pr + e * pp + dp[r][s][p-1];
          if (x > dp[r][s][p]) {
            dp[r][s][p] = x;
            dpc[r][s][p] = 'P';
          }
        }

        if (r + s + p == N) {
          if (dp[r][s][p] > best) {
            best = dp[r][s][p];
            br = r;
            bs = s;
            bp = p;
          }
        }
      }
    }
  }

  // fprintf(stderr, "best = (%d, %d, %d)\n", br, bs, bp);

  string ans = "";
  while (br + bs + bp > 0) {
    if (dpc[br][bs][bp] == 'R') {
      ans = "R" + ans;
      br--;
    } else if (dpc[br][bs][bp] == 'S') {
      ans = "S" + ans;
      bs--;
    } else if (dpc[br][bs][bp] == 'P') {
      ans = "P" + ans;
      bp--;
    } else assert(false);
    assert(br >= 0 && bs >= 0 && bp >= 0);
  }

  total += expected(ans, w, e);
  printf("%s\n", ans.c_str());
}

int main() {
  total = 0;
  int ntc, x;
  scanf("%d%d", &ntc, &x);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }

  fprintf(stderr, "expected: %.2lf\n", total / ntc);
}