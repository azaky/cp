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

#define MAXN 100100
#define MOD 1000000007

int n, pl[MAXN], pr[MAXN], u[MAXN];
ll a[MAXN], b[MAXN];

int find(int *p, int x) {
	if (p[x] == x) {
		return x;
	} else {
		return p[x] = find(p, p[x]);
	}
}

vector<ll> docalc(ll *a) {
	vector<ll> ans1(n + 2), ansfix(n + 2), ans(n + 2);
	vector<pair<ll, int> > x;
	FOR(i, 1, n) {
		x.PB(MP(a[i], i));
	}
	sort(ALL(x));

	FOR(i, 1, n) {
		pl[i] = pr[i] = i;
		u[i] = 0;
	}
	u[0] = u[n + 1] = 0;

	FORIT(it, x) {
		int pos = it->B;
		if (u[pos - 1]) {
			pl[pos] = find(pl, pos - 1);
		}
		if (u[pos + 1]) {
			pr[pos] = find(pr, pos + 1);
		}
		if (u[pos - 1]) {
			pr[find(pl, pos - 1)] = pr[pos];
		}
		if (u[pos + 1]) {
			pl[find(pr, pos + 1)] = pl[pos];
		}
		u[pos] = 1;

		int xa = pr[pos] - pos + 1;
		int xb = pos - pl[pos] + 1;
		int x = xa + xb - 1;
		if (xa > xb) {
			swap(xa, xb);
		}
		// printf("pos = %d, [%d..%d]\n", pos, pl[pos], pr[pos]);
		// printf("xa = %d, xb = %d\n", xa, xb);

		// 1..xa, ans1
		ans1[1] += a[pos];
		ans1[xa + 1] -= a[pos];
		// xa + 1 .. xb, ansfix
		ansfix[xa + 1] += a[pos] * xa;
		ansfix[xb + 1] -= a[pos] * xa;
		// xb + 1 .. xb + xa - 1, ans
		ans1[1] += a[pos];
		ans1[xb + 1] -= a[pos];
		ans1[1] -= a[pos];
		ans1[x + 1] += a[pos];
		ansfix[xb + 1] += a[pos] * (xa + xb);
		ansfix[x + 1] -= a[pos] * (xa + xb);

		// FOR(i, 1, xa - 1) {
		// 	ans[xa + xb - i] += a[pos] * i;
		// 	ans[xa + xb - i] %= MOD;
		// }

		// FOR(k, 1, pr[pos] - pl[pos] + 1) {
		// 	int xr = min(pr[pos], pos + k - 1) - k + 1;
		// 	int xl = max(pl[pos], pos - k + 1);
		// 	// printf("pos = %d, k = %d, [%d..%d]\n", pos, k, xl, xr);
		// 	ans[k] += a[pos] * (xr - xl + 1);
		// 	ans[k] %= MOD;
		// }
	}

	FOR(i, 1, n) {
		ans1[i] += ans1[i - 1];
		ansfix[i] += ansfix[i - 1];
	}

	FOR(i, 1, n) {
		// ans1[i] += ans1[i - 1];
		ans1[i] = ((ans1[i] % MOD) + MOD) % MOD;
		ans1[i] *= i;
		ans1[i] %= MOD;
		ans[i] += ans1[i];
		ans[i] %= MOD;

		// ansfix[i] += ansfix[i - 1];
		ansfix[i] = ((ansfix[i] % MOD) + MOD) % MOD;
		ans[i] += ansfix[i];
		ans[i] %= MOD;
	}
	// FOR(i, 1, n) {
	// 	printf("%lld ", ans[i]);
	// }
	// puts("");
	return ans;
}

int main() {
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%lld", &a[i]);
		a[i] += i;
	}
	FOR(i, 1, n) {
		scanf("%lld", &b[i]);
		b[i] += i;
	}

	vector<ll> ansa = docalc(a);
	vector<ll> ansb = docalc(b);
	FOR(i, 1, n) {
		ll ans = (ansa[i] * ansb[i]) % MOD;
		printf("%lld", ans);
		if (i == n) {
			putchar('\n');
		} else {
			putchar(' ');
		}
	}

	return 0;
}