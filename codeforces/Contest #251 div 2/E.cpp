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

#define MOD 1000000007LL
#define MAXN 100100

int p[MAXN], tau[MAXN], huba[MAXN];
ll fact[MAXN], ifact[MAXN];

ll power(ll a, ll b) {
	if (b == 0) return 1LL;
	ll temp = power(a, b / 2LL);
	temp *= temp;
	temp %= MOD;
	if (b % 2LL == 1LL) {
		temp *= a;
		temp %= MOD;
	}
	return temp;
}

ll inv(ll x) {
	return power(x, MOD-2);
}

ll c(int n, int k) {
	if (n < k) return 0;
	ll ret = fact[n];
	ret *= ifact[k];
	ret %= MOD;
	ret *= ifact[n-k];
	ret %= MOD;
	return ret;
}

int main(){

	// fact
	fact[0] = 1;
	ifact[0] = 1;
	FOR(i, 1, 100000) {
		fact[i] = fact[i-1] * (ll)i;
		fact[i] %= MOD;
		ifact[i] = inv(fact[i]);
	}
	// huba
	huba[1] = 1;
	FOR(i, 2, 100000) {
		huba[i] = 0;
		for (int j = 1; j * j <= i; j++) {
			if (i % j != 0) continue;
			huba[i] -= huba[j];
			if (j * j != i && j != 1) huba[i] -= huba[i/j];
		}
	}
	
	int q, f, n;
	scanf("%d", &q);
	FOR(itc, 1, q) {
		scanf("%d %d", &n, &f);
		ll ans = c(n-1, f-1);
		vector<int> factor;
		for (int i = 1; i * i <= n; i++) {
			if (n % i != 0) continue;
			if (i < n) factor.PB(i);
			if (i * i != n && i > 1) factor.PB(n/i);
		}
		REP(i, SZ(factor)) {
			ans += c(factor[i] - 1, f - 1) * (ll)huba[n / factor[i]];
			ans += MOD;
			ans %= MOD;
		}
		cout << ans << endl;
	}
	
	return 0;
}
