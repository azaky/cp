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

#define MAXN 200
int ntc, n, a[MAXN][MAXN], sum[MAXN][MAXN], ans, v[MAXN], vmax[MAXN], vmin[MAXN];

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d",&n);
		FOR(i,1,n) FOR(j,1,n) scanf("%d",&a[i][j]);
		FOR(i,n+1,2*n) FOR(j,1,n) a[i][j] = a[i-n][j];
		FOR(i,1,2*n) FOR(j,1,n) sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		ans = -1000000000;
		FOR(x,1,n) FOR(y,x,x+n-1){
			FOR(i,1,n) v[i] = sum[y][i]-sum[x-1][i]-sum[y][i-1]+sum[x-1][i-1];
			int total = 0;
			FOR(i,1,n) total += v[i];
			//finding max
			FOR(i,1,n) vmax[i] = max(v[i],v[i]+vmax[i-1]);
			//finding min
			FOR(i,1,n) vmin[i] = min(v[i],v[i]+vmin[i-1]);
			MX(ans,max(*max_element(vmax+1,vmax+n+1),total-*min_element(vmin+1,vmin+n+1)));
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
