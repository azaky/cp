#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
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
	#define GetTime()	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

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

/* -------------- end of azaky's template -------------- */

#define MOD 2000000007LL
ll n, m, dp[1111][30][30], dp2[1111][30], ans;

int main(){
	cin >> n >> m;
//	FOR(a,1,m) FOR(b,1,m) dp[0][a][b] = 1LL;
	FOR(i,1,n){
		FOR(a,1,m) FOR(b,1,m){
			if (a == 1 && b == 1) dp[i][a][b] = 1LL;
			else dp[i][a][b] = (dp[i][a-1][b]+dp[i][a][b-1]-dp[i][a-1][b-1]+dp[i-1][a][b] + MOD) % MOD;
		}
		FOR(a,1,m) FOR(b,1,m){
			if (a != b) dp[i][a][b] = (dp[i][a][b]+dp[i][a][b])%MOD;
		}
/*
		FOR(a,1,m) FOR(b,1,m){
			printf("dp[%d][%d][%d] = %I64d\n",i,a,b,dp[i][a][b]);
		}
*/
	}
	FOR(i,1,n){
		FOR(a,1,m){
			if (a == 1) dp2[i][a] = 1;
			else dp2[i][a] = (dp2[i][a-1]+dp2[i-1][a])%MOD;
		}
	}
	ans = 0;
	FOR(a,1,m) FOR(b,1,m) ans = (ans + dp[n][a][b])%MOD;
	FOR(a,1,m) ans = (ans + dp2[n][a])%MOD;
	assert(ans % 2LL == 0);
//	if (ans % 2LL != 0) ans = ans + MOD;
	cout << ans/2LL << endl;
	
	return 0;
}
