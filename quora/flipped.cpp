#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define MAXC 33

int n, m, b;
double a[MAXN][MAXC];
double s[MAXN];

int main() {
  scanf("%d%d%d", &n, &m, &b);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%lf", &a[i][j]);
    }
  }
  for (int c = 0; c < m; ++c) {
    vector<double> d;
    double mean = 0;
    for (int i = 0; i < n; ++i) {
      d.push_back(a[i][c]);
      mean += a[i][c] / n;
    }
    sort(d.begin(), d.end());
    double q2 = d[n/2];
    double q1 = d[n/4];
    double q3 = d[n * 3 / 4];

    double stdev = 0;
    for (int i = 0; i < n; ++i) {
      stdev += pow(a[i][c] - mean, 2);
    }
    stdev = sqrt(stdev / n);

    // // we score the numbers based on their distance to IQR
    // for (int i = 0; i < n; ++i) {
    //   if (a[i][c] < q1) {
    //     s[i] += q1-a[i][c];
    //   } else if (a[i][c] > q3) {
    //     s[i] += a[i][c]-q3;
    //   }
    // }

    // now using z-score
    for (int i = 0; i < n; ++i) {
      s[i] += fabs((a[i][c] - mean) / stdev);
    }
  }
  vector<pair<double, int>> si;
  for (int i = 0; i < n; ++i) {
    si.emplace_back(s[i], i+1);
  }
  sort(si.begin(), si.end());
  reverse(si.begin(), si.end());
  for (int i = 0; i < b; ++i) {
    printf("%d\n", si[i].second);
  }
}