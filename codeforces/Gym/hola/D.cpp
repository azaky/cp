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

ll m, k;
ll dp[100][100];
ll comb[100][100];

ll calpico(ll x) {
	FOR(i, 0, 64) FOR(j, 0, 64) dp[i][j] = 0;
	int firstDigit = (int)(x & 1);
	dp[0][0] = 1;
	if (firstDigit == 1) {
		dp[0][1] = 1;
	}
	FOR(len, 1, 63) {
		int digit = (int)((x >> (ll)len) & 1);
		dp[len][0] = 1;
		FOR(i, 1, len + 1) {
			if (digit == 0) {
				dp[len][i] = dp[len - 1][i];
			} else {
				dp[len][i] = dp[len - 1][i - 1];
				if (i <= len) {
					dp[len][i] += comb[len - i][i];
				}
			}
		}
	}
	// printf("calpico(%lld) = %lld\n", x, dp[63][k]);
	return dp[63][k];
}

ll calc(ll x) {
	return calpico(x << 1LL) - calpico(x);
}

int main() {
	REP(i, 100) REP(j, 100) {
		if (i == 0 || j == 0) {
			comb[i][j] = 1;
		} else {
			comb[i][j] = comb[i - 1][j] + comb[i][j - 1];
		}
	}

	cin >> m >> k;

	ll l = 1, r = 1000000000000000000LL;
	while (l < r) {
		ll mid = (l + r) / 2LL;
		ll c = calc(mid);
		// printf("[%lld..%lld]: calc(%lld) = %lld\n", l, r, mid, c);
		if (c == m) {
			cout << mid << endl;
			return 0;
		} else if (c > m) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << l << endl;
	return 0;

	return 0;
}
