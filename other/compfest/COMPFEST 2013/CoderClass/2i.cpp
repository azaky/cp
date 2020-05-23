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

#define MAXN 1111
#define INF 1000000000000000000LL

int ntc, n, m;
ll d, a, b, c, p, r[MAXN*MAXN], x[MAXN][MAXN], s[MAXN][MAXN], sdiag[MAXN][MAXN], ans;
ll sum(int ra, int ca, int rb, int cb){return s[rb][cb]-s[rb][ca-1]-s[ra-1][cb]+s[ra-1][ca-1];}

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d",&n,&m);
		cin >> d >> a >> b >> c >> p;
		r[0] = d;
		FOR(i,1,n*n) r[i] = (a*r[i-1]+b) % c;
		FOR(i,1,n) FOR(j,1,n) x[i][j] = r[n*(i-1)+(j-1)]-p;
		FOR(i,1,n) FOR(j,1,n) s[i][j] = s[i-1][j]+s[i][j-1]+x[i][j]-s[i-1][j-1];
		FOR(i,1,n) FOR(j,1,n) sdiag[i][j] = sdiag[i-1][j-1] + sum(i,max(j-i,0)+1,i,j);
		ans = -INF;
		FOR(i,m,n) FOR(j,m,n) MX(ans,sdiag[i][j]-sdiag[i-m][j-m]-sum(i-m+1,max(j-i,0)+1,i,j-m));
		cout << ans << endl;
	}
	
	return 0;
}
