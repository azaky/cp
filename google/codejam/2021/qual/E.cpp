#include <bits/stdc++.h>
using namespace std;

#define MAXN 111
#define MAXQ 10100

int P, c[MAXN];
int a[MAXN][MAXQ];
char buffer[MAXQ];
double s[MAXN], q[MAXQ];

int score = 0;

void answer(int i) {
  if (i == 33) {
    score++;
  }
  printf("%d\n", i);
}

void solve() {
  for (int i = 1; i <= 100; ++i) {
    scanf("%s", buffer);
    int c = 0;
    for (int j = 0; j < 10000; ++j) {
      a[i][j] = buffer[j] - '0';
      c += a[i][j];
    }
    double p = (double)c / 10000;
    s[i] = log((exp(6*p) - 1) / (exp(6) - exp(6*p))) + 3;
    // printf("s[%d] = %.6lf\n", i, s[i]);
  }
  // first, look for max s
  int imaxs = max_element(s+1, s+101) - s;
  if (s[imaxs] > 3.1) {
    answer(imaxs);
    return;
  }

  for (int i = 0; i < 10000; ++i) {
    int d = 0;
    for (int j = 1; j <= 100; ++j) {
      d += a[j][i];
    }
    double p = (double)d / 100;
    q[i] = -(log((exp(6 * p) - 1) / (exp(6) - exp(6 * p))) + 3);
    // printf("q[%d] = %.6lf (%.2lf)\n", i, q[i], p);
  }

  int N_BINS = 20;

  double max_dev = 0;
  int imax = -1;
  for (int i = 1; i <= 100; ++i) {
    double dev = 0;
    vector<double> bins(N_BINS);
    vector<double> cbins(N_BINS);
    for (int j = 0; j < 10000; ++j) {
      int bin = floor((-q[j] + 3) / 6 * N_BINS);
      if (bin < 0) continue;
      if (bin >= N_BINS) continue;
      cbins[bin]++;
      if (a[i][j]) {
        bins[bin]++;
      }
    }
    for (int j = 0; j < N_BINS; ++j) {
      bins[j] /= cbins[j];
    }

    for (int j = 0; j < N_BINS; ++j) {
      double x = s[i] - 3 + 6 * (double)(j)/N_BINS;
      double f = 1. / (1. + exp(-x));
      dev = max(dev, fabs(f - bins[j]));
    }

    if (dev > max_dev) {
      imax = i;
      max_dev = dev;
    }
  }
  answer(imax);

  // if (imax != 33) {
  //   for (int i : {33, imax}) {
  //     vector<double> bins(N_BINS);
  //     vector<double> cbins(N_BINS);
  //     for (int j = 0; j < 10000; ++j) {
  //       int bin = floor((-q[j] + 3) / 6 * N_BINS);
  //       if (bin < 0) continue;
  //       if (bin >= N_BINS) continue;
  //       cbins[bin]++;
  //       if (a[i][j]) {
  //         bins[bin]++;
  //       }
  //     }
  //     for (int j = 0; j < N_BINS; ++j) {
  //       bins[j] /= cbins[j];
  //     }

  //     printf("%3d: [", i);
  //     for (int j = 0; j < N_BINS; ++j) {
  //       if (j) putchar(' ');
  //       printf("%.2lf", bins[j]);
  //     }
  //     printf("]\n");
  //     printf("%3d: [", i);
  //     for (int j = 0; j < N_BINS; ++j) {
  //       if (j) putchar(' ');
  //       double x = s[i] - 3 + 6 * (double)j / N_BINS;
  //       double f = 1. / (1. + exp(-x));
  //       printf("%.2lf", f);
  //     }
  //     printf("]\n");
  //   }
  // }
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  scanf("%d", &P);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
  // printf("score = %.3f\n", (double)score / ntc);
}