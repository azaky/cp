#include <bits/stdc++.h>
using namespace std;

#define INF 1000000001

struct RMQ
{
  RMQ() : n(0) {}
  RMQ(int n)
  {
    init(n);
  }
  template <class Iterator>
  RMQ(Iterator begin, Iterator end)
  {
    init(begin, end);
  }
  void init(int n, bool reset = true)
  {
    // this->n will be set to the smallest power of 2 greater/equal to n
    this->n = 1;
    while (this->n < n)
      this->n <<= 1;

    // resize the containers
    if (reset)
      a.clear();
    a.resize(this->n + 1, INF);
    rmq.resize(this->n << 1);
    change.resize(this->n << 1);

    // reset the value
    build(1, 1, this->n);
  }
  template <typename Iterator>
  void init(Iterator begin, Iterator end)
  {
    // insert values into a
    a.clear();
    a.push_back(0);
    while (begin != end)
    {
      a.push_back(*begin);
      begin++;
    }
    int n = a.size() - 1;

    init(n, false);
  }
  void build(int v, int l, int r)
  {
    if (l == r)
    {
      rmq[v] = a[l];
    }
    else
    {
      int vl = v << 1;
      int vr = vl | 1;
      int m = (l + r) >> 1;
      build(vl, l, m);
      build(vr, m + 1, r);
      rmq[v] = max(rmq[vl], rmq[vr]);
    }
  }

  void applyChanges(int v, int l, int r)
  {
    // printf("applyChanges [%d] (%d, %d)\n", v, l, r);
    if (!change[v]) return;

    rmq[v] = change[v];
    if (l < r)
    {
      int vl = v << 1;
      int vr = vl | 1;
      // propagate change to children
      change[vl] = change[vr] = change[v];
    }

    change[v] = 0;
  }

  void update(int pos, int value)
  {
    update(1, 1, n, pos, pos, value);
  }
  void updateRange(int left, int right, int value)
  {
    update(1, 1, n, left, right, value);
  }
  void update(int v, int l, int r, int left, int right, int value)
  {
    // printf("update [%d] (%d, %d): (%d, %d) -> %d\n", v, l, r, left, right, value);
    // apply changes to current node
    applyChanges(v, l, r);

    int vl = v << 1;
    int vr = vl | 1;
    int m = (l + r) >> 1;
    if (left <= l && r <= right)
    {
      rmq[v] = value;
      if (l < r)
      {
        change[vl] = change[vr] = value;
      }
    }
    else if (l <= right && left <= r)
    {
      update(vl, l, m, left, right, value);
      update(vr, m + 1, r, left, right, value);
      rmq[v] = max(rmq[vl], rmq[vr]);
    }
  }

  int querymax(int left, int right)
  {
    return query(1, 1, n, left, right);
  }
  int query(int v, int l, int r, int left, int right)
  {
    // printf("query [%d] (%d, %d): (%d, %d)\n", v, l, r, left, right);
    applyChanges(v, l, r);
    if (left <= l && r <= right)
    {
      return rmq[v];
    }
    else
    {
      int vl = v << 1;
      int vr = vl | 1;
      int m = (l + r) >> 1;
      int ql, qr;
      if (left <= m)
      {
        ql = query(vl, l, m, left, right);
        if (right <= m)
        {
          return ql;
        }
      }
      if (right > m)
      {
        qr = query(vr, m + 1, r, left, right);
        if (left > m)
        {
          return qr;
        }
      }
      return max(ql, qr);
    }
  }

  pair<int,int> ans(int x) {
    // printf("ans(%d)\n", x);
    int v = this->querymax(x, x);
    int l = queryl(1, 1, n, x, v);
    int r = queryr(1, 1, n, x, v);
    return make_pair(l, r);
  }

  // return smallest index > x having value > x
  // return -1 if all <= x
  // int queryr(int v, int l, int r, int x, int vx) {
  //   int q = _queryr(v, l, r, x, vx);
    // printf("queryr((%d, %d), (%d, %d)) = %d\n", l, r, x, vx, q);
  //   return q;
  // }
  int queryr(int v, int l, int r, int x, int vx)
  {
    applyChanges(v, l, r);
    if (r < x) {
      return -1;
    }
    else if (l < x) {
      int vl = v << 1;
      int vr = vl | 1;
      int m = (l + r) >> 1;

      int qr = queryr(vr, m + 1, r, x, vx);
      if (m < x) {
        return qr;
      }
      int ql = queryr(vl, l, m, x, vx);
      if (ql == -1) {
        return qr;
      } else {
        return ql;
      }
    }
    else if (rmq[v] <= vx) {
      return -1;
    }
    else if (l == r) {
      return l;
    }
    else {
      int vl = v << 1;
      int vr = vl | 1;
      int m = (l + r) >> 1;

      int ql = queryr(vl, l, m, x, vx);
      // printf("at (%d, %d), checking left (%d, %d)\n", l, r, 1, m);
      if (ql != -1) return ql;

      // printf("at (%d, %d), checking right\n", l, r);
      int qr = queryr(vr, m + 1, r, x, vx);
      return qr;
    }
  }

  // return largest index < x having value > x
  // return -1 if all <= x
  // int queryl(int v, int l, int r, int x, int vx)
  // {
  //   int q = _queryl(v, l, r, x, vx);
  //   // printf("queryl((%d, %d), (%d, %d)) = %d\n", l, r, x, vx, q);
  //   return q;
  // }
  int queryl(int v, int l, int r, int x, int vx)
  {
    applyChanges(v, l, r);
    if (l > x)
    {
      return -1;
    }
    else if (r > x)
    {
      int vl = v << 1;
      int vr = vl | 1;
      int m = (l + r) >> 1;

      int ql = queryl(vl, l, m, x, vx);
      if (m >= x)
      {
        return ql;
      }

      int qr = queryl(vr, m + 1, r, x, vx);
      if (qr == -1)
      {
        return ql;
      }
      else
      {
        return qr;
      }
    }
    else if (rmq[v] <= vx)
    {
      return -1;
    }
    else if (l == r)
    {
      return l;
    }
    else
    {
      int vl = v << 1;
      int vr = vl | 1;
      int m = (l + r) >> 1;

      int qr = queryl(vr, m + 1, r, x, vx);
      if (qr != -1)
        return qr;

      int ql = queryl(vl, l, m, x, vx);
      return ql;
    }
  }

  int n;
  vector<int> rmq;
  vector<int> change;
  vector<int> a;
};

#define MAXN 300300

int n, q, h[MAXN];

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &h[i]);
  }

  // printf("building...\n");
  RMQ rmq(h+1, h+n+1);
  // printf("finish building...\n");
  while (q--) {
    int t, x, y, z;
    scanf("%d", &t);
    // printf("task type %d\n", t);
    if (t == 1) {
      scanf("%d", &x);
      auto ans = rmq.ans(x);
      // printf("ans %d: (%d, %d)\n", x, ans.first, ans.second);
      if (ans.first == -1) {
        ans.first = 0;
      }
      if (ans.second == -1) {
        ans.second = n+1;
      }
      printf("%d\n", ans.second - ans.first - 1);
    } else if (t == 2) {
      scanf("%d%d", &x, &y);
      rmq.update(x, y);
    } else if (t == 3) {
      scanf("%d%d%d", &x, &y, &z);
      rmq.updateRange(x, y, z);
    } else assert(false);
  }
}