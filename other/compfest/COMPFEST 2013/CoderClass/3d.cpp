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


#define INF 2000000000

int ntc, n, p, k, m, s, x[111], v[111], nc, nk, nm, ns, cost, dp[20][20][20];
struct grup{int k, m, s, cost;} a[111];
char tipe[111][11];
vector<pii> adj[111];

void fill(int u){
	if (v[u]) return; else v[u] = 1;
	if (tipe[u][0] == 'k') ++nk;
	if (tipe[u][0] == 'm') ++nm;
	if (tipe[u][0] == 's') ++ns;
	cost += 2*x[u];
	FORIT(it,adj[u]){
		cost += it->B;
		fill(it->A);
	}
}

int main(){
	scanf("%d",&ntc);
	REP(itc,ntc){
		scanf("%d%d%d%d%d",&n,&p,&k,&m,&s);
		REP(i,n) scanf("%s%d",tipe[i],&x[i]);
		REP(i,n){
			adj[i].clear();
			v[i] = 0;
		}
		REP(i,p){
			int _x, _y, _z;
			scanf("%d%d%d",&_x,&_y,&_z);
			--_x, --_y;
			adj[_x].PB(MP(_y,_z));
			adj[_y].PB(MP(_x,_z));
		}
		nc = 0;
		REP(i,n){
			if (v[i]) continue;
			nk = nm = ns = cost = 0;
			fill(i);
			a[nc].k = nk; a[nc].m = nm; a[nc].s = ns; a[nc].cost = cost/2;
			++nc;
		}
		FOR(ik,0,k) FOR(im,0,m) FOR(is,0,s) dp[ik][im][is] = -INF;
		dp[0][0][0] = 0;
		REP(i,nc) FORD(ik,k,a[i].k) FORD(im,m,a[i].m) FORD(is,s,a[i].s) if (dp[ik-a[i].k][im-a[i].m][is-a[i].s] != -INF) MX(dp[ik][im][is],dp[ik-a[i].k][im-a[i].m][is-a[i].s]+a[i].cost);
		if (dp[k][m][s] == -INF) puts("tidak mungkin");
		else printf("%d\n",dp[k][m][s]);
	}
	
	return 0;
}
