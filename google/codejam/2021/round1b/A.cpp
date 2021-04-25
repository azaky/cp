#include <bits/stdc++.h>
using namespace std;

typedef __int128_t ll;

/** Extended Euclid | returns <x,y> where ax + by = gcd(a,b) **/
/* complexity: O(min(log(a),log(b))) */
pair<ll, ll> extendedEuclid(ll a, ll b) {
  ll x = 0, y = 1, lastx = 1, lasty = 0;
  // maintain two equations:
  // a_i = a * lastx + b * lasty
  // b_i = a * x     + b * y
  while (b != 0) {
    ll quotient = a / b;
    /* (a, b) = (b, a mod b) */
    ll temp = a;
    a = b;
    b = temp % b;
    /* (x, lastx) = (lastx - quotient*x, x) */
    temp = x;
    x = lastx - quotient * x;
    lastx = temp;
    /* (y, lasty) = (lasty - quotient*y, y) */
    temp = y;
    y = lasty - quotient * y;
    lasty = temp;
  }
  return make_pair(lastx, lasty);
}

/** Multiplicative Inverse | returns a^-1 mod m **/
ll multiplicativeInverse(ll a, ll m) {
  /* if m is prime, return power(a,m-2,m); */
  pair<ll, ll> xy = extendedEuclid(a, m);
  return ((xy.first % m) + m) % m;
}

const ll M = 43200000000000LL;
const ll X = multiplicativeInverse(11, M);
const ll Y = multiplicativeInverse(59, M);

void solve() {
  static ll A[3];
  for (int i = 0; i < 3; ++i) {
    long long tmp;
    scanf("%lld", &tmp);
    A[i] = tmp;
  }
  sort(A, A+3);
  do {
    ll D1 = X * (A[1] - A[0] * 12) % M;
    ll D2 = Y * (A[2] - A[1] * 60) % M;
    D1 = (D1 + M) % M;
    D2 = (D2 + M) % M;
    if (D1 == D2) {
      long long Z = (long long)((A[0] + D1) % M);
      long long ns = (long long)(Z % 1000000000LL);
      Z /= 1000000000LL;
      long long s = (long long)(Z % 60);
      Z /= 60;
      long long m = (long long)(Z % 60);
      Z /= 60;
      long long h = (long long)(Z);
      assert(h < 12);
      printf("%lld %lld %lld %lld\n", h, m, s, ns);
      return;
    }
  } while (next_permutation(A, A + 3));
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}