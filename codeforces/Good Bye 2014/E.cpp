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

#define MAXN 200200
int bit[MAXN], n, p[MAXN], l[MAXN], rmq[MAXN << 2];
int q, x[MAXN], y[MAXN], span[MAXN], ans[MAXN];
vector<int> queries[MAXN];

void update_bit(int k, int v) {
	for (int x = k; x < n; x += (x & -x)) {
		bit[x] += v;
	}
}
int query_bit(int k) {
	int ret = 0;
	for (int x = k; x > 0; x -= (x & -x)) {
		ret += bit[x];
	}
	return ret;
}
int query_bit(int x, int y) {
	return query_bit(y) - query_bit(x-1);
}

void update_rmq(int v, int l, int r, int x, int value) {
	if (r < x || x < l) return;
	if (l == r) {
		rmq[v] = value;
	}
	else {
		int vl = v<<1;
		int vr = vl|1;
		int m = (l+r)>>1;
		update_rmq(vl, l, m, x, value);
		update_rmq(vr, m+1, r, x, value);
		rmq[v] = max(rmq[vl], rmq[vr]);
	}
}
int query_rmq(int v, int l, int r, int x, int y) {
	if (r < x || y < l) return 0;
	if (x <= l && r <= y) {
		return rmq[v];
	}
	else {
		int vl = v<<1;
		int vr = vl|1;
		int m = (l+r)>>1;
		return max(query_rmq(vl, l, m, x, y), query_rmq(vr, m+1, r, x, y));
	}
}

struct RMQ {
	struct RMQInfo {
		int imin, imax; // index of smallest and largest values;
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
	void init(int n) {
		// this->n will be set to the smallest power of 2 greater/equal to n
		this->n = 1;
		while (this->n < n) this->n <<= 1;

		// resize the containers
		a.clear();
		a.resize(this->n + 1);
		rmq.resize(this->n << 1);

		// reset the value
		build(1, 1, this->n);
	}
	template <class Iterator> void init(Iterator begin, Iterator end) {
		// insert values into a
		a.clear();
		a.push_back(0);
		while (begin != end) {
			a.push_back(*begin);
			begin++;
		}
		int n = a.size() - 1;

		// this->n will be set to the smallest power of 2 greater/equal to n
		this->n = 1;
		while (this->n < n) this->n <<= 1;

		// resize the containers
		a.resize(this->n + 1);
		rmq.resize(this->n << 1);

		// reset the value
		build(1, 1, this->n);
	}
	void build(int v, int l, int r) {
		if (l == r) {
			rmq[v].imin = rmq[v].imax = l;
		}
		else {
			int vl = v << 1;
			int vr = vl | 1;
			int m = (l + r) >> 1;
			build(vl, l, m);
			build(vr, m+1, r);
			rmq[v].imin = (a[rmq[vl].imin] < a[rmq[vr].imin]) ? rmq[vl].imin : rmq[vr].imin;
			rmq[v].imax = (a[rmq[vl].imax] > a[rmq[vr].imax]) ? rmq[vl].imax : rmq[vr].imax;
		}
	}

	void update(int pos, int value) {
		a[pos] = value;
		update(1, 1, n, pos, value);
	}
	void update(int v, int l, int r, int pos, int value) {
		if (l == r) {
			rmq[v].imax = rmq[v].imin = pos;
		}
		else {
			int vl = v << 1;
			int vr = vl | 1;
			int m = (l + r) >> 1;
			if (pos <= m) {
				update(vl, l, m, pos, value);
			}
			if (m+1 <= pos) {
				update(vr, m+1, r, pos, value);
			}
			rmq[v].imin = (a[rmq[vl].imin] < a[rmq[vr].imin]) ? rmq[vl].imin : rmq[vr].imin;
			rmq[v].imax = (a[rmq[vl].imax] > a[rmq[vr].imax]) ? rmq[vl].imax : rmq[vr].imax;
		}
	}

	int min(int left, int right) {
		RMQInfo result = query(1, 1, n, left, right);
		return a[result.imin];
	}
	int max(int left, int right) {
		RMQInfo result = query(1, 1, n, left, right);
		return a[result.imax];
	}
	int idxMin(int left, int right) {
		RMQInfo result = query(1, 1, n, left, right);
		return result.imin;
	}
	int idxMax(int left, int right) {
		RMQInfo result = query(1, 1, n, left, right);
		return result.imax;
	}
	RMQInfo query(int v, int l, int r, int left, int right) {
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
			result.imin = (a[infoLeft.imin] < a[infoRight.imin]) ? infoLeft.imin : infoRight.imin;
			result.imax = (a[infoLeft.imax] > a[infoRight.imax]) ? infoLeft.imax : infoRight.imax;
			return result;
		}
	}

	int n;
	vector<RMQInfo> rmq;
	vector<int> a;
};


int main() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i], &l[i]);
	scanf("%d", &q);
	REP(i, q) {
		scanf("%d%d", &x[i], &y[i]);
		x[i]--; y[i]--;
		queries[x[i]].PB(i);
	}

	// first initialization
	int temp = p[0] + l[0];
	FOR(i, 1, n-1) {
		if (temp >= p[i]) {
			update_bit(i, 0);
		}
		else {
			update_bit(i, p[i] - temp);
		}
		MX(temp, p[i] + l[i]);
	}

	// calculates "real" span
	RMQ rmqz(n);
	span[n-1] = p[n-1] + l[n-1];
	rmqz.update(n, span[n-1]);
	// update_rmq(1, 0, n-1, n-1, span[n-1]);
	REPD(i, n-1) {
		int reach = p[i] + l[i];
		if (reach < p[i+1]) {
			span[i] = reach;
		}
		else {
			int r = lower_bound(p, p+n, reach+1) - p;
			r--;
			// span[i] = query_rmq(1, 0, n-1, i+1, r);
			span[i] = rmqz.max(i+2, r+1);
			MX(span[i], reach);
		}
		// update_rmq(1, 0, n-1, i, span[i]);
		rmqz.update(i+1, span[i]);
	}

	// REP(i, n) printf("span[%d] = %d\n", i, span[i]);

	REP(i, n) {
		// printf("start: %d\n", i);
		// FOR(j, 1, n-1) printf("%2d ", query_bit(j, j)); puts("");
		FORIT(it, queries[i]) {
			if (x[*it] == y[*it]) {
				ans[*it] = 0;
			}
			else {
				ans[*it] = query_bit(x[*it]+1, y[*it]);
			}
		}

		// now how to update the bit ...
		if (i == n-1) continue;
		if (span[i+1] >= p[i] + l[i]) continue;

		int lp = lower_bound(p, p+n, span[i+1]) - p;
		int rp = lower_bound(p, p+n, p[i]+l[i]) - p;
		if (rp == n) rp--;

		// printf("update from %d to %d\n", lp, rp);

		temp = span[i+1];
		FOR(j, lp, rp) {
			if (temp >= p[j]) {
				update_bit(j, 0 - query_bit(j, j));
			}
			else {
				update_bit(j, (p[j] - temp) - query_bit(j, j));
			}
			MX(temp, p[j] + l[j]);
		}
	}

	REP(i, q) {
		printf("%d\n", ans[i]);
	}


	return 0;
}