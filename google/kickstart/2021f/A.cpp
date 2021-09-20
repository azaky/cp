#include <bits/stdc++.h>
using namespace std;

int n;
char s[500500];

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    scanf("%d", &n);
    scanf("%s", s);
    vector<int> t(n, 1e9);
    int last = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        last = i;
        t[i] = 0;
      }
      else if (last != -1) {
        t[i] = i - last;
      }
    }
    last = -1;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '1') {
        last = i;
      }
      else if (last != -1) {
        t[i] = min(t[i], last - i);
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += t[i];
    }
    printf("Case #%d: %lld\n", itc, ans);
  }
}