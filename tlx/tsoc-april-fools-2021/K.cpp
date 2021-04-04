#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[100];
  a[0] = 1;
  a[1] = 1;
  a[2] = 1;
  a[3] = 2;
  a[4] = 2;
  a[5] = 1;
  a[6] = 1;
  a[7] = 1;
  a[8] = 1;
  a[9] = 1;

  char s[100];
  scanf("%s", s);
  int ans = 0;
  for (int i = 0; i < strlen(s); ++i) {
    if (s[i] == '-') {
      ans++;
    } else {
      ans += a[s[i] - '0'];
    }
  }
  printf("%d\n", ans);
}