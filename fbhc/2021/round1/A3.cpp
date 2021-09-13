#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

#define MMOD(v) v = ((((v) % MOD) + MOD) % MOD)
#define AMOD(v) ((((v) % MOD) + MOD) % MOD)

int n;
char s[800800];

int a2(const string &u) {
  long long ans = 0, fixed = 0, temp = 0;
  long long sum = 0, tail = 0;
  char last = 'F';
  for (int i = 0; i < u.size(); ++i) {
    if (u[i] == 'F') {
      temp++;
    }
    else {
      if (last != u[i]) {
        sum += tail;
        tail = 0;
        fixed += sum;
        fixed %= MOD;
      }
      tail += temp + 1;
      temp = 0;
      last = u[i];
    }
    ans += fixed;
    ans %= MOD;
  }

  return ans;
}

void verify(const string &u, int _k, int _t1, int _tk1, int _A, int _T, int _S, int _ans) {
  vector<int> a(1, 0), t(2, 0);
  int k = 0;
  char last = 'F';
  for (int i = 0; i < u.size(); ++i) {
    if (u[i] == 'F') {
      t[k+1]++;
    } else if (last == 'F') {
      k++;
      a.push_back(1);
      t.push_back(0);
    } else if (u[i] == last) {
      a[k] += t[k+1] + 1;
      t[k+1] = 0;
    } else {
      k++;
      a.push_back(1);
      t.push_back(0);
    }

    if (u[i] != 'F') {
      last = u[i];
    }
  }

  assert(a.size() == k+1);
  assert(t.size() == k+2);

  // for (int i = 1; i <= k; ++i) {
  //   printf("(%d) %d ", t[i], a[i]);
  // }
  // printf("| (%d)\n", t[k+1]);

  int A = 0, T = 0, S = 0, ans = 0;
  for (int i = 1; i <= k; ++i) {
    A += a[i];
    T += t[i];
    S += AMOD(i * (a[i] + t[i]));
    S %= MOD;
    for (int j = 1; j < i; ++j) {
      ans += (a[i] + t[i+1]) * (i-j) * (t[j] + a[j]);
      ans %= MOD;
    }
  }

  // printf("verify (len = %lu):\n", u.size());
  // puts(u.c_str());
  // printf("k = %d\n", k);
  // printf("t1 = %d\n", t[1]);
  // printf("tk1 = %d\n", t[k+1]);
  // printf("A = %d\n", A);
  // printf("T = %d\n", T);
  // printf("S = %d\n", S);
  // printf("ans = %d\n", ans);

  assert(k == _k);
  assert(t[1] == _t1);
  assert(t[k+1] == _tk1);
  assert(A == _A);
  assert(T == _T);
  assert(S == _S);
  assert(ans == _ans);
  assert(ans == a2(u));
}

void solve() {
  scanf("%d", &n);
  scanf("%s", s);

  // k, t1, tk1, A, T, S, ans
  long long k[2] = {0};
  long long kmod2[2] = {0};
  long long t1[2] = {0};
  long long tk1[2] = {0};
  long long A[2] = {0};
  long long T[2] = {0};
  long long S[2] = {0};
  long long ans[2] = {0};

  int c = 0, x = 1;
  char last = 'F';

  string u;

  for (int i = 0; i < n; ++i) {
    // init
    k[x] = k[c];
    kmod2[x] = kmod2[c];
    t1[x] = t1[c];
    tk1[x] = tk1[c];
    A[x] = A[c];
    T[x] = T[c];
    S[x] = S[c];
    ans[x] = ans[c];

    // transition
    if (s[i] == 'F') {
      // wildcard case
      tk1[x] = AMOD(tk1[c] + 1);
      ans[x] = AMOD(ans[c] + k[c] * (A[c] + T[c]) - S[c]);
      if (k[c] == 0) {
        t1[x] = AMOD(t1[c] + 1);
      }
    } else if (s[i] == '.') {
      // double case
      if (last == 'F') {
        // puts("first case");
        assert(k[c] == 0);
        tk1[x] = AMOD(tk1[c] * 2);
        if (k[c] == 0) {
          t1[x] = AMOD(t1[c] * 2);
        }
      } else {
        assert(k[c] > 0);
        if (kmod2[c] == 0) {
          // double case: diff
          // puts("double: diff");
          ans[x] = ans[c] * 2 + t1[c] * tk1[c] + (A[c] + T[c] + tk1[c]) *
            ((k[c] * (A[c] + T[c] + tk1[c]) - T[c] - tk1[c]) % MOD);
          // ans[x] = AMOD(AMOD(ans[c] * 2) + t1[c] * AMOD(k[c] * (A[c] + T[c]) - S[c]));
          // ans[x] += AMOD(k[c] * AMOD(A[c] + T[c]) - S[c]) * AMOD(A[c] + T[c] + tk1[c] - t1[c]);
          // ans[x] += AMOD(A[c] + T[c]) * AMOD((S[c] - T[c] + AMOD(k[c] * tk1[c])));
          // ans[x] += AMOD(tk1[c] * AMOD((S[c] - A[c] - T[c]*2 + AMOD((k[c] - 1) * tk1[c]) + t1[c])));
          MMOD(ans[x]);
          k[x] = AMOD(k[c] * 2);
          kmod2[x] = 0;
          A[x] = AMOD(A[c] * 2);
          T[x] = AMOD(T[c] * 2 + tk1[c]);
          S[x] = AMOD(S[c] * 2 + AMOD((k[c] + 1) * tk1[c]) + AMOD(k[c] * (A[c] + T[c])));
        } else {
          // double case: same
          // puts("double: same");
          // ans[x] = ans[c] * 2 + AMOD(A[c] + T[c] + tk1[c]) *
          //   AMOD(AMOD(k[c] * (A[c] + T[c])) + AMOD(tk1[c] * (k[c] - 1)) - T[c] * 2 - A[c] + t1[c]);
          ans[x] = AMOD(ans[c] * 2 + AMOD(AMOD(A[c] + T[c] + tk1[c]) *
            AMOD(t1[c] + AMOD((k[c] - 1) * (A[c] + T[c] + tk1[c])) - T[c])));
          MMOD(ans[x]);
          k[x] = AMOD(k[c] * 2 - 1);
          kmod2[x] = 1;
          A[x] = AMOD(A[c] * 2 + t1[c] + tk1[c]);
          T[x] = AMOD(T[c] * 2 - t1[c]);
          S[x] = AMOD(S[c] * 2 + AMOD(k[c] * tk1[c]) + AMOD((k[c] - 1)*(A[c] + T[c])));
        }
      }
    } else if (last == 'F') {
      // first case
      // puts("first case");
      // t1[x] = tk1[c];
      tk1[x] = 0;
      assert(k[c] == 0);
      k[x] = 1;
      kmod2[x] = 1;
      A[x] = 1;
      T[x] = tk1[c];
      S[x] = AMOD(tk1[c] + 1);
    } else if (last != s[i]) {
      // diff case
      // puts("diff case");
      ans[x] = AMOD(ans[c] + AMOD((k[c] + 1)*(A[c] + T[c])) - S[c]);
      S[x] = AMOD(S[c] + AMOD((k[c] + 1)*(tk1[c] + 1)));
      k[x] = AMOD(k[c] + 1);
      kmod2[x] = 1-kmod2[c];
      tk1[x] = 0;
      T[x] = AMOD(T[c] + tk1[c]);
      A[x] = AMOD(A[c] + 1);
    } else {
      // same case
      // puts("same case");
      tk1[x] = 0;
      ans[x] = AMOD(ans[c] + AMOD(k[c] * (A[c] + T[c])) - S[c]);
      A[x] = AMOD(A[c] + tk1[c] + 1);
      S[x] = AMOD(S[c] + AMOD(k[c] * (tk1[c] + 1)));
    }

    if (s[i] == 'X' || s[i] == 'O') {
      last = s[i];
    }

    // puts("");
    // for (int j = 0; j <= i; ++j) putchar(s[j]);
    // puts("");
    // printf("k = %lld\n", k[x]);
    // printf("t1 = %lld\n", t1[x]);
    // printf("tk1 = %lld\n", tk1[x]);
    // printf("A = %lld\n", A[x]);
    // printf("T = %lld\n", T[x]);
    // printf("S = %lld\n", S[x]);
    // printf("ans = %lld\n", ans[x]);

    // change state
    swap(c, x);

    // verify

    assert(k[c] >= 0 && k[c] < MOD);
    assert(t1[c] >= 0 && t1[c] < MOD);
    assert(tk1[c] >= 0 && tk1[c] < MOD);
    assert(A[c] >= 0 && A[c] < MOD);
    assert(T[c] >= 0 && T[c] < MOD);
    assert(S[c] >= 0 && S[c] < MOD);
    assert(ans[c] >= 0 && ans[c] < MOD);

    // if (u.size() < 10000) {
    //   if (s[i] == '.') {
    //     u = u + u;
    //   } else {
    //     u = u + s[i];
    //   }
    //   verify(u, k[c], t1[c], tk1[c], A[c], T[c], S[c], ans[c]);
    // }
  }

  long long len = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') {
      len = AMOD(len * 2);
    } else {
      len = AMOD(len + 1);
    }
  }
  assert(AMOD(A[c] + T[c] + tk1[c]) == len);

  printf("%lld\n", (long long)ans[c]);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}
