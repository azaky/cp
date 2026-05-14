#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001001
#define MOD 998244353LL

long long powmod(long long a, long long b) {
    if (b == 0) return 1;
    if (b & 1) return (a * powmod(a, b-1)) % MOD;
    return powmod((a * a) % MOD, b / 2);
}

long long inv(long long x) {
    return powmod(x, MOD-2);
}

long long f[MAXN];
long long finv[MAXN];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a((int)m);
    map<int,int> cnt;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    f[0] = finv[0] = 1;
    for (long long i = 1; i <= n; i++) {
        f[i] = (f[i-1] * i) % MOD;
        finv[i] = inv(f[i]);
    }

    long long ans = f[n];
    for (int i = 0; i < m; i++) {
        ans *= finv[a[i]];
        ans %= MOD;
    }

    for (auto &p : cnt) {
        if (p.first) {
            ans *= finv[p.second];
            ans %= MOD;
        }
    }

    printf("%lld\n", ans);
}