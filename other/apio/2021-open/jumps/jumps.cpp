#include "jumps.h"

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
struct RMQ {
  // data type to hold information in each node of the tree
  struct RMQInfo {
    RMQInfo() : imin(0), imax(0), vmin(0), vmax(0) {}
    int imin, imax; // index of smallest and largest values
    int vmin, vmax; // the smallest and largest value itself
    void combine(RMQInfo& left, RMQInfo& right) {
      if (left.vmin <= right.vmin) {
        this->vmin = left.vmin;
        this->imin = left.imin;
      }
      else {
        this->vmin = right.vmin;
        this->imin = right.imin;
      }
      if (left.vmax >= right.vmax) {
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

int N;
vector<int> H;
vector<vector<int>> L, R, high, low, rhigh, rlow;

RMQ rmq;

vector<int> vis, dis;

bool is_subtask1 = false;

vector<vector<int>> adj;

void init(int _N, vector<int> _H) {
  N = _N;
  H = _H;
  rmq.init(H.begin(), H.end());

  L.resize(N);
  R.resize(N);
  high.resize(N);
  low.resize(N);
  rhigh.resize(N);
  rlow.resize(N);
  vis.resize(N);
  dis.resize(N);

  vector<int> s;
  for (int i = 0; i < N; ++i) {
    while (!s.empty() && H[s.back()] < H[i]) {
      R[s.back()].push_back(i);
      s.pop_back();
    }
    s.push_back(i);
  }
  while (!s.empty()) {
    R[s.back()].push_back(-1);
    s.pop_back();
  }

  for (int i = N-1; i >= 0; --i) {
    while (!s.empty() && H[s.back()] < H[i]) {
      L[s.back()].push_back(i);
      s.pop_back();
    }
    s.push_back(i);
  }
  while (!s.empty()) {
    L[s.back()].push_back(-1);
    s.pop_back();
  }

  for (int d = 1; d <= 20; ++d) {
    for (int i = 0; i < N; ++i) {
      if (R[i][d-1] != -1) {
        R[i].push_back(R[R[i][d-1]][d-1]);
      } else {
        R[i].push_back(-1);
      }
      if (L[i][d-1] != -1) {
        L[i].push_back(L[L[i][d-1]][d-1]);
      } else {
        L[i].push_back(-1);
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    vector<int> neighbors = {L[i][0], R[i][0]};
    sort(neighbors.begin(), neighbors.end(), [&](int a, int b) -> bool {
      if (a == -1 || b == -1) return b == -1;
      return H[a] < H[b];
    });
    low[i].push_back(neighbors[0]);
    high[i].push_back(neighbors[1]);
    if (high[i].back() != -1) {
      rhigh[i].push_back(max(neighbors[0], neighbors[1]));
    } else {
      rhigh[i].push_back(-1);
    }
  }

  for (int d = 1; d <= 20; ++d) {
    for (int i = 0; i < N; ++i) {
      if (high[i][d-1] != -1) {
        high[i].push_back(high[high[i][d-1]][d-1]);
        rhigh[i].push_back(max(rhigh[i][d-1], rhigh[high[i][d-1]][d-1]));
      } else {
        high[i].push_back(-1);
        rhigh[i].push_back(-1);
      }
      if (low[i][d-1] != -1) {
        low[i].push_back(low[low[i][d-1]][d-1]);
      } else {
        low[i].push_back(-1);
      }
    }
  }
}

int minimum_jumps(int A, int B, int C, int D) {
  int maxr = rmq.max(C + 1, D + 1);
  if (rmq.max(B+1, C) > maxr) {
    return -1;
  }

  // printf("(%d, %d) -> (%d, %d)\n", A, B, C, D);

  int l = B;
  for (int i = 20; i >= 0; --i) {
    if (L[l][i] == -1) continue;
    if (L[l][i] < A) continue;
    if (H[L[l][i]] > maxr) continue;
    l = L[l][i];
  }

  // printf("l = %d, H = %d\n", l, H[l]);
  assert(H[l] == rmq.max(l+1, B+1));
  assert(H[l] < maxr);
  assert(A <= l && l <= B);

  // according to editorial: jump high until maxr, then jump right
  int ans = 0;
  // high jumps
  for (int i = 20; i >= 0; --i) {
    if (high[l][i] == -1) continue;
    if (rhigh[l][i] >= C) continue;
    if (H[high[l][i]] >= maxr) continue;
    l = high[l][i];
    ans += 1 << i;
  }
  // printf("l = %d, H = %d\n", l, H[l]);
  assert(l <= D);
  // right jumps
  if (l < C) {
    for (int i = 20; i >= 0; --i) {
      if (R[l][i] == -1) continue;
      if (R[l][i] >= C) continue;
      l = R[l][i];
      ans += 1 << i;
    }
    assert(C <= R[l][0] && R[l][0] <= D);
    ans++;
  }

  return ans;


  if (L[l][0] == -1 || H[L[l][0]] > maxr) {
    // start from l, greedily to [C, D]
    // first, jump the furthest to right < C
    // then, make 1 jump
    int ans = 0;
    for (int i = 20; i >= 0; --i) {
      if (R[l][i] == -1) continue;
      if (R[l][i] >= C) continue;
      l = R[l][i];
      ans += 1 << i;
    }
    assert(C <= R[l][0] && R[l][0] <= D);
    return ans + 1;
  }

  queue<int> q;
  q.emplace(l);
  dis[l] = 0;
  vis[l] = 1;
  vector<int> visited;

  int best = -1;

  while (!q.empty()) {
    int x = q.front(); q.pop();
    visited.push_back(x);
    if (best != -1) continue;

    if (C <= x) {
      assert(x <= D);
      best = dis[x];
    }

    int l = L[x][0], r = R[x][0];
    if (l != -1 && !vis[l] && H[l] < maxr) {
      vis[l] = 1;
      dis[l] = dis[x] + 1;
      q.emplace(l);
    }
    if (r != -1 && !vis[r] && r <= D) {
      vis[r] = 1;
      dis[r] = dis[x] + 1;
      q.emplace(r);
    }
  }

  for (int x : visited) vis[x] = dis[x] = 0;

  return best;
}
