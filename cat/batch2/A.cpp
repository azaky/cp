#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    scanf("%d%d", &n, &l);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    vector<pair<int,int>> dm(l);
    for (int i = 0; i < l; i++) {
        scanf("%d%d", &dm[i].first, &dm[i].second);
    }
    for (int i = 0; i+1 < l; i++) {
        int d = dm[i].first, m = dm[i].second;
        d++;
        if (d > b[m-1]) {
            d = 1;
            m++;
        }
        d++;
        if (d > b[m-1]) {
            d = 1;
            m++;
        }
        if (d == dm[i+1].first && m == dm[i+1].second) {
            puts("YA");
            return 0;
        }
    }

    puts("TIDAK");

    return 0;
}