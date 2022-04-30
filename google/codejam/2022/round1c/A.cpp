#include <bits/stdc++.h>
using namespace std;

string solve() {
  int n;
  scanf("%d", &n);
  vector<string> s(n);

  bool allallsame = true;

  vector<bool> allsame(n);

  for (int i =  0; i < n; ++i) {
    static char buffer[100];
    scanf("%s", buffer);
    s[i] = buffer;

    allsame[i] = true;
    for (int j = 0; j < s[i].length(); ++j) {
      if (s[i][j] != s[i][0]) {
        allsame[i] = false;
        break;
      }
    }

    if (!allsame[i]) {
      allallsame = false;
    }
  }

  if (allallsame) {
    string ans = "";
    for (string x : s) {
      ans += x;
    }
    return ans;
  }

  vector<int> pre(n, -1);
  for (int i = 0; i < n; ++i) {
    if (allsame[i]) continue;
    for (int j = 0; j < n; ++j) {
      if (i == j || allsame[j]) continue;
      if (s[i].front() == s[j].back()) {
        if (pre[i] != -1) {
          return "IMPOSSIBLE";
        }
        pre[i] = j;
      }
    }
  }

  vector<int> ans;
  vector<bool> used(n);

  auto append = [&](int i) {
    used[i] = true;
    ans.push_back(i);
    // printf("appending string %d (%s)\n", i, s[i].c_str());
  };

  while (true) {
    // Find single string which have no pre.
    int cur = -1;
    for (int i = 0; i < n; ++i) {
      if (used[i] || allsame[i]) continue;
      if (pre[i] != -1) continue;
      cur = i;
      break;
    }

    if (cur == -1) {
      break;
    }

    // Fill the front of ans with allsame.
    for (int i = 0; i < n; ++i) {
      if (!used[i] && allsame[i] && s[i][0] == s[cur][0]) {
        append(i);
      }
    }

    while (cur != -1) {
      append(cur);

      // Fill with allsame.
      for (int i = 0; i < n; ++i) {
        if (!used[i] && allsame[i] && s[i][0] == s[cur].back()) {
          append(i);
        }
      }

      int nex = -1;
      for (int i = 0; i < n; ++i) {
        if (used[i] || allsame[i]) continue;
        if (pre[i] == cur) {
          if (nex != -1) {
            return "IMPOSSIBLE";
          }
          nex = i;
        }
      }
      cur = nex;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (!used[i] && allsame[i]) {
      append(i);
    }
  }

  if (ans.size() != n) {
    return "IMPOSSIBLE";
  }

  // Validate string.
  string sans = "";
  for (int x : ans) {
    sans += s[x];
  }

  vector<bool> usedc(26);
  usedc[sans[0] - 'A'] = true;
  for (int i = 1; i < sans.size(); ++i) {
    if (sans[i] == sans[i-1]) continue;
    int c = sans[i] - 'A';
    if (usedc[c]) {
      return "IMPOSSIBLE";
    }
    usedc[c] = true;
  }

  return sans;
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: %s\n", itc, solve().c_str());
  }
}