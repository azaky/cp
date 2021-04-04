#include <bits/stdc++.h>
using namespace std;

int a[5];

int main() {
  for (int i = 0; i < 4; ++i) {
    char s[10];
    scanf("%s", s);
    int p = (s[0] - 'a') + (s[1] - '0');
    a[i] = p % 2;
  }
  int p = (a[0] + a[1] + a[2] + a[3]) % 2;
  // white: even
  if (p == 0) {
    puts("White");
  // black: odd
  } else {
    puts("Black");
  }
}