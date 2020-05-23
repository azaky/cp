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

int ntc, n;
ll a, b, c[MAXN], sum[MAXN];

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%lld%lld", &n, &a, &b);
		FOR(i, 1, n) {
			scanf("%lld", &c[i]);
			sum[i] = sum[i - 1] + c[i];
		}
		ll ans = 0;
		// full range
		ll totalfull = 0;
		FOR(i, 1, n) {
			totalfull += c[i] * c[i];
		}
		ll xa = (a / sum[n]) * sum[n];
		if (xa != a) {
			xa += sum[n];
		}
		ll xb = (b / sum[n]) * sum[n];
		ll x = (xb - xa) / sum[n];
		ans += totalfull * x;
		// printf("xa = %lld\nxb = %lld\n", xa, xb);
		// printf("totalfull = %lld\n", totalfull);
		// a .. xa
		if (a != xa) {
			xa = a % sum[n];
			int ia = 0;
			while (ia <= n && sum[ia] <= xa) {
				ia++;
			}
			ll totala = (sum[ia] - xa) * (sum[ia] - xa + (xa - sum[ia - 1]) * 2);
			while (++ia <= n) {
				totala += c[ia] * c[ia];
			}
			ans += totala;
			// printf("totala = %lld\n", totala);
		}
		// b .. xb
		if (b != xb) {
			xb = b % sum[n];
			int ib = 1;
			ll totalb = 0;
			while (sum[ib] <= xb) {
				totalb += c[ib] * c[ib];
				ib++;
			}
			totalb += (xb - sum[ib - 1]) * (xb - sum[ib - 1]);
			ans += totalb;
			// printf("totalb = %lld\n", totalb);
		}
		printf("Case #%d: %.17lf\n", itc, (db)ans / (b - a) / 2.);
	}

	return 0;
}