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

#define MAXN 111
#define MAXW 555
int n, p, q, b[MAXN], d[MAXN], w[MAXN], dp[MAXW][MAXN], pre[MAXN][MAXW];
vector<pii> a[MAXN];

int main(){
	char subsoal[11]; scanf("%s %d",subsoal,&n);
	scanf("%d%d%d",&n,&p,&q);
	FOR(i,1,n) scanf("%d%d%d",&b[i],&d[i],&w[i]);
	FOR(i,1,n) a[w[i]].PB(MP(b[i],d[i]));
	//build pre table
	RESET(pre,-1);
	FOR(i,1,n) pre[i][0] = 0;
	FOR(i,1,n){
		FORD(j,p,b[i]){
			if (pre[w[i]][j-b[i]] != -1) MX(pre[w[i]][j],pre[w[i]][j-b[i]]+d[i]);
		}
	}
	//build dp table - flying table dp
	RESET(dp,-1);
	dp[0][0] = 0;
	FOR(k,1,n){
		FORD(i,n,1){
			FOR(it,1,p){
				if (pre[k][it] == -1) continue;
//				printf("warna = %d, berat = %d, daya = %d\n",k,it,pre[k][it]);
				FORD(j,p,it){
					if (dp[j-it][i-1] != -1) MX(dp[j][i],dp[j-it][i-1]+pre[k][it]);
				}
			}
		}
/*		FOR(i,1,p) FOR(j,1,n) if (dp[i][j] != -1){
			printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
		}
*/
	}
	int ans = -1;
	FOR(i,1,p) FOR(j,q,n) MX(ans,dp[i][j]);
	printf("%d\n",ans);
	
	return 0;
}
