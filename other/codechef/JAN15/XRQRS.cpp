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
#include <iterator>
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
 * usage:
 * RMQ rmq(n);							// initialization. one-based, from 1 to n.
 * rmq.init(n);							// another way of above method
 *										// in above methods, all values will be reset to zero
 * RMQ rmq(a.begin(), a.end());			// init the rmq with values of a
 * rmq.init(a.begin(), a.end());		// another way of above method
 * rmq.update(pos, value);				// update the value in pos into value
 * rmq.add(pos, value);					// add value to pos
 * rmq.add(left, right, value);			// add all value to all elements in [left..right]
 * int max = rmq.max(left, right);		// find max value in [left..right]
 * int min = rmq.min(left, right);		// find min value in [left..right]
 * int imax = rmq.idxMax(left, right);	// find the index of smallest value in [left..right]
 * int imin = rmq.idxMin(left, right);	// find the index of largest value in [left..right]
 */
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
	set<int> s;
	FOR(i, 1, 10) s.insert(i);
	RMQ rmq(ALL(s));
	printf("n = %d\n", rmq.n);
	while (true) {
		char buf[10];
		scanf("%s", buf);
		string task = buf;
		if (task == "update") {
			int pos, value;
			scanf("%d%d", &pos, &value);
			rmq.update(pos, value);
		}
		if (task == "min") {
			int left, right;
			scanf("%d%d", &left, &right);
			printf("min[%d..%d] = %d\n", left, right, rmq.min(left, right));
		}
		if (task == "max") {
			int left, right;
			scanf("%d%d", &left, &right);
			printf("max[%d..%d] = %d\n", left, right, rmq.max(left, right));
		}
	}

	vector<int> a;
	int q;

	scanf("%d", &q);
	REP(iq, q) {
		int tipe;
		scanf("%d", &tipe);
		// add number
		if (tipe == 0) {
			int x;
			scanf("%d", &x);

			// insert into a
			a.PB(x);

			// insert into trie

		}
		// xor
		else if (tipe == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);


		}
		// remove
		else if (tipe == 2) {
			int k;
			scanf("%d", &k);
			REP(i, k) {
				int x = a.back();

				// remove from a
				a.pop_back();

				// remove from trie

			}
		}
		// count
		else if (tipe == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);


		}
		// find
		else if (tipe == 1) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);


		}
	}

	return 0;
}
