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

#define MAXN 1000005
#define MAXQ 10005

int r, c, q;
int ra[MAXQ], rb[MAXQ], ca[MAXQ], cb[MAXQ], t[MAXQ];
ll ans[MAXQ];
char task[10];

ll tree[MAXN << 3], lazy[MAXN << 3];

void lazyUpdate(int v, int l, int r) {
	tree[v] += lazy[v] * (r - l + 1);
	if (l < r) {
		int vl = v << 1;
		int vr = vl | 1;
		lazy[vl] += lazy[v];
		lazy[vr] += lazy[v];
	}
	lazy[v] = 0;
}

ll query(int v, int l, int r, int x, int y) {
	lazyUpdate(v, l, r);

	if (x <= l && r <= y) {
		return tree[v];
	} else if (r < x || y < l) {
		return 0;
	} else {
		int vl = v << 1;
		int vr = vl | 1;
		int m = (l + r) >> 1;
		return query(vl, l, m, x, y) + query(vr, m + 1, r, x, y);
	}
}

void update(int v, int l, int r, int x, int y, int add) {
	lazyUpdate(v, l, r);

	int vl = v << 1;
	int vr = vl | 1;
	int m = (l + r) >> 1;
	if (x <= l && r <= y) {
		tree[v] += add * (r - l + 1);
		lazy[vl] += add;
		lazy[vr] += add;
	} else if (r < x || y < l) {
		// do nothing
	} else {
		update(vl, l, m, x, y, add);
		update(vr, m + 1, r, x, y, add);
		tree[v] = tree[vl] + tree[vr];
	}
}

int main() {
	scanf("%d%d", &r, &c);
	scanf("%d", &q);
	FOR(iq, 1, q) {
		scanf("%s%d%d%d%d", task, &ra[iq], &ca[iq], &rb[iq], &cb[iq]);
		if (task[0] == 'q') {
			t[iq] = 0;
		} else if (task[0] == 'a') {
			t[iq] = 1;
		} else {
			t[iq] = -1;
		}
		ans[iq] = 0;
	}
	FOR(ir, 1, r) {
		// reset
		RESET(tree, 0);
		RESET(lazy, 0);
		FOR(iq, 1, q) {
			if (rb[iq] < ir || ir < ra[iq]) {
				continue;
			} else {
				if (t[iq] == 0) {
					ans[iq] += query(1, 1, c, ca[iq], cb[iq]);
				} else {
					update(1, 1, c, ca[iq], cb[iq], t[iq]);
				}
			}
		}
	}
	FOR(iq, 1, q) {
		if (t[iq] == 0) {
			printf("%lld\n", ans[iq]);
		}
	}

	return 0;
}