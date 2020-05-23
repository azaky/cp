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

#define MAXN 400400
#define MOD 1000000009LL

ll fact[MAXN + 5], invfact[MAXN + 5];

ll powMod(ll a, ll b) {
	if (b == 0) {
		return 1;
	} else {
		ll temp = powMod((a * a) % MOD, b >> 1LL);
		if (b & 1) {
			temp = (temp * a) % MOD;
		}
		return temp;
	}
}

ll inv(ll x) {
	return powMod(x, MOD - 2);
}

void precomputeFactorials() {
	fact[0] = 1;
	FOR(i, 1, 400000) {
		fact[i] = fact[i - 1] * (ll)i;
		fact[i] %= MOD;
	}
	FOR(i, 0, 400000) {
		invfact[i] = inv(fact[i]);
	}
}

ll combination(ll n, ll k) {
	ll denom = (invfact[n - k] * invfact[k]) % MOD;
	ll numer = fact[n];
	ll result = (denom * numer) % MOD;
	// printf("C(%lld, %lld) = %lld\n", n, k, result);
	return result;
}

ll calc(ll a, ll b) {
	// printf("calc %lld, %lld\n", a, b);
	if (a < 0 || b < 0) {
		return 0;
	} else {
		return combination(a + b + 2, a + 1) - 1;
	}
}

int main() {
	precomputeFactorials();

	int ntc;
	ll n, m, r, l;
	scanf("%d", &ntc);
	REP(itc, ntc) {
		scanf("%lld%lld%lld%lld", &n, &m, &l, &r);
		ll ans = calc(n - m + l - 1, m + r - 2)
				+ calc(n - m - 1, m - 2)
				- calc(n - m + l - 1, m - 2)
				- calc(n - m - 1, m + r - 2);
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		printf("%lld\n", ans);
	}

	return 0;
}
