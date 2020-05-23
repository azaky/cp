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

int ntc, n, m, a, b, c, d, p, r[1000100], x[1010][1010], y[1010][1010], sum[1010][1010];
int total(int a, int b, int c, int d){
	return sum[c][d] + sum[a-1][b-1] - sum[a-1][d] - sum[c][b-1];
}

int main(){
	scanf("%d",&ntc);
	REP(itc,ntc){
		scanf("%d%d",&n,&m);
		scanf("%d%d%d%d%d",&d,&a,&b,&c,&p);
		REP(i,n*n) r[i] = i == 0 ? d : (a*r[i-1] + b) % c;
		REP(i,n) REP(j,n) x[i+1][j+1] = (r[n*i+j] < p) ? 0 : 1;
		scanf("%d%d%d%d%d",&d,&a,&b,&c,&p);
		REP(i,m*m) r[i] = i == 0 ? d : (a*r[i-1] + b) % c;
		REP(i,m) REP(j,m) y[i+1][j+1] = (r[m*i+j] < p) ? 0 : 1;
//		FOR(i,1,n){FOR(j,1,n) printf("%d ",x[i][j]); puts("");}
//		FOR(i,1,m){FOR(j,1,m) printf("%d ",y[i][j]); puts("");}
		FOR(i,1,n) FOR(j,1,n) sum[i][j] = x[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		ll ans = 0;
		FOR(i,1,m) FOR(j,1,m){
			if (y[i][j] == 1) ans += (ll)((n-m+1)*(n-m+1) - total(i,j,n-m+i,n-m+j));
			else ans += (ll)total(i,j,n-m+i,n-m+j);
		}
		cout << ans << endl;
	}
	
	return 0;
}
