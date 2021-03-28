#include <bits/stdc++.h>
using namespace std;

int n, k;
char s[100100];

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for (int i = 0, j = n-1; i < j; ++i, --j) {
      k -= (s[i] != s[j]);
    }
    printf("Case #%d: %d\n", itc, abs(k));
  }
}