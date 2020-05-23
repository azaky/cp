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
#define MX(a,b) a = max((a),(b))
#define MN(a,b) a = min((a),(b))

/* -------------- end of azaky's template -------------- */

#define INF 1000000000000000LL

ll n,m,k,price[333][333],dp[333][333];

int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	FOR(i,0,n) FOR(j,0,n) price[i][j] = INF;
	REP(i,m){
		ll _l, _r, _c;
		scanf("%I64d%I64d%I64d",&_l,&_r,&_c);
		MN(price[_l][_r],_c);
	}
	FORD(len,n-1,1) FOR(i,1,n-len) MN(price[i][i+len-1],min(price[i][i+len],price[i-1][i+len-1]));
	FOR(last,0,n) FOR(kk,0,n) dp[last][kk] = INF;
	FOR(last,0,n) dp[last][0] = 0;
	FOR(kk,1,n) FOR(last,kk,n){
		dp[last][kk] = price[last-kk+1][last];
		MN(dp[last][kk],dp[last-1][kk]);
		FOR(p,1,kk) MN(dp[last][kk],dp[last-p][kk-p]+price[last-p+1][last]);
	}
	if (dp[n][k] == INF) puts("-1"); else printf("%I64d\n",dp[n][k]);
	
	return 0;
}
