#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Double hashing constants to prevent collisions
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const long long BASE1 = 313;
const long long BASE2 = 317;

const int MAXN = 100005;

long long p1[MAXN], p2[MAXN];

struct Node {
    long long val1[4];
    long long val2[4];
    int lazy;
    int len;
    
    Node() {
        for(int i = 0; i < 4; ++i) {
            val1[i] = val2[i] = 0;
        }
        lazy = 0;
        len = 0;
    }
};

Node tree[4 * MAXN];
string S;

// Merge two nodes dynamically maintaining the rolling hash property
Node merge(const Node& L, const Node& R) {
    Node res;
    res.len = L.len + R.len;
    for(int i = 0; i < 4; ++i) {
        res.val1[i] = (L.val1[i] * p1[R.len] + R.val1[i]) % MOD1;
        res.val2[i] = (L.val2[i] * p2[R.len] + R.val2[i]) % MOD2;
    }
    return res;
}

// Applies cyclic shift to a node's hashes
void apply(int node, int shift) {
    shift %= 4;
    if (shift < 0) shift += 4;
    
    long long temp1[4], temp2[4];
    for(int i = 0; i < 4; ++i) {
        temp1[(i + shift) % 4] = tree[node].val1[i];
        temp2[(i + shift) % 4] = tree[node].val2[i];
    }
    for(int i = 0; i < 4; ++i) {
        tree[node].val1[i] = temp1[i];
        tree[node].val2[i] = temp2[i];
    }
    tree[node].lazy = (tree[node].lazy + shift) % 4;
}

// Push down lazy values to children
void push_down(int node) {
    if (tree[node].lazy != 0) {
        apply(2 * node, tree[node].lazy);
        apply(2 * node + 1, tree[node].lazy);
        tree[node].lazy = 0;
    }
}

// Build segment tree
void build(int node, int l, int r) {
    if (l == r) {
        int c = S[l - 1] - 'a';
        tree[node].val1[c] = 1;
        tree[node].val2[c] = 1;
        tree[node].len = 1;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

// Type 1: Point update
void update_point(int node, int l, int r, int idx, int c) {
    if (l == r) {
        for(int i = 0; i < 4; ++i) tree[node].val1[i] = tree[node].val2[i] = 0;
        tree[node].val1[c] = 1;
        tree[node].val2[c] = 1;
        tree[node].lazy = 0;
        return;
    }
    push_down(node);
    int mid = l + (r - l) / 2;
    if (idx <= mid) update_point(2 * node, l, mid, idx, c);
    else update_point(2 * node + 1, mid + 1, r, idx, c);
    
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

// Type 2: Range update (Cyclic shift)
void update_range(int node, int l, int r, int ql, int qr, int shift) {
    if (ql <= l && r <= qr) {
        apply(node, shift);
        return;
    }
    push_down(node);
    int mid = l + (r - l) / 2;
    if (ql <= mid) update_range(2 * node, l, mid, ql, qr, shift);
    if (qr > mid) update_range(2 * node + 1, mid + 1, r, ql, qr, shift);
    
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

// Query hash node properties over range
Node query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[node];
    push_down(node);
    int mid = l + (r - l) / 2;
    
    if (qr <= mid) return query(2 * node, l, mid, ql, qr);
    if (ql > mid) return query(2 * node + 1, mid + 1, r, ql, qr);
    
    return merge(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    cin >> S;

    // Precompute polynomial hash bases
    p1[0] = 1; p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p1[i] = (p1[i - 1] * BASE1) % MOD1;
        p2[i] = (p2[i - 1] * BASE2) % MOD2;
    }

    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u;
            char c;
            cin >> u >> c;
            update_point(1, 1, n, u, c - 'a');
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            update_range(1, 1, n, l, r, 1);
        } else if (type == 3) {
            int l, r, p;
            cin >> l >> r >> p;
            
            Node res1 = query(1, 1, n, l, l + p - 1);
            Node res2 = query(1, 1, n, r, r + p - 1);

            pair<long long, long long> h1[4], h2[4];
            for(int i = 0; i < 4; ++i) {
                h1[i] = {res1.val1[i], res1.val2[i]};
                h2[i] = {res2.val1[i], res2.val2[i]};
            }
            
            // Sort both multi-sets to abstract character mapping away
            sort(h1, h1 + 4);
            sort(h2, h2 + 4);

            bool ok = true;
            for(int i = 0; i < 4; ++i) {
                if (h1[i] != h2[i]) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) cout << "YA\n";
            else cout << "TIDAK\n";
        }
    }

    return 0;
}