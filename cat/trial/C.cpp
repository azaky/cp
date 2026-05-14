#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    string ab, ba;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        ab += a[i]; ab += b[i];
        ba += b[i]; ba += a[i];
    }
    cout << min(ab, ba) << endl;

    return 0;
}