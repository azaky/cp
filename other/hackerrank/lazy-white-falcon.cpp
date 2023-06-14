#include <bits/stdc++.h>

using namespace std;

#define MAXN 100100

int n, q;
vector<int> adj[MAXN];
int prel[MAXN], prer[MAXN];

int T[MAXN], L[MAXN], P[MAXN][20];
void LCApre() {
  int i, j;

  //we initialize every element in P with -1
  for (i = 0; i < n; i++)
    for (j = 0; 1 << j < n; j++)
      P[i][j] = -1;

  //the first ancestor of every node i is T[i]
  for (i = 0; i < n; i++)
    P[i][0] = T[i];

  //bottom up dynamic programing
  for (j = 1; 1 << j < n; j++)
    for (i = 0; i < n; i++)
      if (P[i][j - 1] != -1)
        P[i][j] = P[P[i][j - 1]][j - 1];
}
int LCAquery(int p, int q) {
  int log, i;

  //if p is situated on a higher level than q then we swap them
  if (L[p] < L[q]) swap(p, q);

  //we compute the value of [log(L[p)]
  for (log = 1; 1 << log <= L[p]; log++);
  log--;

  //we find the ancestor of node p situated on the same level
  //with q using the values in P
  for (i = log; i >= 0; i--)
    if (L[p] - (1 << i) >= L[q])
      p = P[p][i];

  if (p == q) return p;

  //we compute LCA(p, q) using the values in P
  for (i = log; i >= 0; i--)
    if (P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q = P[q][i];

  return T[p];
}

void dfs(int v, int p, int depth) {
    T[v] = p;
    L[v] = depth;
    static int i = 0;
    i++;
    prel[v] = i;
    int sz = 0;
    for (int c : adj[v]) if (c != p) {
        dfs(c, v, depth+1);
        sz += prer[c] - prel[c] + 1;
    }
    prer[v] = i;
    assert(sz == prer[v] - prel[v]);
}

int tree[MAXN << 2];
int val[MAXN];

void update(int v, int vl, int vr, int l, int r, int value) {
    if (r < vl || vr < l) return;
    if (l <= vl && vr <= r) {
        tree[v] += value;
    } else {
        int mid = (vl + vr) / 2;
        update(v << 1, vl, mid, l, r, value);
        update((v << 1) + 1, mid+1, vr, l, r, value);
    }
}

int query(int v, int vl, int vr, int x) {
    if (x < vl || vr < x) return 0;
    if (vl == vr) {
        return tree[v];
    } else {
        int mid = (vl + vr) / 2;
        return tree[v] + query(v << 1, vl, mid, x) + query((v << 1) + 1, mid+1, vr, x);
    }
}

void dump(int v, int vl, int vr) {
    printf("v[%d] = [%d..%d] = %d\n", v, vl, vr, tree[v]);
    if (vl == vr) return;
    int mid = (vl + vr) / 2;
    dump(v << 1, vl, mid);
    dump((v << 1) + 1, mid+1, vr);
}

template<typename T> class BIT {
public:
  BIT(int n): v(vector<T>(n+1)), n(n) {}
  T sum(int k) {
    T s = 0;
    for (int i = k; i > 0; i -= (i & -i)) {
      s += this->v[i];
    }
    return s;
  }
  T sum(int l, int r) {
    return this->sum(r) - this->sum(l-1);
  }
  void update(int k, T v) {
    for (int i = k; i <= this->n; i += (i & -i)) {
      this->v[i] += v;
    }
  }
private:
  vector<T> v;
  int n;
};

int brute(int x) {
  int sum = 0;
  while (x) {
    sum += val[x];
    x = T[x];
  };
  return sum + val[x];
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0, -1, 0);
    LCApre();
    // for (int i = 0; i < n; ++i) {
    //     printf("%d: %d..%d\n", i, prel[i], prer[i]);
    // }
    BIT<int> bit(n+1);

    auto check = [&](int x, string label) {
      int ansx = query(1, 1, n, prel[x]);
      if (ansx != brute(x)) {
        printf("%s = %d, ansx = %d, brute = %d\n", label.c_str(), x, ansx, brute(x));
        int v = x;
        while (v) {
          printf("%d (%d) -> ", v, val[v]);
          v = T[v];
        };
        printf("%d (%d)\n", 0, val[0]);
        exit(1);
      }
    };

    for (int iq = 0; iq < q; ++iq) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            int diff = y - val[x];
            update(1, 1, n, prel[x], prer[x], diff);
            // bit.update(prer[x]+1, -diff);
            // bit.update(prel[x], diff);
            val[x] = y;
        } else {
            int lca = LCAquery(x, y);
            // int ans = query(1, 1, n, prel[x]) + query(1, 1, n, prel[y]) - query(1, 1, n, prel[lca]);
            int ansx = query(1, 1, n, prel[x]);
            int ansy = query(1, 1, n, prel[y]);
            int anslca = query(1, 1, n, prel[lca]);
            int ans = ansx + ansy - 2 * anslca + val[lca];
            check(x, "x");
            check(y, "y");
            check(lca, "lca");
            int ex = 0, ey = 0;
            for (int v = x; v != lca; v = T[v]) {
              ex += val[v];
            }
            for (int v = y; v != lca; v = T[v]) {
              ey += val[v];
            }
            assert(ex == ansx - anslca);
            assert(ey == ansy - anslca);
            ansx - anslca + ansy - anslca + val[lca];
            // assert(ex + ey + val[lca] == ans);
            // int ans = bit.sum(prel[x]) + bit.sum(prel[y]) - bit.sum(prel[lca]);
            // printf("lca = %d\n", lca);
            // printf("x(%d -> %d): %d\n", x, prel[x], query(1, 1, n, prel[x]));
            // printf("y(%d -> %d): %d\n", y, prel[y], query(1, 1, n, prel[y]));
            // printf("lca(%d -> %d): %d\n", lca, prel[lca], query(1, 1, n, prel[lca]));
            printf("%d\n", ans);
        }
        // dump(1, 1, n);
        // for (int i = 1; i <= n; ++i) {
        //   printf("bit[%d] = %d\n", i, bit.sum(i, i));
        // }
    }
    
    return 0;
}
