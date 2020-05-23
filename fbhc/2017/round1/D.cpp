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

ll power(ll a, ll b) {
	if (b == 0) return 1;
	ll temp = power((a * a) % MOD, b / 2);
	if (b & 1) temp = (temp * a) % MOD;
	return temp;
}

ll inv(ll x) {
	return power(x, MOD - 2);
}

#define MAXN 2222
#define MAXT 8100100

int ntc, n, r[MAXN];
ll m, f[MAXT], finv[MAXT];

int main(){
	scanf("%d", &ntc);

	FOR(itc, 1, ntc) {
		scanf("%d%lld", &n, &m);
		m--;

		int total = 0;
		FOR(i, 1, n) {
			scanf("%d", &r[i]);
			total += r[i] + r[i];
		}

		// precalc M! / (M - i)!
		f[0] = 1;
		finv[0] = 1;
		FOR(i, 1, total) {
			f[i] = (f[i - 1] * (m - i + 1)) % MOD;
			finv[i] = (finv[i - 1] * inv(m - i + 1)) % MOD;
		}

		ll magic = inv(n * (n - 1));

		ll ans = 0;
		// special case for n = 1
		if (n == 1) {
			ans = m + 1;
		} else {
			// brute force both endpoints
			FOR(a, 1, n) FOR(b, 1, n) {
				if (a == b) continue;
				// N! * (M - total + N)! / (M - total)! = N! * prod(M - total + 1..M - total + N) = N! * f[M - total] / f[M - total + N]
				int t = total - r[a] - r[b];
				if (t > m) continue;
				ll addum = (f[t] * finv[t - n]) % MOD;
				addum *= magic;
				addum %= MOD;
				// printf("[%d - %d]: %lld, ft = %lld, ftn = %lld\n", a, b, addum, f[t], f[t - n]);

				ans += addum;
				ans %= MOD;
			}
		}

		printf("Case #%d: %lld\n", itc, ans);
	}

	return 0;
}