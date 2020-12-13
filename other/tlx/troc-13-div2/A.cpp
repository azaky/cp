#include <bits/stdc++.h>
using namespace std;

int n;
char s[111];

int main() {
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; ++i) {
    if (i > 0 && s[i] == s[i-1]) continue;
    putchar(s[i]);
  }
  putchar('\n');
}