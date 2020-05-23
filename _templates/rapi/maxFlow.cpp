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

#define MAXN 1100
#define INF 0x3FFFFFFF

int res[MAXN][MAXN], vis[MAXN];

/** Maximum Flow **/
/* Edmond Karp | complexity : O(|V|*(|V|+|E|)) */
void augment(int v, int minEdge, int &s, int &f, vector<int> &p){
	if (v == s) { f = minEdge; return; }
	else if (p[v] != -1) { 
		augment(p[v],min(minEdge,res[p[v]][v]),s,f,p); res[p[v]][v]-= f; res[v][p[v]] += f; 
	}
}
int maxFlowEdmondKarp(int n, int source, int target) {
	int mf = 0;
	while (1) {
		int f = 0;
		vector<int> dist(n+5,INF);
		dist[source] = 0;
		queue<int> q; q.push(source);
		vector<int> p; p.assign(n+5,-1);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == target) break;
			for (int v = 0; v < n; v++)
				if (res[u][v] > 0 && dist[v] == INF)
					dist[v] = dist[u] + 1, q.push(v), p[v] = u;
		}
		augment(target,INF,source,f,p);
		if (f == 0) break;
		mf += f;
	}
	return mf;
}

/* Ford Fulkerson | complexity : O(|V|^2 F) */
int findPath(int n, int u, int t, int f){
	if (u == t) return f;
	vis[u] = 1;
	for (int v = 0; v < n; ++v){
		if (!vis[v] && res[u][v] > 0){
			int df = findPath(n, v, t, min(f,res[u][v]));
			if (df > 0){
				res[u][v] -= df;
				res[v][u] += df;
				return df;
			}
		}
	}
	return 0;
}
int maxFlowFordFulkerson(int n, int source, int target) {
	for (int flow = 0;;){
		for (int i = 0; i < n; ++i) vis[i] = 0;
		int df = findPath (n, source, target, INF);
		if (df == 0) return flow;
		flow += df;
	}
}
/* WARNING: res will be modified during the process */

int main() {
	return 0;
}