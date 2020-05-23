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

#define INF 1000100
int ntc, n, m, a, b, x, y, dp[111][222], visit[111][222];
vector<pair<int,pii> > adj[111];

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d%d%d",&n,&m,&a,&b);
		REP(i,n) adj[i].clear();
		REP(i,m){
			int u, v, p, q;
			scanf("%d%d%d%d",&u,&v,&p,&q);
			u--; v--;
			adj[u].PB(MP(v,MP(p,q)));
			adj[v].PB(MP(u,MP(p,q)));
		}
		scanf("%d%d",&x,&y);
		x--; y--;
		REP(i,n) REP(j,2*n){
			dp[i][j] = INF;
			visit[i][j] = 0;
		}
		dp[x][0] = 0;
		priority_queue< pair<pii,int> > pq;
		pq.push(MP(MP(0,0),x));
		while (!pq.empty()){
			int p = -pq.top().A.A;
			int q = -pq.top().A.B;
			int v = pq.top().B;
			pq.pop();
			if (visit[v][p]) continue;
			//printf("v = %d, p = %d, q = %d\n",v, p, q);
			//assert(dp[v][p] == q);
			visit[v][p] = 1;
			FORIT(it,adj[v]){
				if (dp[v][p] + (it->B).B < dp[it->A][p+(it->B).A]){
					dp[it->A][p+(it->B).A] = dp[v][p] + (it->B).B;
					pq.push(MP(MP(-p-(it->B).A,-dp[it->A][p+(it->B).A]),it->A));
				}
			}
		}
		int ans = INF;
		REP(j,2*n) if (a*j + b*dp[y][j] < ans) ans = a*j + b*dp[y][j];
		printf("%d\n",ans);
	}
		
	return 0;
}
