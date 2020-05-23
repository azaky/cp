#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <limits>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

/** Range Minimum/Maximum Query
 * minimum dependencies:
 * #include <vector>
 * using namespace std;
 * 
 * usage:
 * RMQ rmq(n);							// initialization. one-based, from 1 to n.
 * rmq.init(n);							// another way of above method
 *										// in above methods, all values will be reset to zero
 * RMQ rmq(a.begin(), a.end());			// init the rmq with values of a
 * rmq.init(a.begin(), a.end());		// another way of above method
 * rmq.update(pos, value);				// update the value in pos into value
 * rmq.updateRange(left, right, value); // update the value in range [left..right] to value
 * rmq.add(pos, value);					// add value to pos
 * rmq.addRange(left, right, value);	// add all value to all elements in [left..right]
 * int max = rmq.max(left, right);		// find max value in [left..right]
 * int min = rmq.min(left, right);		// find min value in [left..right]
 * int imax = rmq.idxMax(left, right);	// find the index of smallest value in [left..right]
 * int imin = rmq.idxMin(left, right);	// find the index of largest value in [left..right]
 */
struct RMQ {
	// data type to hold information in each node of the tree
	struct RMQInfo {
		RMQInfo() : imin(0), imax(0), vmin(0), vmax(0) {}
		int imin, imax; // index of smallest and largest values
		int vmin, vmax; // the smallest and largest value itself
		void combine(RMQInfo &left, RMQInfo &right) {
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
			build(vr, m+1, r);
			rmq[v].combine(rmq[vl], rmq[vr]);
		}
	}

	void addChange(int v, int l, int r, pair<int,int> c) {
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
				addChange(vr, m+1, r, change[v]);
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
				addChange(vr, m+1, r, make_pair(type, value));
			}
		}
		else if (l <= right && left <= r) {
			update(vl, l, m, left, right, value, type);
			update(vr, m+1, r, left, right, value, type);
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
				infoRight = query(vr, m+1, r, left, right);
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

int main() {
	int n, x, q, l, r;
	vector<int> a;

	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &x);
		a.PB(x);
	}

	RMQ rmq(ALL(a));
	// REP(i, n) rmq.update(i+1, a[i]);
	// printf("n = %d, nnode = %d\n", rmq.n, rmq.nnode);

	scanf("%d", &q);
	REP(i, q) {
		scanf("%d%d", &l, &r);
		printf("%d\n", rmq.min(l+1, r+1));
	}

	return 0;
}
