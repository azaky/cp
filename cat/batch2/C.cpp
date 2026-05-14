#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> adj[200200];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        x--, y--;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }

    // it has to be a star
    if (adj[0].size() != n-1) {
        puts("-1");
        return 0;
    }

    vector<int> cheapestCost(n);
    set<pair<int,int>> unexplored; // <cheapestCost, i>
    for (auto e : adj[0]) {
        cheapestCost[e.first] = e.second;
        unexplored.emplace(e.second, e.first);
    }
    int ans = 0;
    while (!unexplored.empty()) {
        auto x = unexplored.begin();
        int u = x->second;
        unexplored.erase(x);
        // printf("u = %d\n", u);
        for (auto e : adj[u]) {
            int v = e.first, w = e.second;
            // printf("\tchecking (u,v) = (%d,%d)\n", u, v);
            if (unexplored.count(make_pair(cheapestCost[v], v))) {
                // printf("\tin unexplored: v = %d\n", v);
                if (w < cheapestCost[v]) {
                    // printf("\terasing edge");
                    // this is not allowed, as it will make cheapestCost[v] != shortestPath[v]
                    // so erase this edge
                    ans++;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}