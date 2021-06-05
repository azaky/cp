#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> c) {
  int n = 0;
  for (int x : c) n += x;

  auto getMinDigit = [&]() -> int {
    for (int i = 0; i < 10; ++i) {
      if (c[i]) {
        return i;
      }
    }
    return -1;
  };
  auto getMaxDigit = [&]() -> int {
    for (int i = 9; i >= 0; --i) {
      if (c[i]) {
        return i;
      }
    }
    return -1;
  };
  auto getMinNonzeroDigit = [&]() -> int {
    for (int i = 1; i < 10; ++i) {
      if (c[i]) {
        return i;
      }
    }
    return -1;
  };
  auto getMatchingDigit = [&]() -> int {
    for (int i = 0; i < 10; ++i) {
      if (c[i] >= 2) {
        return i;
      }
    }
    return -1;
  };
  auto getMatchingNonzeroDigit = [&]() -> int {
    for (int i = 1; i < 10; ++i) {
      if (c[i] >= 2) {
        return i;
      }
    }
    return -1;
  };

  // odd case
  if (n % 2 == 1) {
    long long A = getMinNonzeroDigit(), B = 0;
    c[(int)A]--;
    for (int i = 0; i < n/2; ++i) {
      A *= 10;
      B *= 10;
      int b = getMaxDigit();
      int a = getMinDigit();
      // fprintf(stderr, "A = %lld, B = %lld\n", A, B);
      c[a]--;
      c[b]--;
      A += a;
      B += b;
    }
    return A - B;
  }

  // even case
  long long best = 1e18;

  auto check = [&](long long A, long long B) {
    long long D = abs(A - B);
    // fprintf(stderr, "checking: %lld %lld (D = %lld)\n", A, B, D);
    if (D < best) {
      best = D;
    }
  };

  auto bruteForce = [&](bool nonzero) {
    // all matching
    bool allzero = true;
    for (int i = 0; i < 10; ++i) {
      if (c[i]) allzero = false;
    }
    if (allzero) {
      check(0, 0);
      return;
    };

    // just brute force combination of first digits
    int start = nonzero ? 1 : 0;
    for (int da = start; da < 10; ++da) {
      for (int db = da + 1; db < 10; ++db) {
        if (c[da] && c[db]) {
          vector<int> tmp = c;

          c[da]--;
          c[db]--;

          long long A = da, B = db;
          while (true) {
            int a = getMaxDigit();
            int b = getMinDigit();
            assert((a == -1) == (b == -1));
            if (a == -1) break;
            A *= 10;
            B *= 10;
            A += a;
            B += b;
            c[a]--;
            c[b]--;
          }
          check(A, B);

          c = tmp;
        }
      }
    }
  };

  // case 1: no 0 & 9
  {
    int d = getMatchingNonzeroDigit();
    if (d == -1) {
      bruteForce(true);
    } else {
      // fprintf(stderr, "d = %d\n", d);
      vector<int> tmp = c;

      c[d] -= 2;
      while (d != -1) {
        d = getMatchingDigit();
        // fprintf(stderr, "\td = %d\n", d);
        if (d == -1) break;
        c[d] -= 2;
      }
      bruteForce(false);

      c = tmp;
    }
  }

  // case 2:
  // <matching> <A> 9x
  // <matching><A+1>0x
  for (int x = 0; x <= min(c[0], c[9]); ++x) {
    // fprintf(stderr, "x = %d\n", x);
    vector<int> tmp = c;

    c[0] -= x;
    c[9] -= x;

    for (int a = 0; a < 9; ++a) {
      if (c[a] && c[a+1]) {
        // fprintf(stderr, "\t picking a = %d, a+1 = %d\n", a, a+1);
        c[a]--; c[a+1]--;

        int d = getMatchingNonzeroDigit();
        if (d != -1 || a > 0) {
          vector<int> tmp2 = c;

          if (d != -1) {
            c[d] -= 2;
          }
          while (d != -1) {
            d = getMatchingDigit();
            if (d == -1) break;
            c[d] -= 2;
          }

          long long A = 0, B = 1;
          while (true) {
            int a = getMaxDigit();
            int b = getMinDigit();
            assert((a == -1) == (b == -1));
            if (a == -1) break;
            A *= 10;
            B *= 10;
            A += a;
            B += b;
            c[a]--;
            c[b]--;
          }
          check(A, B);

          c = tmp2;
        }

        c[a]++; c[a+1]++;
      }
    }

    c = tmp;
  }

  // case 3:
  // <matching><A+1>
  // <matching> <A>

  // for (int a = 1; a < 9; ++a) {
  //   if (c[a] && c[a+1]) {
  //     // fprintf(stderr, "\t picking a = %d, a+1 = %d\n", a, a+1);
  //     c[a]--; c[a + 1]--;

  //     int d = getMatchingNonzeroDigit();
  //     if (d != -1 || a > 0) {
  //       vector<int> tmp2 = c;

  //       if (d != -1) {
  //         c[d] -= 2;
  //       }
  //       while (d != -1) {
  //         d = getMatchingDigit();
  //         if (d == -1) break;
  //         c[d] -= 2;
  //       }

  //       long long A = 0, B = 1;
  //       while (true) {
  //         int a = getMaxDigit();
  //         int b = getMinDigit();
  //         assert((a == -1) == (b == -1));
  //         if (a == -1) break;
  //         A *= 10;
  //         B *= 10;
  //         A += a;
  //         B += b;
  //         c[a]--;
  //         c[b]--;
  //       }
  //       check(A, B);

  //       c = tmp2;
  //     }

  //     c[a]++; c[a + 1]++;
  //   }
  // }

  return best;
}

pair<long long, long long> brute(vector<int> c) {
  int n = 0;
  for (int x : c) n += x;

  int best = 1e9, bestA, bestB;

  auto check = [&](int A, int B) {
    int D = abs(A - B);
    if (D < best) {
      best = D;
      bestA = A;
      bestB = B;
    }
  };
  function<void(int,int,int,int)> dfs = [&](int A, int B, int na, int nb) {
    if (na + nb == n) {
      check(A, B);
      return;
    }
    if (na < n/2) {
      for (int i = 0; i < 10; ++i) {
        if (c[i] && !(A == 0 && i == 0)) {
          c[i]--;
          dfs(10*A + i, B, na+1, nb);
          c[i]++;
        }
      }
    } else {
      assert(nb < (n+1) / 2);
      for (int i = 0; i < 10; ++i) {
        if (c[i] && !(B == 0 && i == 0)) {
          c[i]--;
          dfs(A, 10*B + i, na, nb+1);
          c[i]++;
        }
      }
    }
  };

  dfs(0, 0, 0, 0);

  // fprintf(stderr, "\tA = %d, B = %d\n", bestA, bestB);

  return make_pair(bestA, bestB);
}

int main() {
  // for (int N = 11; N < 1e6; ++N) {
  //   vector<int> c(10, 0);
  //   int t = N, nonzero = 0;
  //   while (t > 0) {
  //     c[t % 10]++;
  //     if (t % 10) nonzero++;
  //     t /= 10;
  //   }
  //   if (nonzero >= 2) {
  //     long long mine = solve(c);
  //     auto ans = brute(c);
  //     if (mine != abs(ans.first-ans.second)) {
  //       printf("N = %d\nmine = %lld\nans  = %lld %lld\n", N, mine, ans.first, ans.second);
  //     }
  //   }
  // }
  // return 0;

  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    char s[100] = { 0 };
    scanf("%s", s);
    int n = strlen(s);
    vector<int> c(10, 0);
    for (int i = 0; i < n; ++i) {
      c[s[i] - '0']++;
    }

    printf("Case #%d: %lld\n", itc, solve(c));
  }
}