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

/** Binary Indexed Tree
 * usage:
 * BIT bit(n); 							// initialization. one-based, from 1 to n
 * bit.init(n);							// another way to init. All values will be reset to zero
 * bit.update(pos, value); 				// add value to pos
 * int sum = bit.query(left, right); 	// find the sum from left to right
 * int sum = bit.query(pos);			// find the sum from 1 to pos
 */
struct BIT {
	BIT() {
		this->n = 0;
	}
	BIT(int n) {
		this->n = n;
		bit.resize(n+1);
	}
	void init(int n) {
		this->n = n;
		bit.resize(n+1);
		for (int i = 0; i <= n; ++i) {
			bit[i] = 0;
		}
	}
	void update(int pos, int value) {
		for (int x = pos; x <= n; x += (x & -x)) {
			bit[x] += value;
		}
	}
	int query(int left, int right) {
		if (left > right) {
			return 0;
			// return query(right, left)
		}
		else {
			return query(right) - query(left - 1);
		}
	}
	int query(int pos) {
		int ret = 0;
		for (int x = pos; x > 0; x -= (x & -x)) {
			ret += bit[x];
		}
		return ret;
	}

	int n;
	vector<int> bit;
};

#define MAXN 200200
int n, a[MAXN], b[MAXN], ans[MAXN], ord[MAXN], orda[MAXN], ordb[MAXN];

int main() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);

	BIT bita(n), bitb(n), bit(n);
	FOR(i, 1, n) {
		bita.update(i, 1);
		bitb.update(i, 1);
		bit.update(i, 1);
	}
	
	REP(i, n) {
		orda[i] = bita.query(a[i]);
		bita.update(a[i]+1, -1);
		ordb[i] = bitb.query(b[i]);
		bitb.update(b[i]+1, -1);
		ord[i] = orda[i] + ordb[i];
	}
	
	REPD(i, n) {
		if (ord[i] >= n - i) {
			ord[i] -= n - i;
			if (i) ord[i-1]++;
		}
	}

	// REP(i, n) printf("orda[%d] = %d\n", i, orda[i]);
	// REP(i, n) printf("ordb[%d] = %d\n", i, ordb[i]);
	// REP(i, n) printf("ord[%d] = %d\n", i, ord[i]);

	REP(i, n) {
		// find largest x such that query(x-1) == ord[i]
		int l = 1, r = n;
		while (l < r) {
			int m = (l + r) >> 1;
			int q = bit.query(m-1);
			if (q < ord[i]) {
				l = m + 1;
			}
			else if (q == ord[i]) {
				if (bit.query(m) == ord[i]) {
					l = m + 1;
				}
				else {
					l = r = m;
				}
			}
			else {
				r = m - 1;
			}
		}
		ans[i] = l-1;
		bit.update(l, -1);
	}
	REP(i, n) {
		printf("%d", ans[i]);
		if (i < n-1) printf(" "); else printf("\n");
	}

	return 0;
}