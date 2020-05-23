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

#define MOD 1000000007

int ntc, n, k, dp[444][2222];

int calcBruteForce(int n, int k) {
	int p[111];
	int ans = 0;
	REP(mask, 1 << n) {
		REP(i, n) {
			if ((1 << i) & mask) {
				p[i] = 1;
			} else {
				p[i] = 0;
			}
		}
		bool isPalindrome = false;
		REP(s, n - k + 1) {
			bool local = true;
			for (int l = s, r = s + k - 1; l < r && local; ++l, --r) {
				if (p[l] != p[r]) {
					local = false;
				}
			}
			if (local) {
				isPalindrome = true;
			}
		}
		REP(s, n - k) {
			bool local = true;
			for (int l = s, r = s + k; l < r && local; ++l, --r) {
				if (p[l] != p[r]) {
					local = false;
				}
			}
			if (local) {
				isPalindrome = true;
			}
		}
		if (!isPalindrome) {
			ans++;
		}
	}
	return ans;
}

int calc(int n, int k) {
	if (n < k) {
		return 1 << n;
	}
	// generate first 1<<k
	REP(mask, 1 << k) {
		bool isPalindrome = true;
		for (int l = 0, r = k - 1; l < r && isPalindrome; ++l, --r) {
			if ((((1 << l) & mask) >> l) != (((1 << r) & mask) >> r)) {
				isPalindrome = false;
			}
		}
		if (!isPalindrome) {
			dp[k][mask] = 1;
		} else {
			dp[k][mask] = 0;
		}
	}
	REP(mask, 1 << (k + 1)) {
		bool isPalindrome = true;
		for (int l = 0, r = k; l < r && isPalindrome; ++l, --r) {
			if ((((1 << l) & mask) >> l) != (((1 << r) & mask) >> r)) {
				isPalindrome = false;
			}
		}
		if (!isPalindrome) {
			dp[0][mask] = 1;
		} else {
			dp[0][mask] = 0;
		}
	}
	FOR(t, k + 1, n) {
		REP(mask, 1 << k) {
			dp[t][mask] = 0;
			if (!dp[k][mask]) continue;
			REP(p, 2) {
				// p .. mask
				int nmask = mask ^ (p << k);
				int pmask = (mask >> 1) ^ (p << (k - 1));
				if (dp[k][pmask] && dp[0][nmask]) {
					dp[t][mask] += dp[t - 1][pmask];
					dp[t][mask] %= MOD;
				}
			}
			// printf("dp[%d][%d] = %d\n", t, mask, dp[t][mask]);
		}
	}

	int ans = 0;
	REP(mask, 1 << k) {
		ans += dp[n][mask];
		ans %= MOD;
	}
	return ans;
}

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &k);

		int ans = calc(n, k);
		printf("%d\n", ans);
		// int ansBruteForce = calcBruteForce(n, k);
		// if (ans != ansBruteForce) {
		// 	printf("DIFFER! should be %d\n", ansBruteForce);
		// }
		// fflush(stdout);
	}
	
	return 0;
}