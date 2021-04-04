#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    char s[100];
    scanf("%s", s);
    bool dream = false;
    for (int i = 0; i < strlen(s); ++i) {
      if (s[i] == 'i' || s[i] == 'I') dream = true;
    }
    puts(dream ? "YES" : "NO");
  }
}