#include <bits/stdc++.h>
using namespace std;

// https://loj.ac/s/30698
// From https://codeforces.com/blog/entry/15296
namespace dsu {
  const int MAXN = 100010, MAXM = 500010, Inf = 0x3f3f3f3f;
  struct node {
    int id, rev, t, mint, mine;
    node* lson, * rson, * pa;
    inline bool isroot() {
      return (!pa) || !(pa->lson == this || pa->rson == this);
    }
    inline void ud() {
      mine = id, mint = t;

      if (lson && lson->mint < mint)
        mint = lson->mint, mine = lson->mine;

      if (rson && rson->mint < mint)
        mint = rson->mint, mine = rson->mine;
    }
    inline void fa_lazy() {
      if (rev) {
        swap(lson, rson);

        if (lson)
          lson->rev ^= 1;

        if (rson)
          rson->rev ^= 1;

        rev = 0;
      }
    }
    inline void fa_all() {
      if (!isroot())
        pa->fa_all();

      fa_lazy();
    }
  };
  vector<node> pool;
  vector<node*> nd;
  //LCT!!
  inline void rot(node* x) {
    node* p = x->pa;

    if (x == p->lson) {
      p->lson = x->rson;

      if (p->lson)
        p->lson->pa = p;

      x->pa = p->pa;

      if (!p->isroot() && p->pa->lson == p)
        p->pa->lson = x;
      else if (!p->isroot() && p->pa->rson == p)
        p->pa->rson = x;

      p->pa = x;
      x->rson = p;
    }
    else {
      p->rson = x->lson;

      if (p->rson)
        p->rson->pa = p;

      x->pa = p->pa;

      if (!p->isroot() && p->pa->lson == p)
        p->pa->lson = x;
      else if (!p->isroot() && p->pa->rson == p)
        p->pa->rson = x;

      p->pa = x;
      x->lson = p;
    }

    p->ud();
    x->ud();
  }
  inline void spaly(node* x) {
    while (!x->isroot()) {
      node* p = x->pa;

      if (p->isroot())
        rot(x);
      else if ((p->pa->lson == p) ^ (p->lson == x))
        rot(x), rot(x);
      else
        rot(p), rot(x);
    }
  }
  inline void access(node* x) {
    x->fa_all();
    spaly(x);

    if (x->pa) {
      access(x->pa);
      x->pa->rson = x;
      x->pa->ud();
      spaly(x);
    }

    x->rson = 0;
  }
  inline void mkr(node* x) {
    access(x);
    x->rev ^= 1;
  }
  inline void link(node* x, node* y) {
    mkr(x);
    x->pa = y;
  }
  inline void cut(node* x, node* y) {
    mkr(x);
    access(y);
    x->pa = 0;
  }
  inline int query(node* x, node* y) {
    mkr(x);
    access(y);

    if (x->isroot())
      return -1;

    spaly(x);

    if (y->pa != x)
      rot(y);

    if (x->rson == y)
      return y->lson->mine;
    else
      return y->rson->mine;
  }
  // t == 0: connect
  // t == 1: cut
  // t == 2: query
  struct qu {
    int t, u, v, d;
  };
  map<pair<int, int>, int> mmp; //edge->addtime

  vector<bool> dsu(int n, vector<qu> q) {
    int m = q.size();
    vector<bool> ans;

    // reset
    mmp.clear();
    pool.clear();
    nd.clear();
    pool.resize(n + m + 10);
    nd.resize(n + m + 10);

    for (int i = 1; i <= n; i++) {
      nd[i] = &pool[i];
      nd[i]->id = i;
      nd[i]->t = Inf;
      nd[i]->ud();
    }

    // somehow q is 1-indexed. shift? lol
    q.resize(m + 1);
    for (int i = m; i >= 1; i--) {
      q[i] = q[i - 1];
      q[i].d = 0;
    }

    for (int i = 1; i <= m; i++) {
      // scanf("%d%d%d", &q[i].t, &q[i].u, &q[i].v);

      if (q[i].u > q[i].v)
        swap(q[i].u, q[i].v);

      if (q[i].t == 0)
        mmp[make_pair(q[i].u, q[i].v)] = i;
      else if (q[i].t == 1)
        q[mmp[make_pair(q[i].u, q[i].v)]].d = i;
    }

    for (int i = 1; i <= m; i++)
      if (q[i].d == 0)
        q[i].d = Inf;

    for (int i = 1; i <= m; i++) {
      int res = query(nd[q[i].u], nd[q[i].v]);

      if (q[i].t == 0) {
        if (res != -1 && nd[res]->t < q[i].d) {
          cut(nd[q[res - n].u], nd[res]);
          cut(nd[q[res - n].v], nd[res]);
          nd[i + n] = &pool[i + n];
          nd[i + n]->id = i + n;
          nd[i + n]->t = q[i].d;
          nd[i + n]->ud();
          link(nd[q[i].u], nd[i + n]);
          link(nd[q[i].v], nd[i + n]);
        }
        else if (res == -1) {
          nd[i + n] = &pool[i + n];
          nd[i + n]->id = i + n;
          nd[i + n]->t = q[i].d;
          nd[i + n]->ud();
          link(nd[q[i].u], nd[i + n]);
          link(nd[q[i].v], nd[i + n]);
        }
      }
      else if (q[i].t == 1) {
        if (res != -1 && nd[res]->t == i) {
          cut(nd[q[res - n].u], nd[res]);
          cut(nd[q[res - n].v], nd[res]);
        }
      }
      else {
        if (res != -1)
          ans.push_back(true);
        else
          ans.push_back(false);
        // printf("q[(%d, %d)] = %d\n", q[i].u, q[i].v, res);
      }
    }
    return ans;
  }
} // namespace dsu

void solve(int tc) {
  int n, l;
  scanf("%d%d", &n, &l);
  vector<int> k(l);
  vector<vector<int>> s(l);
  for (int i = 0; i < l; i++) {
    scanf("%d", &k[i]);
    s[i].resize(k[i]);
    for (int j = 0; j < k[i]; j++) {
      scanf("%d", &s[i][j]);
    }
  }

  // edge count.
  map<pair<int, int>, int> edgec;
  for (int i = 0; i < l; i++) {
    for (int j = 1; j < k[i]; j++) {
      pair<int, int> edge = { s[i][j - 1], s[i][j] };
      if (edge.first > edge.second) swap(edge.first, edge.second);
      edgec[edge]++;
    }
  }

  // build query.
  vector<dsu::qu> q;
  auto addq = [&](int t, int u, int v) {
    dsu::qu qu;
    qu.t = t;
    qu.u = u;
    qu.v = v;
    q.push_back(qu);
  };
  // connect graph.
  for (auto const& edge : edgec) {
    dsu::qu qu;
    addq(0, edge.first.first, edge.first.second);
  }
  // query each lines.
  int totalask = 0;
  for (int i = 0; i < l; i++) {
    // cut line.
    for (int j = 1; j < k[i]; j++) {
      pair<int, int> edge = { s[i][j - 1], s[i][j] };
      if (edge.first > edge.second) swap(edge.first, edge.second);
      if (edgec[edge] == 1) {
        addq(1, edge.first, edge.second);
      }
    }
    // query line
    for (int j = 1; j < k[i]; j++) {
      pair<int, int> edge = { s[i][j - 1], s[i][j] };
      if (edge.first > edge.second) swap(edge.first, edge.second);
      addq(2, edge.first, edge.second);
      totalask++;
    }
    // reconnect line
    for (int j = 1; j < k[i]; j++) {
      pair<int, int> edge = { s[i][j - 1], s[i][j] };
      if (edge.first > edge.second) swap(edge.first, edge.second);
      if (edgec[edge] == 1) {
        addq(0, edge.first, edge.second);
      }
    }
  }

  auto res = dsu::dsu(n, q);
  assert(res.size() == totalask);
  int ires = 0;
  int ans = 0;
  for (int i = 0; i < l; i++) {
    int essential = false;
    for (int j = 0; j + 1 < k[i]; j++) {
      if (!res[ires + j]) {
        essential = true;
        // printf("line %d: cut %d-%d\n", i, s[i][j], s[i][j + 1]);
        break;
      }
    }
    ires += k[i] - 1;
    if (essential) {
      // printf("line %d essential!\n", i);
      ans++;
    }
  }
  printf("Case #%d: %d\n", tc, ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; itc++) {
    solve(itc);
  }
}