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

const int a[] = {1, 6, 4, 3};
#define MAXN 111

int lcm(int mask) {
	int ret = 1;
	REP(i, 4) {
		if (mask & (1 << i)) {
			ret = ret * a[i] / __gcd(ret, a[i]);
		}
	}
	return ret;
}

int ntc, r, c;
ll dp[MAXN][20][20];

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &r, &c);
		REP(i, (1 << 4)) {
			dp[0][3][i] = dp[0][2][i] = 0;
		}
		dp[0][3][0] = dp[0][2][0] = 1;

		FOR(i, 1, r) REP(d, 1 << 4) {
			dp[i][3][d] = dp[i][2][d] = 0;

			// 3
			// 3
			if (d & 1) {
				if (i >= 2) {
					dp[i][3][d] += dp[i-2][2][d] + dp[i-2][2][d^1];
				}

				// 2
				dp[i][2][d] += dp[i-1][3][d] + dp[i-1][3][d^1];
			}

			// 222211
			// 211222
			if (d & 2) {
				int mul = __gcd(lcm(d), 6);
				int muld = __gcd(lcm(d ^ 2), 6);

				if (c % 6 == 0 && i >= 2) {
					dp[i][2][d] += dp[i-2][3][d] * mul + dp[i-2][3][d^2] * muld;
				}
			}

			// 2221
			// 2121
			// 2122
			if (d & 4) {
				int mul = __gcd(lcm(d), 4);
				int muld = __gcd(lcm(d ^ 4), 4);

				if (c % 4 == 0 && i >= 3) {
					dp[i][2][d] += dp[i-3][3][d] * mul + dp[i-3][3][d^4] * muld;
				}
			}

			// 221
			// 221
			if (d & 8) {
				int mul = __gcd(lcm(d), 3);
				int muld = __gcd(lcm(d ^ 8), 3);

				if (c % 3 == 0 && i >= 2) {
					dp[i][2][d] += dp[i-2][3][d] * mul + dp[i-2][3][d^8] * muld;
				}
			}

			dp[i][2][d] %= MOD;
			dp[i][3][d] %= MOD;
		}

		ll ans = 0;
		REP(i, 1 << 4) {
			ans += dp[r][2][i];
			ans += dp[r][3][i];
			ans %= MOD;
		}

		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}