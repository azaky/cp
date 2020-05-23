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

	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)

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

#define MAXN 100100

int ntc, a[MAXN], n, q;

int s[MAXN << 3], maxnode;
vector<int> node[MAXN << 3];

void build(int v, int l, int r) {
	if (l == r) {
		MX(maxnode, v);
		node[v].resize(1);
		node[v][0] = a[l];
		s[v] = 1;
	} else {
		int vl = v << 1;
		int vr = vl | 1;
		int m = (l + r) >> 1;
		build(vl, l, m);
		build(vr, m + 1, r);
		s[v] = s[vl] + s[vr];
		node[v].resize(s[v]);
		merge(ALL(node[vl]), ALL(node[vr]), node[v].begin());
	}
}

pii query(int v, int l, int r, int xl, int xr, int x) {
	pii ans;
	if (xl <= l && r <= xr) {
		int t = lower_bound(ALL(node[v]), x + 1) - node[v].begin();
		ans = MP(t, t ? node[v][t - 1] : -1);
	} else if (r < xl || xr < l) {
		ans = MP(0, -1);
	} else {
		int vl = v << 1;
		int vr = vl | 1;
		int m = (l + r) >> 1;
		pii ql = query(vl, l, m, xl, xr, x);
		pii qr = query(vr, m + 1, r, xl, xr, x);
		ans = MP(ql.A + qr.A, max(ql.B, qr.B));
	}
	// printf("query([%d..%d], [%d..%d], %d) = (%d, %d)\n", l, r, xl, xr, x, ans.A, ans.B);
	return ans;
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		printf("Case #%d:\n", itc);
		scanf("%d%d", &n, &q);
		FOR(i, 1, n) {
			scanf("%d", &a[i]);
		}
		maxnode = 0;
		build(1, 1, n);

		sort(a+1, a+n+1);
		REP(iq, q) {
			int pl, pr, k;
			scanf("%d%d%d", &pl, &pr, &k);
			int l = 1, r = n;
			for (int i = 0; i < 15; ++i) {
				int m = a[(l + r) >> 1];
				pii t = query(1, 1, n, pl, pr, m);
				if (t.A < k) {
					l = upper_bound(a, a+n, max(t.B, m)) - a;
				} else if (t.A > k) {
					r = lower_bound(a, a+n, min(t.B, m)) - a;
				} else {
					l = r = lower_bound(a, a+n, t.B) - a;
				}
			}
			assert(l == r);
			printf("%d\n", a[l]);
		}
		REP(i, maxnode) {
			node[i].clear();
		}
	}
	GetTime();

	return 0;
}
