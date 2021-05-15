#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
struct RMQ {
  // data type to hold information in each node of the tree
  struct RMQInfo {
    RMQInfo() : imin(0), imax(0), vmin(0), vmax(0) {}
    int imin, imax; // index of smallest and largest values
    int vmin, vmax; // the smallest and largest value itself
    void combine(RMQInfo& left, RMQInfo& right) {
      if (left.vmin < right.vmin) {
        this->vmin = left.vmin;
        this->imin = left.imin;
      }
      else {
        this->vmin = right.vmin;
        this->imin = right.imin;
      }
      if (left.vmax > right.vmax) {
        this->vmax = left.vmax;
        this->imax = left.imax;
      }
      else {
        this->vmax = right.vmax;
        this->imax = right.imax;
      }
    }
  };

  RMQ() {
    this->n = 0;
  }
  RMQ(int n) {
    init(n);
  }
  template <class Iterator> RMQ(Iterator begin, Iterator end) {
    init(begin, end);
  }
  void init(int n, bool reset = true) {
    // this->n will be set to the smallest power of 2 greater/equal to n
    this->n = 1;
    while (this->n < n) this->n <<= 1;

    // resize the containers
    if (reset) a.clear();
    a.resize(this->n + 1);
    rmq.resize(this->n << 1);
    change.resize(this->n << 1);

    // reset the value
    build(1, 1, this->n);
  }
  template <typename Iterator> void init(Iterator begin, Iterator end) {
    // insert values into a
    a.clear();
    a.push_back(0);
    while (begin != end) {
      a.push_back(*begin);
      begin++;
    }
    int n = a.size() - 1;

    init(n, false);
  }
  void build(int v, int l, int r) {
    if (l == r) {
      rmq[v].imin = rmq[v].imax = l;
      rmq[v].vmin = rmq[v].vmax = a[l];
    }
    else {
      int vl = v << 1;
      int vr = vl | 1;
      int m = (l + r) >> 1;
      build(vl, l, m);
      build(vr, m + 1, r);
      rmq[v].combine(rmq[vl], rmq[vr]);
    }
  }

  void addChange(int v, int l, int r, pair<int, int> c) {
    if (change[v].first == 0 || c.first == 1) {
      change[v] = c;
    }
    else if (c.first == 2) {
      change[v].second += c.second;
    }
  }
  void applyChanges(int v, int l, int r) {
    if (change[v].first) {
      int vl = v << 1;
      int vr = vl | 1;
      int m = (l + r) >> 1;
      // apply update
      if (change[v].first == 1) {
        rmq[v].vmin = rmq[v].vmax = change[v].second;
        rmq[v].imin = rmq[v].imax = l;
      }
      // apply add
      else if (change[v].first == 2) {
        rmq[v].vmin += change[v].second;
        rmq[v].vmax += change[v].second;
      }
      if (l < r) {
        // propagate change to children
        addChange(vl, l, m, change[v]);
        addChange(vr, m + 1, r, change[v]);
      }
      // reset
      change[v].first = 0;
    }
  }

  void update(int pos, int value) {
    update(1, 1, n, pos, pos, value, 1);
  }
  void updateRange(int left, int right, int value) {
    update(1, 1, n, left, right, value, 1);
  }
  void add(int pos, int value) {
    update(1, 1, n, pos, pos, value, 2);
  }
  void addRange(int left, int right, int value) {
    update(1, 1, n, left, right, value, 2);
  }
  void update(int v, int l, int r, int left, int right, int value, int type) {
    // apply changes to current node
    applyChanges(v, l, r);

    int vl = v << 1;
    int vr = vl | 1;
    int m = (l + r) >> 1;
    if (left <= l && r <= right) {
      if (type == 1) {
        rmq[v].imax = rmq[v].imin = l;
        rmq[v].vmax = rmq[v].vmin = value;
      }
      else if (type == 2) {
        rmq[v].vmax += value;
        rmq[v].vmin += value;
      }
      if (l < r) {
        addChange(vl, l, m, make_pair(type, value));
        addChange(vr, m + 1, r, make_pair(type, value));
      }
    }
    else if (l <= right && left <= r) {
      update(vl, l, m, left, right, value, type);
      update(vr, m + 1, r, left, right, value, type);
      rmq[v].combine(rmq[vl], rmq[vr]);
    }
  }

  int min(int left, int right) {
    return query(1, 1, n, left, right).vmin;
  }
  int max(int left, int right) {
    return query(1, 1, n, left, right).vmax;
  }
  int idxMin(int left, int right) {
    return query(1, 1, n, left, right).imin;
  }
  int idxMax(int left, int right) {
    return query(1, 1, n, left, right).imax;
  }
  RMQInfo query(int v, int l, int r, int left, int right) {
    applyChanges(v, l, r);
    if (left <= l && r <= right) {
      return rmq[v];
    }
    else {
      int vl = v << 1;
      int vr = vl | 1;
      int m = (l + r) >> 1;
      RMQInfo infoLeft, infoRight, result;
      if (left <= m) {
        infoLeft = query(vl, l, m, left, right);
        if (right <= m) {
          return infoLeft;
        }
      }
      if (right > m) {
        infoRight = query(vr, m + 1, r, left, right);
        if (left > m) {
          return infoRight;
        }
      }
      result.combine(infoLeft, infoRight);
      return result;
    }
  }

  int n;
  vector<RMQInfo> rmq;
  vector<pair<int, int> > change;
  vector<int> a;
};

/** Extended Euclid | returns <x,y> where ax + by = gcd(a,b) **/
/* complexity: O(min(log(a),log(b))) */
pair<ll, ll> extendedEuclid(ll a, ll b) {
  ll x = 0, y = 1, lastx = 1, lasty = 0;
  // maintain two equations:
  // a_i = a * lastx + b * lasty
  // b_i = a * x     + b * y
  while (b != 0) {
    ll quotient = a / b;
    /* (a, b) = (b, a mod b) */
    ll temp = a;
    a = b;
    b = temp % b;
    /* (x, lastx) = (lastx - quotient*x, x) */
    temp = x;
    x = lastx - quotient * x;
    lastx = temp;
    /* (y, lasty) = (lasty - quotient*y, y) */
    temp = y;
    y = lasty - quotient * y;
    lasty = temp;
  }
  return make_pair(lastx, lasty);
}

/** Multiplicative Inverse | returns a^-1 mod m **/
ll multiplicativeInverse(ll a, ll m) {
  /* if m is prime, return power(a,m-2,m); */
  pair<ll, ll> xy = extendedEuclid(a, m);
  return ((xy.first % m) + m) % m;
}


#define MOD 1000000007LL
#define MAXN 100000

ll f[MAXN+1];

ll C(int n, int k) {
  ll c = f[n];
  c *= multiplicativeInverse(f[k], MOD);
  c %= MOD;
  c *= multiplicativeInverse(f[n-k], MOD);
  c %= MOD;
  return c;
}

int n;
int v[MAXN+1];
RMQ rmq;

ll calc(int l, int r) { // [l, r]
  if (l >= r) return 1;
  int i = rmq.idxMin(l, r);
  assert(l <= i && i <= r);
  ll c = calc(l, i-1) * calc(i+1, r);
  c %= MOD;
  c *= C(r-l, i-l);
  c %= MOD;
  return c;
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &v[i]);
  }
  bool valid = true;
  for (int i = 1; i <= n; ++i) {
    if (v[i] > v[i-1]+1) {
      valid = false;
    }
  }
  if (!valid) {
    puts("0");
    return;
  }

  rmq.init(v+1, v+n+1);
  printf("%lld\n", calc(1, n));
}

int main() {
  f[0] = 1;
  for (int i = 1; i <= MAXN; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}