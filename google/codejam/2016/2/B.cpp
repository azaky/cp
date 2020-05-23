/* DELAPAN.3gp */
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

#define MAXN 222

int ntc, n, k;
db p[MAXN], pmax[MAXN][MAXN][MAXN];
db dp[MAXN][MAXN];

db getAns(const vector<db> &p) {
	assert(SZ(p) == k);
	RESET(dp, 0);
	dp[0][0] = 1;
	FOR(i, 1, k) {
		FOR(j, 0, i) {
			if (j) {
				dp[i][j] = dp[i - 1][j - 1] * p[i - 1] + dp[i - 1][j] * (1. - p[i - 1]);
			} else {
				dp[i][j] = dp[i - 1][j] * (1. - p[i - 1]);
			}
		}
	}
	return dp[k][k / 2];
}

int main(){
	OPEN("B-large");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &k);
		FOR(i, 1, n) {
			scanf("%lf", &p[i]);
		}
		sort(p + 1, p + 1 + n);

		db ans = 0;
		FOR(ileft, 0, k) {
			vector<db> chosenp;
			REP(i, ileft) {
				chosenp.PB(p[i + 1]);
			}
			REP(i, k - ileft) {
				chosenp.PB(p[n - i]);
			}
			MX(ans, getAns(chosenp));
		}
		// RESET(pmax, 0);
		// pmax[0][0][0] = 1;
		// FOR(i, 1, n) {
		// 	pmax[i][0][0] = 1;
		// 	FOR(c, 1, k) {
		// 		FOR(yes, 0, c) {
		// 			if (yes) {
		// 				pmax[i][c][yes] = pmax[i - 1][c - 1][yes - 1] * p[i] + pmax[i - 1][c - 1][yes] * (1. - p[i]);
		// 			} else {
		// 				pmax[i][c][yes] = pmax[i - 1][c - 1][yes] * (1. - p[i]);
		// 			}
		// 			// i-th doesn't vote
		// 			MX(pmax[i][c][yes], pmax[i - 1][c][yes]);
		// 			printf("pmax[%d][%d][%d] = %.2lf\n", i, c, yes, pmax[i][c][yes]);
		// 		}
		// 	}
		// }
		// printf("Case #%d: %.17lf\n", itc, pmax[n][k][k / 2]);
		printf("Case #%d: %.17lf\n", itc, ans);
	}
	
	return 0;
}
