#include <bits/stdc++.h>
using namespace std;

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    int d, k, n;
    scanf("%d%d%d", &d, &n, &k);
    vector<vector<int>> s(d+1), e(d+1);
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
      int si, ei;
      scanf("%d%d%d", &h[i], &si, &ei);
      s[si].push_back(i);
      e[ei].push_back(i);
    }
    set<pair<int,int>> topk, r;
    long long sumtopk = 0, ans = 0;
    for (int i = 1; i <= d; ++i) {
      // Add attractions that start on day i.
      for (int x : s[i]) {
        if (topk.size() < k) {
          topk.emplace(h[x], x);
          sumtopk += h[x];
        } else {
          auto lowest = *topk.begin();
          if (lowest.first < h[x]) {
            assert(topk.erase(lowest) == 1);
            sumtopk -= lowest.first;
            r.insert(lowest);
            topk.emplace(h[x], x);
            sumtopk += h[x];
          } else {
            r.emplace(h[x], x);
          }
        }
      }

      // if (!topk.empty() || !r.empty()) {
      //   printf("Day %d: topk:", i);
      //   for (auto p : topk) printf(" %d (%d),", p.second, p.first);
      //   printf(" r:");
      //   for (auto p : r) printf(" %d (%d),", p.second, p.first);
      //   printf("\n");
      // }

      ans = max(ans, sumtopk);

      // Remove attractions that end on day i.
      for (int x : e[i]) {
        auto p = make_pair(h[x], x);
        if (topk.count(p)) {
          assert(topk.erase(p) == 1);
          sumtopk -= h[x];
        } else {
          assert(r.count(p));
          assert(r.erase(p) == 1);
        }
      }
      while (topk.size() < k && !r.empty()) {
        auto highest = *r.rbegin();
        assert(r.erase(highest) == 1);
        topk.insert(highest);
        sumtopk += highest.first;
      }
    }
    printf("Case #%d: %lld\n", itc, ans);
  }
}