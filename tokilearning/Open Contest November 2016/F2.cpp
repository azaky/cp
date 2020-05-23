#include <bits/stdc++.h>
using namespace std;

#define MAXN 200200
char s[MAXN];
int n, Z[MAXN];

int main () {
    scanf("%s", s);
    n = strlen(s);

    set<int> x;
    for (int i = 0; i < n; ++i) {
        if (s[i] == s[0]) {
            x.insert(i);
        }
    }

    int len = 1;
    vector<int> ans;
    while (true) {
        // check first first
        int first = *(x.begin());
        while (x.count(first + len) || first + len >= n) {
            // it is included as answer
            ans.push_back(first);
            x.erase(x.begin());
            first = *(x.begin());
        }
        char c = s[first + len];
        for (auto start : x) {
            if ()
        }
    }

    int L = 0, R = 0;
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R] == s[R-L]) ++R;
            Z[i] = R-L; --R;
        }
        else {
            int k = i-L;
            if (Z[k] < R-i+1) Z[i] = Z[k];
            else {
                L = i;
                while (R < n && s[R] == s[R-L]) ++R;
                Z[i] = R-L; --R;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", Z[i]);
    }
    puts("");

    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; i < n; ++i) {
        if (Z[i]) ans.push_back(i);
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i] + 1);
        if (i == ans.size() - 1) {
            putchar('\n');
        } else {
            putchar(' ');
        }
    }
}

