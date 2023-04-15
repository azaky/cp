#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  int e[26];
  for (int i = 0; i < 26; i++) {
    scanf("%d", &e[i]);
  }
  set<vector<int>> w;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    static char s[100];
    scanf("%s", s);
    int len = strlen(s);
    vector<int> h(len);
    for (int j = 0; j < len; j++) {
      h[j] = e[s[j] - 'A'];
    }
    w.insert(h);
  }
  printf("Case #%d: %s\n", tc, w.size() == n ? "NO" : "YES");
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; itc++) {
    solve(itc);
  }
}