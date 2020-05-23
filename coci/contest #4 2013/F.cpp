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

#define MAXV 333
#define MAXE 100100
#define INF 1000000000
int n, m, dm[MAXV][MAXV], ds[MAXV][MAXV], best[MAXV][MAXV];
vector<int> adj[MAXV];

int main(){
	scanf("%d%d",&n,&m);
	REP(i,m) {
		int _x, _y;
		scanf("%d%d",&_x,&_y);
		scanf("%d%d",&dm[_x][_y],&ds[_x][_y]);
		adj[_x].PB(_y);
	}
	
	/* dijkstra (?) */
	set <pii> pq; //<num_road,v>
	FOR(i,1,n) FOR(j,0,m) best[i][j] = -INF;
	best[1][0] = 0;
	pq.insert(MP(0,1));
	while (!pq.empty()) {
		pii now = *(pq.begin());
		pq.erase(now);
		int v = now.B;
		int num_road = now.A;
		int dd = best[v][num_road];
		
		//printf("v = %d, num_road = %d, dd = %d\n",v,num_road,dd);
		//system("pause");
		
		if (v == 1 && dd > 0) {
			printf("%d %d\n",num_road,dd);
			break;
		}
		
		FORIT(it,adj[v]) {
			if (dd + ds[v][*it] - dm[v][*it] > best[*it][num_road+1]) {
				best[*it][num_road+1] = dd + ds[v][*it] - dm[v][*it];
			}
			pq.insert(MP(num_road+1,*it));
		}
	}
	
	return 0;
}
