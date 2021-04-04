#include <bits/stdc++.h>
using namespace std;

vector<int> cf(int A, int B) {
  int a0 = A / B;
  A -= a0 * B;
  if (A == 0) {
    return {a0};
  }
  auto n = cf(B, A);
  n.insert(n.begin(), a0);
  return n;
}

int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  int A = a*d + b*c;
  int B = b*d;
  int D = __gcd(A, B);
  A /= D;
  B /= D;

  // find continued fraction
  auto f = cf(A, B);
  // for (int i = 0; i < f.size(); ++i) {
  //   printf("%d ", f[i]);
  // }
  // puts("");
  long long P = 0;
  long long Q = 1;
  for (int i = 1; i < f.size(); ++i) {
    P <<= f[i];
    if (i & 1) {
      P += 1;
    } else {
      P -= 1;
    }
    Q <<= f[i];
  }
  P <<= 1;
  P += Q * f[0];

  long long R = __gcd(P, Q);
  printf("%lld %lld\n", P/R, Q/R);
}