#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<string> s;
  for (int i = 0; i < n; ++i) {
    static char buffer[100];
    scanf("%s", buffer);
    s.push_back(buffer);
  }
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i].size() > s[i-1].size()) continue;
    string a = s[i-1].substr(0, s[i].size());
    string b = s[i-1].substr(s[i].size(), s[i-1].size() - s[i].size());
    bool allnine = true;
    for (char c : b) {
      if (c != '9') allnine = false;
    }
    if (a < s[i]) {
      for (int j = 0; j < b.size(); ++j) {
        s[i] += '0';
      }
    } else if (s[i] < a || (a == s[i] && allnine)) {
      for (int j = 0; j < b.size()+1; ++j) {
        s[i] += '0';
      }
    } else {
      int t = b.size()-1;
      while (true) {
        if (b[t] == '9') {
          b[t] = '0';
          t--;
        } else {
          b[t]++;
          break;
        }
      }
      s[i] += b;
    }
    ans += s[i].size() - a.size();
  }
  printf("%d\n", ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}