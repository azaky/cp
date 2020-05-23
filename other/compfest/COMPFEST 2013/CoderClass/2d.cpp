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

#define SHIFT 1000
int ntc, n, m, dx[2222], dy[2222], a[1111][1111];

int main(){
	scanf("%d",&ntc);
	REP(itc,ntc){
		scanf("%d%d",&n,&m);
		FOR(i,2,n+m) dx[i] = 0;
		FOR(i,1-m,n-1) dy[i+SHIFT] = 0;
		FOR(i,1,n) FOR(j,1,m){
			scanf("%d",&a[i][j]);
			dx[i+j] += a[i][j];
			dy[i-j+SHIFT] += a[i][j];
		}
		int ans = 0;
		FOR(i,1,n) FOR(j,1,m) MX(ans,dx[i+j]+dy[i-j+SHIFT]-2*a[i][j]);
		cout << ans << endl;
	}
	
	return 0;
}
