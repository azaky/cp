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

#define INF 1000000000

int l, n, a[111], dp[111][111];

int MinCut(int x, int y){
	if (y-x == 1) return 0;
	if (dp[x][y] != INF) return dp[x][y];
	FOR(i,x+1,y-1) MN(dp[x][y],MinCut(x,i)+MinCut(i,y));
	dp[x][y] += a[y]-a[x];
	return dp[x][y];
}

int main(){
	scanf("%d",&l);
	if (l == 0) return 0;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	a[0] = 0; a[n+1] = l;
	FOR(i,0,n+1) FOR(j,0,n+1) dp[i][j] = INF;
	printf("The minimum cutting is %d.\n",MinCut(0,n+1));
	
	main();
	
	return 0;
}
