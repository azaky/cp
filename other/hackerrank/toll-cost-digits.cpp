#include <bits/stdc++.h>

using namespace std;

#define MAXN 200200

int n, m;
vector<pair<int,int>> adj[MAXN];
int vis[MAXN], vd[MAXN][10];
long long cd[10];
long long ans[10];
vector<int> vs;

void dfs(int v, int c) {
    if (vd[v][c]) return;
    if (!vis[v]) {
        vis[v] = 1;
        vs.push_back(v);
    }
    vd[v][c] = 1;
    cd[c]++;
    for (auto &p : adj[v]) {
        dfs(p.first, (c + p.second) % 10);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        adj[x].emplace_back(y, z % 10);
        adj[y].emplace_back(x, (1000 - z) % 10);
    }
    
    for (int r = 1; r <= n; ++r) {
        if (vis[r]) continue;
        memset(cd, 0, sizeof(cd));
        vs.clear();
        dfs(r, 0);
        vector<long long> tmp(10, 0);
        for (int f = 0; f < 10; ++f) {
            for (int t = 0; t < 10; ++t) {
                int c = (10 - f + t) % 10;
                tmp[c] += cd[f] * cd[t];
            }
        }
        for (int v : vs) {
            for (int f = 0; f < 10; ++f) {
                for (int t = 0; t < 10; ++t) {
                    int c = (10 - f + t) % 10;
                    tmp[c] -= vd[v][f] * vd[v][t];
                }
            }
        }
        int mul = 1;
        if (vd[r][1]) {
            mul = 10;
            assert(accumulate(vd[r], vd[r]+10, 0) == 10);
        } else if (vd[r][2]) {
            mul = 5;
            assert(accumulate(vd[r], vd[r]+10, 0) == 5);
        } else if (vd[r][5]) {
            mul = 2;
            assert(accumulate(vd[r], vd[r]+10, 0) == 2);
        } else {
            assert(accumulate(vd[r], vd[r]+10, 0) == 1);
        }
        for (int i = 0; i < 10; ++i) {
            assert(tmp[i] % mul == 0);
            ans[i] += tmp[i] / mul;
        }
    }
    
    for (int i = 0; i < 10; ++i) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
