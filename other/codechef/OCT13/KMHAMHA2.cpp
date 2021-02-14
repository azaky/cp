/* DELAPAN.3gp */
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

/* -------------- end of DELAPAN.3gp's template -------------- */

/** Maximum Flow **/
/* complexity : O(|V|*(|V|+|E|)) */
/*
void augment(int v, int minEdge, int **res, int &s, int &f, vector<int> &p){
	if (v == s) { f = minEdge;return; }
	else if (p[v] != -1) { 
		augment(p[v],min(minEdge,res[p[v]][v]),res,s,f,p); res[p[v]][v]-= f; res[v][p[v]] += f; 
	}
}
int maxFlow(int n, int source, int target, int **res) {
	int mf = 0;
#ifndef INF
	const int INF = 1000000000;
#endif
	while (1) {
		int f = 0;
		vector<int> dist(n+5,INF); dist[source] = 0; queue<int> q; q.push(source);
		vector<int> p;
		p.assign(n+5,-1);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == target) break;
			for (int v = 0; v < n; v++)
				if (res[u][v] > 0 && dist[v] == INF)
					dist[v] = dist[u]+ 1, q.push(v), p[v] = u;
		}
		augment(target,INF,res,source,f,p);
		if (f == 0) break;
		mf += f;
	}
	return mf;
}
*/
/* complexity : O(|V|^2*f) */
int findPath(int n, int cap[][2111], int vis[], int u, int t, int f){
	if (u == t){
		return f;
	}
	vis[u] = 1;
	for (int v = 0; v < n; ++v){
		if (!vis[v] && cap[u][v] > 0){
			int df = findPath(n,cap,vis,v,t,min(f,cap[u][v]));
			if (df > 0){
				cap[u][v] -= df;
				cap[v][u] += df;
				return df;
			}
		}
	}
	return 0;
}
int maxFlow(int n, int source, int target, int cap[][2111]){
	int vis[n+5];
	for (int flow = 0;;){
		memset(vis,0,sizeof(vis));
		int df = findPath(n,cap,vis,source,target,1000000);
		if (df == 0){
			return flow;
		}
		flow += df;
	}
}

int ntc, n, nr, nc, adj[2111][2111];
pii a[2111];

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		map<int,int> r, c;
		nr = 0; nc = 0;
		scanf("%d",&n);
		REP(i,n){
			scanf("%d%d",&a[i].A,&a[i].B);
			//normalize
			if (!EXIST(a[i].A,r)) r[a[i].A] = ++nr;
			a[i].A = r[a[i].A];
			if (!EXIST(a[i].B,c)) c[a[i].B] = ++nc;
			a[i].B = c[a[i].B];
		}
		/* build graph */
		RESET(adj,0);
		REP(i,n) adj[a[i].A][a[i].B+nr] = 1;
		FOR(i,1,nr) adj[0][i] = 1;
		FOR(i,nr+1,nr+nc) adj[i][nr+nc+1] = 1;
		printf("%d\n",maxFlow(nr+nc+2,0,nc+nr+1,adj));
	}
	
	return 0;
}
