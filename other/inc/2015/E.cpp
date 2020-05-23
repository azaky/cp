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

#define MAXN 10100

int ntc;
int n, m, r, selected[MAXN], p[MAXN], npre[MAXN], idx[MAXN];
vector<int> adj[MAXN];

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
			MX(bit[x], value);
		}
	}
	int query(int pos) {
		int ret = 0;
		for (int x = pos; x > 0; x -= (x & -x)) {
			MX(ret, bit[x]);
		}
		return ret;
	}
	int n;
	vector<int> bit;
};

int lis(int x, int y) { // lis dari x .. y, both must be included
	// printf("lis(%d, %d)\n", x, y);
	// normalize
	vector<int> id;
	FOR(i, x, y) {
		id.PB(idx[i]);
	}
	sort(ALL(id));
	int size = SZ(id);
	map<int, int> iidx;
	REP(i, size) {
		iidx[id[i]] = i + 1;
	}

	BIT bit(size + 1);
	FOR(i, x, y - 1) {
		if (idx[i] < idx[x] || idx[i] > idx[y]) continue;
		int now = bit.query(iidx[idx[i]]);
		bit.update(iidx[idx[i]], now + 1);
	}
	return 1 + bit.query(iidx[idx[y]] - 1);
}

int main() {
	scanf("%d", &ntc);

	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &n, &m, &r);
		FOR(i, 0, n) {
			selected[i] = 0;
			adj[i].clear();
			npre[i] = 0;
		}
		FOR(i, 1, m) {
			scanf("%d", &p[i]);
			selected[p[i]] = 1;
			if (i > 1) {
				adj[p[i - 1]].PB(p[i]);
				npre[p[i]]++;
			}
		}
		p[0] = 0;
		p[m + 1] = n + 1;
		REP(i, r) {
			int x, y;
			scanf("%d%d", &x, &y);
			adj[x].PB(y);
			npre[y]++;
		}
		// topo sort
		queue<int> q;
		FOR(i, 1, n) {
			if (npre[i] == 0) q.push(i);
		}
		int nr = 0;
		while (!q.empty()) {
			// assert(q.size() == 1);
			int now = q.front(); q.pop();
			idx[now] = ++nr;
			// printf("idx[%d] = %d\n", now, idx[now]);
			FORIT(it, adj[now]) {
				npre[*it]--;
				if (npre[*it] == 0) {
					q.push(*it);
				}
			}
		}
		// printf("nr = %d\n", nr);
		// assert(n == nr);
		idx[0] = 0;
		idx[n + 1] = n + 1;

		int ans = 0;
		REP(i, m + 1) {
			ans += lis(p[i], p[i + 1]);
			// printf("ans = %d\n", ans);
		}
		ans -= m + 2;
		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}
