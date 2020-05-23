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
#define MOD 1000000007LL

int ntc, n, x[MAXN], h[MAXN];
int bit[MAXN];
vector<int> a[MAXN];

int query(int k) {
	int ret = 0;
	for (int x = k; x > 0; x -= x & -x) {
		ret += bit[x];
	}
	return ret;
}

int query(int l, int r) {
	int ret = 0;
	if (l <= r) {
		ret = query(r) - query(l - 1);
	}
	// printf("query(%d..%d) = %d\n", l, r, ret);
	return ret;
}

void update(int k, int v) {
	// printf("updating %d\n", k);
	for (int x = k; x <= n; x += x & -x) {
		bit[x] += v;
	}
}

ll calc(const vector<int> &c) {
	int m = SZ(c) - 1;
	if (m < 0) {
		return 0;
	}
	ll ret = 0;
	ll sumlucu = 0;
	ll sumsquare = 0;
	FOR(i, 1, m) {
		ll g = c[i] - c[i - 1];
		ll temp = 0;
		temp += ((g * g) % MOD) * i;
		temp %= MOD;
		temp += sumsquare;
		temp %= MOD;
		temp += 2LL * g * sumlucu;
		temp %= MOD;
		ret += temp;
		ret %= MOD;

		sumsquare = temp;
		sumlucu += g * i;
		sumlucu %= MOD;
	}
	// FORIT(it, c) {
	// 	printf("%d ", *it);
	// }
	// printf(": %lld\n", ret);
	return ret;
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		REP(i, n) {
			scanf("%d%d", &x[i], &h[i]);
		}
		// normalize h
		vector<int> allh;
		REP(i, n) {
			allh.PB(h[i]);
		}
		sort(ALL(allh));
		allh.resize(unique(ALL(allh)) - allh.begin());
		map<int, int> idxh;
		REP(i, SZ(allh)) {
			idxh[allh[i]] = i + 1;
		}
		REP(i, n) {
			h[i] = idxh[h[i]];
		}
		// normalize x
		vector<int> allx;
		REP(i, n) {
			allx.PB(x[i]);
		}
		allx.PB(-1);
		sort(ALL(allx));
		allx.resize(unique(ALL(allx)) - allx.begin());
		map<int, int> idxx;
		REP(i, SZ(allx)) {
			idxx[allx[i]] = i;
		}

		RESET(bit, 0);
		FOR(i, 1, n) {
			a[i].clear();
		}
		REP(i, n) {
			assert(1 <= h[i] && h[i] <= n);
			a[h[i]].PB(x[i]);
		}
		ll ans = 0;
		FORD(i, n, 1) {
			sort(ALL(a[i]));
			vector<int> c;
			int last = -1;
			FORIT(it, a[i]) {
				if (query(idxx[last] + 1, idxx[*it] - 1) > 0) {
					ans += calc(c);
					ans %= MOD;
					c.clear();
				}
				c.PB(*it);
				last = *it;
				update(idxx[*it], 1);
			}
			ans += calc(c);
			ans %= MOD;
		}
		printf("Case #%d: %lld\n", itc, ans);
	}

	return 0;
}