#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000009LL

int main() {
    for (int i = 0; i < 100; ++i) {
        long long x;
        scanf("%lld", &x);
        printf("%lld\n", (x + MOD) % MOD);
    }
    return 0;
}