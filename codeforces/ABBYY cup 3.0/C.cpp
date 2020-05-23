#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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

#define INF 1000000
int dp[82][82][82][82], a[82][82];
int n, m;

int calc(int r1, int c1, int r2, int c2){
	int L = (abs(r2-r1+1)*abs(c2-c1+1));
	if (L % 2) return INF;
	if (dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
	if (L == 2){
		dp[r1][c1][r2][c2] = a[r1][c1] == a[r2][c2] ? 0 : 1;
		return dp[r1][c1][r2][c2];
	}
	int ret = INF;
	FOR(i,r1,r2-1) MN(ret,calc(r1,c1,i,c2)+calc(i+1,c1,r2,c2));
	FOR(i,c1,c2-1) MN(ret,calc(r1,c1,r2,i)+calc(r1,i+1,r2,c2));
	return dp[r1][c1][r2][c2] = ret;
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	FOR(i,1,n) FOR(j,1,m) FOR(k,1,n) FOR(l,1,m) dp[i][j][k][l] = -1;
	printf("%d\n",calc(1,1,n,m));
	
	return 0;
}
