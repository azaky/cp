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

#define MAXN 500500
int p[MAXN], tau[MAXN], r[MAXN];
int n, q, v[MAXN], huba[MAXN], a[MAXN];
vector<int> factor[MAXN];

int main() {
	// precompute everything
	// basic sieve
	FOR(i, 1, 500000) p[i] = i;
	for (int i = 2; i * i <= 500000; ++i) {
		if (p[i] == i) {
			for (int j = i; j * i <= 500000; ++j) {
				p[i * j] = i;
			}
		}
	}
	// calculate the "reduced" form, tau (not real tau, though)
	r[1] = 1;
	tau[1] = 0;
	FOR(i, 2, 500000) {
		int x = i, _p = p[x], k = 0;
		while (x % _p == 0) {
			x /= _p;
			k++;
		}
		r[i] = r[x] * _p;
		tau[i] = 1 + tau[x];
	}

	scanf("%d%d", &n, &q);
	REP(i, n) {
		scanf("%d", &a[i]);
		a[i] = r[a[i]];
		for (int j = 1; j * j <= a[i]; ++j) {
			if (a[i] % j != 0) continue;
			if (j != 1) factor[i].PB(j);
			if (j * j != a[i]) factor[i].PB(a[i] / j);
		}
	}

	ll ans = 0;
	int here = 0;
	REP(iq, q) {
		int x;
		scanf("%d", &x);
		x--;

		if (v[x]) {
			FORIT(it, factor[x]) huba[*it]--;
		}

		ll add = 0;
		FORIT(it, factor[x]) {
			if (tau[*it] % 2 == 1) {
				add += (ll)huba[*it];
			} else {
				add -= (ll)huba[*it];
			}
		}

		// printf("add = %d\n", add);

		if (v[x]) {
			here--;
			ans -= (ll)here - add;
			v[x] = 0;
		} else {
			ans += (ll)here - add;
			here++;
			v[x] = 1;
			FORIT(it, factor[x]) huba[*it]++;
		}

		printf("%I64d\n", ans);

		// FOR(i, 1, 6) {
		// 	printf("huba[%d] = %d\n", i, huba[i]);
		// }
		// printf("\n");
	}

	return 0;
}