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

int ntc, n, m, x, a[222][222], s[222][222], v[222], dp[2];

int main(){
	scanf("%d",&ntc);
	REP(itc,ntc){
		scanf("%d%d",&n,&m);
		FOR(i,1,n) FOR(j,1,m){
			scanf("%d",&x);
			s[i][j] = s[i][j-1] + (x & 1);
		}
		int ans = 0;
		FOR(l,1,m) FOR(r,l,m){
			FOR(i,1,n) v[i] = (v[i-1] + s[i][r] - s[i][l-1]) & 1;
			dp[0] = 1; dp[1] = 0;
			FOR(i,1,n) ans += dp[v[i]]++;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
