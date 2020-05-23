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

#define INF 1000000
int dp[82][82][82][82], a[82][82];
int n, m;
int r1,r2,c1,c2,k;

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	FOR(sr,1,n) FOR(sc,1,m){
		if ((sr*sc)%2) continue;
		for (r1=1,r2=sr; r2 <= n; r1++,r2++){
			for(c1=1,c2=sc; c2 <= m; c1++,c2++){
				if (sr*sc == 2) dp[r1][c1][r2][c2] = (a[r1][c1] == a[r2][c2]) ? 0 : 1;
				else {
					dp[r1][c1][r2][c2] = INF;
					if (sc%2){for(k=r1+1;k<r2;k+=2) MN(dp[r1][c1][r2][c2],dp[r1][c1][k][c2]+dp[k+1][c1][r2][c2]);}
					else for(k=r1;k<r2;++k) MN(dp[r1][c1][r2][c2],dp[r1][c1][k][c2]+dp[k+1][c1][r2][c2]);
					if (sr%2){for(k=c1+1;k<c2;k+=2) MN(dp[r1][c1][r2][c2],dp[r1][c1][r2][k]+dp[r1][k+1][r2][c2]);}
					else for(k=c1;k<c2;++k) MN(dp[r1][c1][r2][c2],dp[r1][c1][r2][k]+dp[r1][k+1][r2][c2]);
					assert(dp[r1][c1][r2][c2] != INF);
				}
//				printf("dp[%d][%d][%d][%d] = %d\n",r1,c1,r2,c2,dp[r1][c1][r2][c2]);
			}
		}
	}
	printf("%d\n",dp[1][1][n][m]);
	
	return 0;
}
