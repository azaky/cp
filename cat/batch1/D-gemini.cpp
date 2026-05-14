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
    if (scanf("%d", &ans) != 1) exit(0);
    if (ans == -1) exit(0); // Terminate on -1 to get WRONG-ANSWER instead of TIMELIMIT
    return queries[p] = ans;
}

void answer(vector<int> &ans) {
    assert((int)ans.size() == n);
    printf("!");
    for (int i : ans) printf(" %d", i);
    printf("\n");
    fflush(stdout);
    int x;
    if (scanf("%d", &x) != 1) exit(0);
    assert(x == 1);
    exit(0);
}

int t[MAXN];
vector<int> pair_nodes[MAXN];

int main() {
    if (scanf("%d", &n) != 1) return 0;

    // Phase 1: Query every vertex against Vertex 1
    // This takes (N - 1) queries.
    for (int i = 2; i <= n; i++) {
        t[i] = q(1, i);
        // Calculate the absolute distance 'k' from Vertex 1
        int k = min(t[i], n - 2 - t[i]);
        pair_nodes[k].push_back(i);
    }

    vector<int> L, R;
    L.push_back(1);
    R.push_back(1);

    // Initialize the two chains with the direct neighbors of Vertex 1 (k = 0)
    L.push_back(pair_nodes[0][0]);
    R.push_back(pair_nodes[0][1]);

    // Phase 2: Merge chains layer by layer
    int max_k = (n - 2) / 2;
    for (int k = 1; k <= max_k; k++) {
        if (pair_nodes[k].empty()) break;
        
        // If N is even, the last group has only 1 vertex exactly opposite to Vertex 1
        if (pair_nodes[k].size() == 1) {
            L.push_back(pair_nodes[k][0]);
        } else {
            int u = pair_nodes[k][0];
            int v = pair_nodes[k][1];
            
            // 1 Query per layer to check if 'u' attaches to the 'L' chain
            int qq = q(L.back(), u);
            if (qq == 0 || qq == n - 2) {
                L.push_back(u);
                R.push_back(v);
            } else {
                L.push_back(v);
                R.push_back(u);
            }
        }
    }

    // Construct the final perimeter array
    vector<int> ans;
    for (int x : L) ans.push_back(x);
    for (int i = (int)R.size() - 1; i >= 1; i--) { // Reverse R and skip the duplicate Vertex 1
        ans.push_back(R[i]);
    }

    answer(ans);
    return 0;
}