#include <bits/stdc++.h>
using namespace std;

void solve(int tc) {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(n), s(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    s[i] = a[i];
  }
  sort(s.begin(), s.end());
  map<int, int> idx;
  for (int i = 0; i < n; i++) {
    idx[s[i]] = i;
  }
  vector<int> sl(n), sr(n);
  vector<int> ml(n), mr(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      sl[i] = -1;
    }
    else {
      sl[i] = sl[i - 1];
      while (sl[i] + 1 < i && s[sl[i] + 1] + k <= s[i]) sl[i]++;
    }
    if (sl[i] == -1) {
      ml[i] = 0;
    }
    else {
      ml[i] = ml[sl[i]] + 1;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      sr[i] = n;
    }
    else {
      sr[i] = sr[i + 1];
      while (sr[i] - 1 > i && s[i] + k <= s[sr[i] - 1]) sr[i]--;
    }
    if (sr[i] == n) {
      mr[i] = 0;
    }
    else {
      mr[i] = mr[sr[i]] + 1;
    }
  }
  printf("Case #%d:", tc);
  for (int x : a) {
    int i = idx[x];
    printf(" %d", 1 + ml[i] + mr[i]);
  }
  printf("\n");
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; itc++) {
    solve(itc);
  }
}