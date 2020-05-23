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

#define MAXN 100100

int ntc, n;
ll a[MAXN], dp[MAXN][2];

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		FOR(i, 1, n) {
			scanf("%lld", &a[i]);
		}
		ll ans = 0;
		bool allNegative = true;
		dp[0][0] = dp[0][1] = 0;
		FOR(i, 1, n) {
			if (a[i] > 0) {
				allNegative = false;
			}
			if (dp[i - 1][0] < 0) {
				dp[i][0] = a[i];
			} else {
				dp[i][0] = dp[i - 1][0] + a[i];
			}
			MX(dp[i][0], 0LL);
			dp[i][1] = max(dp[i][0], max(dp[i - 1][1] + a[i], dp[i - 1][0]));
			MX(dp[i][1], 0LL);
			MX(ans, max(dp[i][0], dp[i][1]));

			// REP(j, 2) printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
		}
		if (allNegative) {
			ans = a[1];
			FOR(i, 1, n) {
				MX(ans, a[i]);
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
