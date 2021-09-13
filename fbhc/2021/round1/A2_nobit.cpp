#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

int n;
char s[800800];

void solve() {
  scanf("%d", &n);
  scanf("%s", s);

  long long ans = 0, fixed = 0, temp = 0;
  long long sum = 0, tail = 0;
  char last = 'F';
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'F') {
      temp++;
    } else {
      if (last != s[i]) {
        sum += tail;
        tail = 0;
        fixed += sum;
        fixed %= MOD;
      }
      tail += temp+1;
      temp = 0;
      last = s[i];
    }
    ans += fixed;
    ans %= MOD;

    puts("");
    for (int j = 0; j <= i; ++j) {
      putchar(s[j]);
    }
    puts("");
    printf("sum   = %lld\n", sum);
    printf("fixed = %lld\n", fixed);
    printf("ans   = %lld\n", ans);
    printf("tail  = %lld\n", tail);
    printf("temp  = %lld\n", temp);
  }

  printf("%lld\n", ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}