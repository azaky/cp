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

#define MAXN 11100
int n, m, a[MAXN][MAXN], h[MAXN], prev[MAXN];
int sum[MAXN << 3], lazy[MAXN << 3], lazysum[MAXN << 3], lazyerase[MAXN << 3], xl[MAXN << 3], xr[MAXN << 3], vl[MAXN << 3], vr[MAXN << 3];

void propagate(int v) {
	if (lazy[v]) {
		lazy[vl[v]] = lazy[vr[v]] = 1;
		if (lazyerase[v]) {
			// printf("propagate [%d..%d]: erase\n", xl[v], xr[v]);
			sum[v] = 0;
			lazyerase[vl[v]] = 1;
			lazyerase[vr[v]] = 1;
		}
		else {
			// printf("propagate [%d..%d]: sum += %d\n", xl[v], xr[v], lazysum[v]);
			sum[v] += lazysum[v] * (xr[v] - xl[v] + 1);
			lazysum[vl[v]] += lazysum[v];
			lazysum[vr[v]] += lazysum[v];
			lazyerase[vl[v]] = 0;
			lazyerase[vr[v]] = 0;
		}
		lazy[v] = 0;
		lazysum[v] = lazyerase[v] = 0;
	}
}

void erase(int v, int x, int y) {
	propagate(v);
	if (xr[v] < x || y < xl[v]) {
		return;
	}
	if (x <= xl[v] && xr[v] <= y) {
		propagate(vl[v]); propagate(vr[v]);
		sum[v] = 0;
		lazy[vl[v]] = lazy[vr[v]] = 1;
		lazyerase[vl[v]] = 1;
		lazyerase[vr[v]] = 1;
	}
	else {
		erase(vl[v], x, y);
		erase(vr[v], x, y);
		sum[v] = sum[vl[v]] + sum[vr[v]];
	}
}

void update(int v, int x, int y, int value) {
	// printf("update(v = %d [%d..%d], x = %d, y = %d, value = %d)\n", v, xl[v], xr[v], x, y, value);
	propagate(v);
	if (xr[v] < x || y < xl[v]) {
		return;
	}
	if (x <= xl[v] && xr[v] <= y) {
		propagate(vl[v]); propagate(vr[v]);
		sum[v] += value * (xr[v] - xl[v] + 1);
		lazy[vl[v]] = lazy[vr[v]] = 1;
		lazysum[vl[v]] += value;
		lazysum[vr[v]] += value;
	}
	else {
		update(vl[v], x, y, value);
		update(vr[v], x, y, value);
		sum[v] = sum[vl[v]] + sum[vr[v]];
	}
}

int query(int v, int x, int y) {
	propagate(v);
	if (xr[v] < x || y < xl[v]) {
		return 0;
	}
	if (x <= xl[v] && xr[v] <= y) {
		return sum[v];
	}
	else {
		return query(vl[v], x, y) + query(vr[v], x, y);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) FOR(j, 1, m) {
		scanf("%d", &a[i][j]);
	}

	xl[1] = 1; xr[1] = n;
	FOR(i, 1, n << 2) {
		// printf("i = %d, l = %d, r = %d\n", i, xl[i], xr[i]);
		vl[i] = i << 1;
		vr[i] = vl[i] | 1;
		xl[vl[i]] = xl[i];
		xr[vl[i]] = (xl[i] + xr[i]) / 2;
		xl[vr[i]] = xr[vl[i]] + 1;
		xr[vr[i]] = xr[i];
	}

	ll ans = 0;
	FOR(i, 1, n) {
		int last = 0;
		FOR(j, 1, m) {
			if (a[i][j] != last) {
				erase(1, 1, n);
				last = a[i][j];
				//puts("NIH DIERASE COY");
			}
			// printf("tree:");
			// for (int k = 1; k <= n; k++) {
			// 	printf(" %d", query(1, k, k));
			// }
			// printf(" total: %d", query(1, 1, n));
			// printf("\n");
			if (prev[j] != a[i][j]) {
				h[j] = 1;
				prev[j] = a[i][j];
			}
			else {
				h[j]++;
			}
			if (h[j] < n) erase(1, h[j] + 1, n);
			update(1, 1, h[j], 1);
			int add = query(1, 1, h[j]);
			ans += add;
			// printf("i = %d, j = %d, h[j] = %d, prev[j] = %d, val = %d\n", i, j, h[j], prev[j], add);
			// printf("tree:");
			// for (int k = 1; k <= n; k++) {
			// 	printf(" %d", query(1, k, k));
			// }
			// printf("\n");
		}
		// printf("-----\n\n");
	}
	printf("%lld\n", ans);
	
	return 0;
}
