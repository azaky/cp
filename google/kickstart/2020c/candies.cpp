#include <bits/stdc++.h>
using namespace std;

template<class T> class BIT {
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

#define MAXN 200100
long long a[MAXN], s[MAXN], t[MAXN];
char qs[2];

int one(int x) {
  return (x & 1) ? -1 : 1;
}

int main() {
  int ntc, n, q;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    scanf("%d%d", &n, &q);
    BIT<long long> S(n), T(n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      s[i] = a[i] * i * one(i-1);
      t[i] = a[i] * one(i-1);
      S.update(i, s[i]);
      T.update(i, t[i]);
    }
    long long ans = 0;
    for (int iq = 0; iq < q; ++iq) {
      scanf("%s", qs);
      if (qs[0] == 'Q') {
        int l, r;
        scanf("%d%d", &l, &r);
        long long qa = (S.sum(l, r) - T.sum(l, r) * (l - 1)) * one(l - 1);
        ans += qa;
      } else {
        int x; long long v;
        scanf("%d%lld", &x, &v);
        a[x] = v;
        long long ds = a[x] * x * one(x-1) - s[x];
        long long dt = a[x] * one(x-1) - t[x];
        S.update(x, ds);
        T.update(x, dt);
        s[x] += ds;
        t[x] += dt;
      }
    }
    printf("Case #%d: %lld\n", itc, ans);
  }
}