#include <bits/stdc++.h>
using namespace std;

int k, h[30];

void check(vector<int> ans) {
  int n = ans.size(), x = 0;
  for (int i = 0; i < n; ++i) {
    assert(1 <= ans[i] && ans[i] <= (1 << 30) - 1);
    x ^= ans[i];
    for (int j = 0; j < i; ++j) {
      assert(ans[i] != ans[j]);
      assert((ans[i] & ans[j]) == ans[i]);
    }
  }
  assert(x == k);
}

int main() {
  scanf("%d", &k);
  int nk = __builtin_popcount(k) * 2;
  int lastodd = -1, lasteven = 0;
  for (int i = 0; i < 30; ++i) {
    if (k & (1 << i)) {
      lastodd += 2;
      h[i] = lastodd;
    } else {
      lasteven += 2;
      if (lasteven > nk) lasteven = nk;
      h[i] = lasteven;
    }
  }
  vector<int> ans;
  for (int i = 0; i < nk; ++i) {
    int num = 0;
    for (int j = 0; j < 30; ++j) {
      if (i < h[j]) num |= (1 << j);
    }
    ans.push_back(num);
  }

  check(ans);

  printf("%d\n", nk);
  for (int i = 0; i < nk; ++i) {
    if (i) putchar(' ');
    printf("%d", ans[i]);
  }
  putchar('\n');
}
