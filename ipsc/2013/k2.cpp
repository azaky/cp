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

ll way[111111], dp[11];
int n, ntc;
#define MOD 1000000009

int main(){
	dp[0] = 1;
	FOR(i,1,4){
		dp[i] = 0;
		FOR(step,1,2) if (i-step >= 0) dp[i] += dp[i-step];
	}
//	FOR(i,1,4) printf("[%d][%d]\n",i,dp[i]);
	way[0] = 1;
	FOR(i,1,100000){
		way[i] = 0;
		FOR(step,1,4){
			if (i-step < 0) continue;
			way[i] = (way[i] + way[i-step]*dp[step])%MOD;
		}
	}
	scanf("%d",&ntc);
	REP(itc,ntc){
		scanf("%d",&n);
		printf("%I64d\n",way[n]);
	}
	
	return 0;
}
