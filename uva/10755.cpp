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

#define MAXN 50
int ntc, a, b, c;
ll v[MAXN][MAXN][MAXN], sum[MAXN][MAXN][MAXN];

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d%d",&a,&b,&c);
		FOR(i,1,a) FOR(j,1,b) FOR(k,1,c) scanf("%lld",&v[i][j][k]);
		FOR(i,1,a) FOR(j,1,b) FOR(k,1,c){
			sum[i][j][k] = sum[i][j][k-1] + sum[i][j-1][k] + sum[i-1][j][k] - sum[i-1][j-1][k] - sum[i-1][j][k-1] - sum[i][j-1][k-1] + sum[i-1][j-1][k-1] + v[i][j][k];
		}
		ll ans = -1000000000000000000LL;
		FOR(i,0,a-1) FOR(i1,i+1,a) FOR(j,0,b-1) FOR(j1,j+1,b) FOR(k,0,c-1) FOR(k1,k+1,c){
			if ((sum[i1][j1][k1]-sum[i1][j1][k]-sum[i1][j][k1]-sum[i][j1][k1]+sum[i1][j][k]+sum[i][j1][k]+sum[i][j][k1]-sum[i][j][k]) > ans){
				ans = (sum[i1][j1][k1]-sum[i1][j1][k]-sum[i1][j][k1]-sum[i][j1][k1]+sum[i1][j][k]+sum[i][j1][k]+sum[i][j][k1]-sum[i][j][k]);
			}
		}
		printf("%lld\n",ans);
		if (itc != ntc) puts("");
	}
	
	return 0;
}
