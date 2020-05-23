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

#define MAXN 400400
int n, m, deg[MAXN], vis[MAXN], xnode;
vector<pii> adj[MAXN];
pii edge[MAXN];
vector<int> bridges;

int mark[MAXN], cost[MAXN], bdeg[MAXN];
vector<pii> badj[MAXN];

/** Bridge **/
/* complexity : O(|V| + |E| + |E| log |E|) */
void bridgeDFS(int u, vector< pair<int,int> > *AdjList, int *dfs_low, int *dfs_num, int *dfs_parent, int *bridgeList){
	static int dfsNumberCounter;
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (int j = 0; j < (int)AdjList[u].size(); j++){
		int v = AdjList[u][j].first;
		if (dfs_num[v] == -1){
			dfs_parent[v] = u;
			bridgeDFS(v,AdjList,dfs_low,dfs_num,dfs_parent,bridgeList);
			if (dfs_low[v] > dfs_num[u]){
				bridgeList[AdjList[u][j].second] = 1;
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}
		else if (v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
		}
	}
}
vector<int> bridge(int n, int m, vector< pair<int,int> > *AdjList){
	int dfs_num[n+5], dfs_low[n+5], dfs_parent[n+5];
	int bridgeList[m+5];
	for (int i = 0; i < n; ++i){
		dfs_num[i] = -1;
		dfs_low[i] = dfs_parent[i] = 0;
	}
	for (int i = 0; i < m; ++i){
		bridgeList[i] = 0;
	}
	for (int i = 0; i < n; ++i){
		if (dfs_num[i] == -1){
			bridgeDFS(i,AdjList,dfs_low,dfs_num,dfs_parent,bridgeList);
		}
	}
	vector<int> res;
	for (int i = 0; i < m; ++i){
		if (bridgeList[i]) res.push_back(1); else res.push_back(0);
	}
	return res;
}

void dfs(int v, int prevnode = -1, int prevedge = -1) {
	// printf("dfs(%d)\n", v);
	// fflush(stdout);
	if (vis[v]) {
		assert(prevedge != -1);
		if (edge[prevedge].A != prevnode) {
			swap(edge[prevedge].A, edge[prevedge].B);
		}
	} else {
		vis[v] = -1;
		mark[v] = xnode;
		cost[xnode]++;
		FORIT(it, adj[v]) {
			if (it->A == prevnode) continue;
			if (bridges[it->B]) continue;
			if (vis[it->A] != 1) {
				if (edge[it->B].A != v) {
					swap(edge[it->B].A, edge[it->B].B);
				}
				dfs(it->A, v, it->B);
			}
		}
		vis[v] = 1;
	}
}

void bdfs(int v, int prevnode = -1) {
	// printf("bdfs(%d), cost = %d\n", v, cost[v]);
	FORIT(it, badj[v]) {
		if (it->A == prevnode) continue;
		if (mark[edge[it->B].B] != v) {
			swap(edge[it->B].A, edge[it->B].B);
		}
		bdfs(it->A, v);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	REP(i, m) {
		scanf("%d%d", &edge[i].A, &edge[i].B);
		edge[i].A--;
		edge[i].B--;
		adj[edge[i].A].PB(MP(edge[i].B, i));
		adj[edge[i].B].PB(MP(edge[i].A, i));
		deg[edge[i].A]++;
		deg[edge[i].B]++;
	}

	bridges = bridge(n, m, adj);
	// puts("BRIDGES");
	// FORIT(it, bridges) printf("%d ", *it); puts("");

	xnode = 0;
	REP(i, n) {
		if (!vis[i]) {
			dfs(i);
			xnode++;
		}
	}
	REP(i, m) {
		if (!bridges[i]) continue;
		int u = edge[i].A, v = edge[i].B;
		badj[mark[u]].PB(MP(mark[v], i));
		badj[mark[v]].PB(MP(mark[u], i));
		bdeg[mark[u]]++;
		bdeg[mark[v]]++;
	}

	// pick the most as root
	int iroot = -1;
	REP(i, xnode) {
		if (iroot == -1 || cost[i] > cost[iroot]) {
			iroot = i;
		}
	}
	if (iroot != -1) {
		// printf("iroot = %d\n", iroot);
		bdfs(iroot);
	} else {
		assert(false);
		iroot = 0;
	}

	printf("%d\n", cost[iroot]);
	REP(i, m) {
		printf("%d %d\n", edge[i].A + 1, edge[i].B + 1);
	}
	
	return 0;
}