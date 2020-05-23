#include <vector>
#include <map>
#include <set>
#include <queue>
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
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long LL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

int ntc, N, X, Y, n, sisa;
double ans, dp[5111][5111];

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d%d",&N,&X,&Y);
		
		for (n = 0; ; n++){
			if ((2*n-1)*n <= N && (2*n+1)*(n+1) > N) break;
		}
		
		if (abs(X)+abs(Y) <= 2*n - 2){
			printf("Case #%d: 1.0\n",itc);
			continue;
		}
		
		if (abs(X)+abs(Y) > 2*n){
			printf("Case #%d: 0.0\n",itc);
			continue;
		}
		
		sisa = N - (2*n-1)*n;
		
		if (Y == 2*n || Y+1 > sisa){
			printf("Case #%d: 0.0\n",itc);
			continue;
		}
		
		double total = 0.0;
		
		dp[0][0] = 1.;
		FOR(s,1,sisa){
			FOR(l,0,s){
				int r = s - l;
				dp[l][r] = 0.;
				if (l > 2*n || r > 2*n) continue;
				if (l) dp[l][r] += (r == 2*n ? 1. : 0.5)*dp[l-1][r];
				if (r) dp[l][r] += (l == 2*n ? 1. : 0.5)*dp[l][r-1];
				if (s == sisa) total += dp[l][r];
			}
		}
		
		assert(fabs(total-1.0) < 0.000001);
		
		ans = 0.;
		FOR(l,0,sisa){
			int r = sisa-l;
			if (X < 0 && Y+1 <= l) ans += dp[l][r];
			if (X > 0 && Y+1 <= r) ans += dp[l][r];
		}
		
		printf("Case #%d: %.17lf\n",itc,ans);
	}
	
	return 0;
}
