#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 200200
int n;
int h[MAXN];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &h[i]);
  }

  vector<pair<pii, int>> blocks; // <<left, right>, height>

  vector<pii> s; // <left, height>
  s.emplace_back(1, *min_element(h + 1, h + n + 1));

  for (int i = 1; i <= n; i++) {
    assert(!s.empty());

    if (h[i] == s.back().second) continue;

    if (h[i] > s.back().second) {
      s.emplace_back(i, h[i]);
      continue;
    }

    int l = i;
    while (!s.empty() && h[i] < s.back().second) {
      l = s.back().first;
      int ph = h[i];
      if (s.size() > 1) {
        ph = max(ph, s[s.size() - 2].second);
      }
      blocks.push_back({ {s.back().first, i - 1}, s.back().second - ph });
      s.pop_back();
    }

    assert(!s.empty());

    if (h[i] > s.back().second) {
      s.emplace_back(l, h[i]);
    }
  }

  while (!s.empty()) {
    int ph = 0;
    if (s.size() > 1) {
      ph = max(ph, s[s.size() - 2].second);
    }
    blocks.push_back({ {s.back().first, n} , s.back().second - ph });
    s.pop_back();
  }

  // for (auto p : blocks) {
  //   printf("blocks [%d, %d] h = [%d]\n", p.first.first, p.first.second, p.second);
  // }

  sort(blocks.begin(), blocks.end(), [](const pair<pii, int>& a, const pair<pii, int>& b) -> bool {
    if (a.first.first != b.first.first) {
      return a.first.first < b.first.first;
    }
    if (a.first.second != b.first.second) {
      return a.first.second > b.first.second;
    }
    assert(false);
    });

  // puts("sorted:");
  // for (auto p : blocks) {
  //   printf("blocks [%d, %d] h = [%d]\n", p.first.first, p.first.second, p.second);
  // }

  std::vector<long long> blockSize;
  for (uint i = 0; i < blocks.size(); ++i) {
    long long size = (long long)blocks[i].second * (blocks[i].first.second - blocks[i].first.first + 1);
    if (i == 0) {
      blockSize.push_back(size);
    }
    else {
      blockSize.push_back(blockSize.back() + size);
    }
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    long long k;
    scanf("%lld", &k);

    int idx = lower_bound(blockSize.begin(), blockSize.end(), k) - blockSize.begin();
    if (idx > 0) {
      k -= blockSize[idx - 1];
    }
    assert(k > 0);
    int range = blocks[idx].first.second - blocks[idx].first.first + 1;
    printf("%d\n", blocks[idx].first.first + (int)((k - 1) % range));
  }
}
