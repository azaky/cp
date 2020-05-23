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

#define INF 1000000000
#define MAXN 1010
int n, m, p[MAXN], s, e, c, path[MAXN][111], q;
vector<pii> adj[MAXN];

int main(){
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&p[i]);
	REP(i,m){
		int x, y, z;
		scanf("%d%d%d",&x,&y,&z);
		adj[x].PB(MP(y,z));
		adj[y].PB(MP(x,z));
	}
	scanf("%d",&q);
	while (q--){
		scanf("%d%d%d",&c,&s,&e);
		priority_queue <pair<int,pii> > pq;
		pq.push(MP(0,MP(s,0)));
		REP(i,n) REP(j,c+1) path[i][j] = INF;
		path[s][0] = 0;
		while (!pq.empty()){
			int cost = -pq.top().A;
			int v = pq.top().B.A;
			int cap = pq.top().B.B;
			pq.pop();
			if (path[v][cap] != cost) continue;
			if (v == e) {
				assert(cap == 0);
				break;
			}
//			printf("v = %d, cap = %d, cost = %d\n",v,cap,cost);
			//ngisi bensin sampe penuh~
			while (cap <= c){
				FORIT(it,adj[v]){
					if (cap >= it->B){
						if (cost < path[it->A][cap-it->B]){
							path[it->A][cap-it->B] = cost;
							pq.push(MP(-cost,MP(it->A,cap-it->B)));
						}
					}
				}
				cap ++;
				cost += p[v];
			}
		}
		if (path[e][0] == INF) puts("impossible");
		else printf("%d\n",path[e][0]);
	}
	
	return 0;
}
