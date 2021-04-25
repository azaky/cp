#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long p) {
  if (p % 2 == 0) return false;
  for (long long i = 3; i * i <= p; i += 2) {
    if (p % i == 0) return false;
  }
  return true;
}

void solve() {
  long long z;
  scanf("%lld", &z);
  if (z < 15) {
    puts("6");
    return;
  }
  long long s = (long long)sqrtf128((__float128)z);
  assert(s * s <= z);
  // pick one prime above s and one below s
  long long q = s+1;
  while (!isPrime(q)) q++;
  long long p = s;
  while (!isPrime(p)) p--;
  while (p * q > z) {
    q = p;
    p--;
    while (!isPrime(p)) p--;
  }
  printf("%lld\n", p*q);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}