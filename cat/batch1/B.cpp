#include <bits/stdc++.h>
using namespace std;

#define MAXN 300300

long long sum[MAXN];
long long a[MAXN];
int n;

bool can(int ll, int rr) {
    if (ll == rr) return true;
    long long s = sum[rr] - sum[ll-1];
    if (s % 2) return false;
    s /= 2;
    int l = ll, r = rr;
    while (l < r) {
        int m = (l + r) / 2;
        long long sm = sum[m] - sum[ll-1];
        if (sm == s) {
            l = r = m;
        }
        if (sm < s) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
    if (sum[l] - sum[ll-1] == s) {
        return can(ll, l) && can(l+1, rr);
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum[i+1] = sum[i] + a[i];
    }

    if (can(1, n)) {
        puts("YA");
    } else {
        puts("TIDAK");
    }
}
