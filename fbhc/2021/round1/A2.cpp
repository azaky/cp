#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

int n;
char s[800800];

template<typename T> class BIT {
public:
  BIT(int n): v(vector<T>(n+1)), n(n) {}
  T sum(int k) {
    T s = 0;
    for (int i = k; i > 0; i -= (i & -i)) {
      s += this->v[i];
    }
    return s;
  }
  T sum(int l, int r) {
    return this->sum(r) - this->sum(l-1);
  }
  void update(int k, T v) {
    for (int i = k; i <= this->n; i += (i & -i)) {
      this->v[i] += v;
    }
  }
private:
  vector<T> v;
  int n;
};

void solve() {
  scanf("%d", &n);
  scanf("%s", s);

  BIT<long long> bit(n);
  long long ans = 0, fixed = 0, temp = 0;
  int k = 0;
  char last = 'F';
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'F') {
      temp++;
    } else {
      if (last != s[i]) {
        fixed += bit.sum(k);
        fixed %= MOD;
        k++;
      }
      bit.update(k, temp+1);
      temp = 0;
      last = s[i];
    }
    ans += fixed;
    ans %= MOD;
    // printf("[%d] = %d:", i, fixed);
    // for (int i = 1; i <= k; ++i) {
    //   printf(" %d", bit.sum(i, i));
    // }
    // printf(" ? %d\n", temp);
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