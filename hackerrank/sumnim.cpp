#include <bits/stdc++.h>
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
using namespace std;

#define MAXN 40

vector<map<long long, long long> > calc(long long *a, int n) {
    vector<map<long long, long long> > results;
    results.resize(n + 1);
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long xxor = 0, sum = 0;
        int last = -1;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (mask & (1 << i)) {
                xxor ^= sum;
                sum = 0;
                last = i;
            }
        }
        results[last + 1][xxor]++;
    }
    return results;
}

int main() {
    int n;
    long long a[MAXN];
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    int n1 = n / 2;
    int n2 = n - n1;
    long long *b = a + n1;
    reverse(b, b + n2);
    
    long long suma = 0, sumb = 0;
    for (int i = 0; i < n1; ++i) {
        suma += a[i];
    }
    for (int i = 0; i < n2; ++i) {
        sumb += b[i];
    }
    long long tempSumb = sumb;
    
    vector<map<long long, long long> > resultL = calc(a, n1);
    vector<map<long long, long long> > resultR = calc(b, n2);
    
    long long ans = 0;
    FORIT(it, resultL[n1]) {
    	ans += it->second * resultR[n2][it->first];
    }
    for (int ia = 0; ia < n1; ++ia) {
        long long sum = tempSumb + suma;
        for (int ib = 0; ib < n2; ++ib) {
            FORIT(it, resultL[ia]) {
                ans += it->second * resultR[ib][it->first ^ sum];
            }
            if (ib < n2) {
            	sum -= b[ib];
            }
        }
        if (ia < n1) {
	        suma -= a[ia];
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
