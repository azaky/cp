#include <bits/stdc++.h>
using namespace std;

char a[2002], b[2002];
int n;

int main() {
    scanf("%d%s%s", &n, a, b);
    int d = (a[0] - b[0] + 10) % 10;
    for (int i = 0; i < n; i++) {
        if (((a[i] - b[i] + 10) % 10) != d) {
            puts("TIDAK");
            return 0;
        }
    }
    puts("YA");
    return 0;
}