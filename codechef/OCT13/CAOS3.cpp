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

#define MAXN 25
int ntc, r, c, a[MAXN][MAXN], _l[MAXN][MAXN], _r[MAXN][MAXN], _u[MAXN][MAXN], _d[MAXN][MAXN], m[MAXN][MAXN], v[MAXN][MAXN][MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];
char s[100];

int grundy(int ra, int ca, int rb, int cb){
	if (v[ra][ca][rb][cb]) return dp[ra][ca][rb][cb];
	v[ra][ca][rb][cb] = 1;
	set<int> s;
	FOR(i,ra,rb) FOR(j,ca,cb){
		if (!m[i][j]) continue;
		s.insert(grundy(ra,ca,i-1,j-1) ^ grundy(ra,j+1,i-1,cb) ^ grundy(i+1,ca,rb,j-1) ^ grundy(i+1,j+1,rb,cb));
	}
	dp[ra][ca][rb][cb] = 0;
	while (EXIST(dp[ra][ca][rb][cb],s)) dp[ra][ca][rb][cb]++;
//	printf("dp[%d][%d][%d][%d] = %d\n",ra,ca,rb,cb,dp[ra][ca][rb][cb]);
	return dp[ra][ca][rb][cb];
}

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%d%d",&r,&c);
		FOR(i,0,r+1) FOR(j,0,c+1) a[i][j] = 1;
		FOR(i,1,r){
			scanf("%s",s);
			FOR(j,1,c) a[i][j] = s[j-1] == '#';
		}
		FOR(i,1,r){
			FOR(j,0,c+1) _l[i][j] = a[i][j] ? 0 : _l[i][j-1]+1;
			FORD(j,c+1,0) _r[i][j] = a[i][j] ? 0 : _r[i][j+1]+1;
		}
		FOR(j,1,c){
			FOR(i,0,r+1) _u[i][j] = a[i][j] ? 0 : _u[i-1][j]+1;
			FORD(i,r+1,0) _d[i][j] = a[i][j] ? 0 : _d[i+1][j]+1;
		}
		FOR(i,1,r) FOR(j,1,c){
			m[i][j] = (_l[i][j] >= 3 && _r[i][j] >= 3 && _u[i][j] >= 3 && _d[i][j] >= 3);
		}
		RESET(v,0);
		if (grundy(1,1,r,c)) puts("Asuna"); else puts("Kirito");
	}
	
	return 0;
}
