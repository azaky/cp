#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

#define AMOD(v) ((((v) % MOD) + MOD) % MOD)

int n;
char s[800001];

void solve() {
  scanf("%d", &n);
  scanf("%s", s);

  long long k = 0, t1 = 0, tk1 = 0, A = 0, T = 0, S = 0, ans = 0;
  // Note that we need kmod2 to check for k mod 2 value,
  // since the value of k % 2 may not be accurate after applying mods.
  int kmod2 = 0;

  char last = 'F';

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'F') {
      // Case 1: appending F
      ans = AMOD(ans + k * (A + T) - S);
      tk1 = AMOD(tk1 + 1);
      
      // Handle t1
      if (last == 'F') {
        t1 = AMOD(t1 + 1);
      }
    } else if (s[i] == 'X' || s[i] == 'O') {
      if (last == s[i]) {
        // Case 2: appending matching character
        ans = AMOD(ans + k * (A + T) - S);
        A = AMOD(A + tk1 + 1);
        S = AMOD(S + k * (tk1 + 1));
        tk1 = 0;
      } else {
        // Case 3: appending different character
        ans = AMOD(ans + (k + 1) * (A + T) - S);
        A = AMOD(A + 1);
        T = AMOD(T + tk1);
        S = AMOD(S + (k + 1) * (tk1 + 1));
        k = AMOD(k + 1);
        kmod2 = !kmod2;
        tk1 = 0;
      }
      last = s[i];
    } else {
      if (last == 'F') {
        // Special case: duplication where k is still 0
        tk1 = AMOD(tk1 * 2);
        t1 = AMOD(t1 * 2);
      } else if (kmod2 == 0) {
        // Case 4: duplication, different first and last character
        ans = AMOD(ans * 2 + t1 * tk1 + (A + T + tk1) * AMOD(k * (A + T + tk1) - T - tk1));
        S = AMOD(S * 2 + k * (A + T + tk1) + tk1);
        A = AMOD(A * 2);
        T = AMOD(T * 2 + tk1);
        k = AMOD(k * 2);
      } else {
        // Case 5: duplication, matching first and last character
        ans = AMOD(ans * 2 + (A + T + tk1) * AMOD((k - 1) * (A + T + tk1) - T + t1));
        S = AMOD(S * 2 + tk1 * k + (k - 1) * (A + T));
        A = AMOD(A * 2 + t1 + tk1);
        T = AMOD(T * 2 - t1);
        k = AMOD(k * 2 - 1);
      }
    }
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
