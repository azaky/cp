#include <bits/stdc++.h>
using namespace std;

int n;
char s[800800];

void solve() {
  scanf("%d", &n);
  scanf("%s", s);
  char last = 'F';
  int changes = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'F') continue;
    if (last != s[i] && last != 'F') changes++;
    last = s[i];
  }
  printf("%d\n", changes);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}