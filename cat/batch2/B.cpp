#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long t;
    scanf("%d%lld", &n, &t);

    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
    }

    sort(a.begin(), a.end());

    if (t < a[0].first) {
        puts("0");
        return 0;
    }
    
    long long ans = 0;

    // strategy 0: a[0] (b[0] a[0]) ...
    long long ans0 = 1LL + (t - a[0].first) / (a[0].first + a[0].second);

    // strategy 1: a[0] a[1] a[0] a[1] ...
    if (a.size() > 1) {
        long long alt1 = (t - a[0].first) / (a[0].first + a[1].first);
        long long ans1 = 1LL + alt1 * 2LL;
        if (t - a[0].first - (a[0].first + a[1].first) * alt1 >= a[1].first) {
            ans1++;
        }
        ans = max(ans, ans1);
    }

    printf("%lld\n", ans);

    return 0;
}