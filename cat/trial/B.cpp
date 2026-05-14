#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    long long mn = *min_element(a.begin(), a.end());
    long long mx = *max_element(a.begin(), a.end());
    long long sum = reduce(a.begin(), a.end(), 0LL);
    for (long long i = 0; ; i++) {
        if (i != mn && i != mx && i != sum) {
            printf("%lld\n", i);
            break;
        }
    }

    return 0;
}