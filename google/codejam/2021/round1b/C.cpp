#include <bits/stdc++.h>
using namespace std;

int N, B, P;

void solve() {
  vector<int> h(N);
  int full = 0;
  for (int _ = 0; _ < N*B; ++_) {
    int d;
    scanf("%d", &d);
    int best = -1;
    for (int i = 0; i < N; ++i) {
      if (h[i] < B && (best == -1 || h[i] > h[best])) best = i;
    }
    assert(best != -1);
    if (d == 9) {
      // if possible, put 9 at the most significant digit
      // i.e. do nothing
    } else {
      int best2 = -1;
      for (int i = 0; i < N; ++i) {
        if (h[i] < B-1 && (best2 == -1 || h[i] > h[best2])) best2 = i;
      }

      int best3 = -1;
      for (int i = 0; i < N; ++i) {
        if (h[i] < B - 2 && (best3 == -1 || h[i] > h[best3])) best3 = i;
      }

      if (best2 != -1 && ((8 <= d) || (5 <= d && full >= N-4))) {
        best = best2;
      } else if (best3 != -1) {
        best = best3;
      }
    }

    assert(best >= 0 && best < N);

    h[best]++;
    printf("%d\n", best + 1);
    fflush(stdout);

    if (h[best] == B) full++;
  }
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  scanf("%d%d%d", &N, &B, &P);
  for (int itc = 1; itc <= ntc; ++itc) {
    // printf("Case #%d: ", itc);
    solve();
  }
  int res;
  scanf("%d", &res);
  assert(res == 1);
}