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
#include <limits>
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
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

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

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 2050
#define INF 1000000009
int ntc, p, m[MAXN], price[30][MAXN];
int dp[MAXN][30], visit[MAXN][30];

int calc(int v, int l, int r, int _i, int _j, int had){
	if (l == r) {
		if (had + m[l] >= p) return 0;
		return INF;
	}
	if (visit[v][had]) return dp[v][had];
	visit[v][had] = 1;
	dp[v][had] = INF;
	int mid = (l + r) >> 1;
	/* buy this ticket */
	MN(dp[v][had],price[_i][_j]+calc(2*v,l,mid,_i-1,2*_j,had+1)+calc(2*v+1,mid+1,r,_i-1,2*_j+1,had+1));
	/* don't buy */
	MN(dp[v][had],calc(2*v,l,mid,_i-1,2*_j,had)+calc(2*v+1,mid+1,r,_i-1,2*_j+1,had));
//	printf("[%d..%d] with had = %d: %d\n",l,r,had,dp[v][had]);
	return dp[v][had];
}

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d",&p);
		REP(i,(1<<p)) scanf("%d",&m[i]);
		REP(i,p) REP(j,(1<<(p-i-1))) scanf("%d",&price[i][j]);
		//dp[id_games][tickets_had]
		RESET(visit,0);
		printf("Case #%d: %d\n",itc,calc(1,0,(1<<p)-1,p-1,0,0));
	}
	
	return 0;
}
