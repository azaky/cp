#include <bits/stdc++.h>
using namespace std;

/** Extended Euclid | returns <x,y> where ax + by = gcd(a,b) **/
/* complexity: O(min(log(a),log(b))) */
pair<long long, long long> extendedEuclid(long long a, long long b) {
  long long x = 0, y = 1, lastx = 1, lasty = 0;
  // maintain two equations:
  // a_i = a * lastx + b * lasty
  // b_i = a * x     + b * y
  while (b != 0) {
    long long quotient = a / b;
    /* (a, b) = (b, a mod b) */
    long long temp = a;
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
long long multiplicativeInverse(long long a, long long m) {
  /* if m is prime, return power(a,m-2,m); */
  pair<long long, long long> xy = extendedEuclid(a, m);
  return ((xy.first % m) + m) % m;
}

long long wheel(long long n, long long d, long long a, long long b) {
  // impossible case.
  long long step = __gcd(n, d);
  long long diff = abs(a - b);
  if (diff % step != 0) {
    return -1;
  }
  // make gcd(n, d) = 1.
  n /= step;
  d /= step;
  diff /= step;
  // a + kd - b = 0 mod n
  // (a - b) + kd = 0 mod n
  // k = (b - a) * (d ^ -1) mod n.
  long long dinv = multiplicativeInverse(d, n);
  long long ans1 = (dinv * diff) % n;
  long long ans2 = (dinv * (n - diff)) % n;
  return min(ans1, ans2);
}

void solve(int tc) {
  int w;
  long long n, d;
  scanf("%d%lld%lld", &w, &n, &d);
  vector<long long> a(w);
  for (int i = 0; i < w; i++) {
    scanf("%lld", &a[i]);
  }
  long long ans = 0;
  for (int i = 0; i < w / 2; i++) {
    long long ww = wheel(n, d, a[i], a[w - 1 - i]);
    if (ww == -1) {
      printf("Case #%d: IMPOSSIBLE\n", tc);
      return;
    }
    ans += ww;
  }
  printf("Case #%d: %lld\n", tc, ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; itc++) {
    solve(itc);
  }
}