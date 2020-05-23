#include <vector>
#include <map>
#include <set>
#include <queue>
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
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long LL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-i; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) (s.find(a) != s.end())

/* -------------- end of azaky's template -------------- */

int n,m,a[40][40][40][40];

int main(){
	//freopen("hyper.in","r",stdin);
	//freopen("hyper.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	REP(i,n) REP(j,n) REP(k,n) REP(l,n) scanf("%d",&a[i][j][k][l]);
	FOR(size,1,m-1) REP(i,n-size) REP(j,n-size) REP(k,n-size) REP(l,n-size) REP(mask,16) a[i][j][k][l] = min(a[i][j][k][l],a[i+(((1<<0)&mask)>>0)][j+(((1<<1)&mask)>>1)][k+(((1<<2)&mask)>>2)][l+(((1<<3)&mask)>>3)]);
	REP(i,n-m+1) REP(j,n-m+1) REP(k,n-m+1) REP(l,n-m+1) printf("%d ",a[i][j][k][l]);
	
	return 0;
}
