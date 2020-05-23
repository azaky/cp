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

#define MAXV 100100
#define MAXE 300300

int n, m, l, r, visited[MAXV];
pii edge[MAXE];
vector<int> adj[MAXV];

bool bipartite;

void dfs (int v, int color) {
	if (visited[v]) {
		if (visited[v] != color) bipartite = false;
	}
	else {
		visited[v] = color;
		FORIT(it,adj[v]) dfs(*it,3-color);
	}
}

bool isBipartite (int k) {
	bipartite = true;
	
	/* create graph */
	FOR(i,1,k) {
		adj[edge[i].A].PB(edge[i].B);
		adj[edge[i].B].PB(edge[i].A);
	}
	
	/* test bipartite */
	RESET(visited,0);
	FOR(i,1,n) {
		if (!visited[i]) dfs(i,1);
	}
	
	/* delete graph */
	FOR(i,1,n) {
		while (SZ(adj[i])) adj[i].pop_back();
	}
	
	return bipartite;
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m) {
		scanf("%d%d",&edge[i].A,&edge[i].B);
	}
	
	/* do binary search */
	l = 1; r = m;
	while (l < r) {
		int mid = (l+r) / 2;
		if (isBipartite(mid)) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	
	printf("%d\n",l);
	
	return 0;
}
