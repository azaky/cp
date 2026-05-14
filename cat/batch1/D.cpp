#include <bits/stdc++.h>
using namespace std;

#define MAXN 3333

map<pair<int,int>,int> queries;

int n;

int q(int a, int b) {
    if (a > b) swap(a, b);
    pair<int,int> p = {a, b};
    if (queries.count(p)) {
        return queries[p];
    }
    printf("? %d %d\n", a, b);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return queries[p] = ans;
}

void answer(vector<int> &ans) {
    assert(ans.size() == n);
    printf("!");
    for (int i : ans) printf(" %d", i);
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    assert(x == 1);
    exit(0);
}

int t[MAXN];
vector<int> tc[MAXN];

int main() {
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        t[i] = q(1, i);
        tc[t[i]].push_back(i);
    }

    // easiest case: 0-n
    if (tc[0].size() == 1 && tc[n-2].size() == 1) {
        vector<int> ans;
        ans.push_back(1);
        for (int i = 0; i <= n-2; i++) {
            ans.push_back(tc[i].front());
        }
        answer(ans);
    }

    // 0-0
    if (tc[0].size() == 2) {
        vector<int> ans, dans;
        ans.push_back(1);
        ans.push_back(tc[0][0]);
        dans.push_back(tc[0][1]);
        int k = 1;
        while (tc[k].size() == 2) {
            int qq = q(ans.back(), tc[k][0]);
            if (qq == 0 || qq == n-2) {
                ans.push_back(tc[k][0]);
                dans.push_back(tc[k][1]);
            } else {
                dans.push_back(tc[k][0]);
                ans.push_back(tc[k][1]);
            }
            k++;
        }

        // decide to append the rest to ans or dans
        if (tc[k].size()) {
            int qq = q(ans.back(), tc[k][0]);
            if (qq == 0 || qq == n-2) {
                while (tc[k].size()) {
                    ans.push_back(tc[k][0]);
                    k++;
                }
            } else {
                while (tc[k].size()) {
                    dans.push_back(tc[k][0]);
                    k++;
                }
            }
        }

        ans.insert(ans.end(), dans.rbegin(), dans.rend());
        answer(ans);
    }

    // n-n
    if (tc[n-2].size() == 2) {
        vector<int> ans, dans;
        ans.push_back(1);
        ans.push_back(tc[n-2][0]);
        dans.push_back(tc[n-2][1]);
        int k = n-3;
        while (tc[k].size()) {
            int qq = q(ans.back(), tc[k][0]);
            if (qq == 0 || qq == n-2) {
                ans.push_back(tc[k][0]);
                dans.push_back(tc[k][1]);
            } else {
                dans.push_back(tc[k][0]);
                ans.push_back(tc[k][1]);
            }
            k--;
        }

        // decide to append the rest to ans or dans
        if (tc[k].size()) {
            int qq = q(ans.back(), tc[k][0]);
            if (qq == 0 || qq == n-2) {
                while (tc[k].size()) {
                    ans.push_back(tc[k][0]);
                    k--;
                }
            } else {
                while (tc[k].size()) {
                    dans.push_back(tc[k][0]);
                    k--;
                }
            }
        }

        ans.insert(ans.end(), dans.rbegin(), dans.rend());
        answer(ans);
    }

    assert(false);

    return 0;
}