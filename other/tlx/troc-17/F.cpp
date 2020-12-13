#include <bits/stdc++.h>
using namespace std;

/** Range Minimum/Maximum Query
 * usage:
 * RMQ rmq(n);							// Initialize rmq with size n. All values will be set
 * rmq.init(n);							// to zero.
 * RMQ rmq(a.begin(), a.end());			// Initialize the rmq with values of a.
 * rmq.init(a.begin(), a.end());		// 
 * 
 * rmq.update(pos, value);				// Update the value in index pos.
 * rmq.updateRange(left, right, value); // Update the value in range [left..right].
 * rmq.add(pos, value);					// Add value at index pos.
 * rmq.addRange(left, right, value);	// Add value to all elements in [left..right].
 * 
 * int vmax = rmq.max(left, right);		// Find max value in [left..right].
 * int vmin = rmq.min(left, right);		// Find min value in [left..right].
 * int imax = rmq.idxMax(left, right);	// Find the index of largest value in [left..right].
 *										// If it is not unique, the leftmost index is returned.
 * int imin = rmq.idxMin(left, right);	// Find the index of smallest value in [left..right].
 *										// If it is not unique, the leftmost index is returned.
 * 
 * note:
 * * All indices are 1-based. Valid indices are from 1 to n.
 * * Initialization takes O(n), and all updates and queries take O(log(n)). Memory complexity
 *   will be O(n) (13*n to be exact).
 * * While using methods with range [left..right], make sure that left <= right and the range
 *   is within [1..n]. If the range is invalid, unexpected behavior may occur.
 */
struct RMQ
{
  // data type to hold information in each node of the tree
  struct RMQInfo
  {
    RMQInfo() : imin(0), imax(0), vmin(0), vmax(0) {}
    int imin, imax; // index of smallest and largest values
    int vmin, vmax; // the smallest and largest value itself
    void combine(RMQInfo &left, RMQInfo &right)
    {
      if (left.vmin <= right.vmin)
      {
        this->vmin = left.vmin;
        this->imin = left.imin;
      }
      else
      {
        this->vmin = right.vmin;
        this->imin = right.imin;
      }
      if (left.vmax >= right.vmax)
      {
        this->vmax = left.vmax;
        this->imax = left.imax;
      }
      else
      {
        this->vmax = right.vmax;
        this->imax = right.imax;
      }
    }
  };

  RMQ()
  {
    this->n = 0;
  }
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
    a.resize(this->n + 1);
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
      rmq[v].imin = rmq[v].imax = l;
      rmq[v].vmin = rmq[v].vmax = a[l];
    }
    else
    {
      int vl = v << 1;
      int vr = vl | 1;
      int m = (l + r) >> 1;
      build(vl, l, m);
      build(vr, m + 1, r);
      rmq[v].combine(rmq[vl], rmq[vr]);
    }
  }

  void addChange(int v, int l, int r, pair<int, int> c)
  {
    if (change[v].first == 0 || c.first == 1)
    {
      change[v] = c;
    }
    else if (c.first == 2)
    {
      change[v].second += c.second;
    }
  }
  void applyChanges(int v, int l, int r)
  {
    if (change[v].first)
    {
      int vl = v << 1;
      int vr = vl | 1;
      int m = (l + r) >> 1;
      // apply update
      if (change[v].first == 1)
      {
        rmq[v].vmin = rmq[v].vmax = change[v].second;
        rmq[v].imin = rmq[v].imax = l;
      }
      // apply add
      else if (change[v].first == 2)
      {
        rmq[v].vmin += change[v].second;
        rmq[v].vmax += change[v].second;
      }
      if (l < r)
      {
        // propagate change to children
        addChange(vl, l, m, change[v]);
        addChange(vr, m + 1, r, change[v]);
      }
      // reset
      change[v].first = 0;
    }
  }

  void update(int pos, int value)
  {
    update(1, 1, n, pos, pos, value, 1);
  }
  void updateRange(int left, int right, int value)
  {
    update(1, 1, n, left, right, value, 1);
  }
  void add(int pos, int value)
  {
    update(1, 1, n, pos, pos, value, 2);
  }
  void addRange(int left, int right, int value)
  {
    update(1, 1, n, left, right, value, 2);
  }
  void update(int v, int l, int r, int left, int right, int value, int type)
  {
    // apply changes to current node
    applyChanges(v, l, r);

    int vl = v << 1;
    int vr = vl | 1;
    int m = (l + r) >> 1;
    if (left <= l && r <= right)
    {
      if (type == 1)
      {
        rmq[v].imax = rmq[v].imin = l;
        rmq[v].vmax = rmq[v].vmin = value;
      }
      else if (type == 2)
      {
        rmq[v].vmax += value;
        rmq[v].vmin += value;
      }
      if (l < r)
      {
        addChange(vl, l, m, make_pair(type, value));
        addChange(vr, m + 1, r, make_pair(type, value));
      }
    }
    else if (l <= right && left <= r)
    {
      update(vl, l, m, left, right, value, type);
      update(vr, m + 1, r, left, right, value, type);
      rmq[v].combine(rmq[vl], rmq[vr]);
    }
  }

  int min(int left, int right)
  {
    return query(1, 1, n, left, right).vmin;
  }
  int max(int left, int right)
  {
    return query(1, 1, n, left, right).vmax;
  }
  int idxMin(int left, int right)
  {
    return query(1, 1, n, left, right).imin;
  }
  int idxMax(int left, int right)
  {
    return query(1, 1, n, left, right).imax;
  }
  RMQInfo query(int v, int l, int r, int left, int right)
  {
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
      RMQInfo infoLeft, infoRight, result;
      if (left <= m)
      {
        infoLeft = query(vl, l, m, left, right);
        if (right <= m)
        {
          return infoLeft;
        }
      }
      if (right > m)
      {
        infoRight = query(vr, m + 1, r, left, right);
        if (left > m)
        {
          return infoRight;
        }
      }
      result.combine(infoLeft, infoRight);
      return result;
    }
  }

  int n;
  vector<RMQInfo> rmq;
  vector<pair<int, int>> change;
  vector<int> a;
};

#define MAXN 200200
int n, d, q, a[MAXN], s[MAXN], b[MAXN];
char plan[MAXN];

int main() {
  scanf("%d%d", &n, &d);
  scanf("%s", plan);
  for (int i = 0; i < n; ++i) {
    a[i+1] = plan[i] - '0';
    s[i+1] = s[i] + a[i+1];
  }
  for (int i = 1; i <= n; ++i) {
    b[i] = s[i];
    if (i >= d) b[i] -= s[i-d];
  }
  RMQ rmq(b+1, b+n+1);

  scanf("%d", &q);
  while (q--) {
    int t, k;
    scanf("%d%d", &t, &k);
    if (t == 1) {
      rmq.addRange(k, min(k + d - 1, n), 1 - 2 * a[k]);
      a[k] = 1-a[k];
    } else {
      // find leftmost idx s.t. rmq[x] > k
      if (rmq.max(1, n) <= k) {
        puts("-1");
        continue;
      }
      int l = 1, r = n;
      while (l < r) {
        int mid = (l + r) / 2;
        int maxmid = rmq.max(1, mid);
        if (maxmid <= k) {
          l = mid+1;
        } else {
          r = mid;
        }
      }
      assert(rmq.max(l, l) > k);
      if (l > 1) assert(rmq.max(1, l-1) <= k);
      printf("%d\n", l);
    }
  }
}
