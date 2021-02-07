#include <bits/stdc++.h>
using namespace std;

#define MAXN 500500

int n, x[MAXN], y[MAXN];
long long sum[MAXN], sx[MAXN], sy[MAXN];

int main() {
  vector<int> vx, vy;
  vector<pair<int,int>> ax, ay;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int _x, _y;
    scanf("%d%d", &_x, &_y);
    x[i] = _x + _y;
    y[i] = _x - _y;
    vx.push_back(x[i]);
    vy.push_back(y[i]);
    ax.emplace_back(x[i], i);
    ay.emplace_back(y[i], i);
    // printf("xy[%d] = (%d, %d)\n", i, x[i], y[i]);
  }

  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  sort(ax.begin(), ax.end());
  sort(ay.begin(), ay.end());

  for (int i = 0; i < n; ++i) {
    sx[i+1] = sx[i] + ax[i].first;
    sy[i+1] = sy[i] + ay[i].first;
  }

  int i = 0;
  while (i < n) {
    int l = i;
    int r = i;
    while (r < n && ax[r].first == ax[l].first) r++;
    // printf("x = %d, l = %d, r = %d\n", vx[i], l, r);
    long long suml = (long long)vx[i] * l - sx[i];
    long long sumr = sx[n] - sx[r] - (long long)(n-r) * vx[i];
    while (i < r) {
      sum[ax[i].second] += suml + sumr;
      i++;
    }
  }

  i = 0;
  while (i < n) {
    int l = i;
    int r = i;
    while (r < n && ay[r].first == ay[l].first) r++;
    // printf("y = %d, l = %d, r = %d\n", vy[i], l, r);
    long long suml = (long long)vy[i] * l - sy[i];
    long long sumr = sy[n] - sy[r] - (long long)(n-r) * vy[i];
    while (i < r) {
      sum[ay[i].second] += suml + sumr;
      i++;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (sum[i] < sum[ans]) ans = i;
    // printf("sum[%d] = %lld\n", i+1, sum[i]);
  }
  printf("%d\n", ans+1);
}