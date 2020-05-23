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

/** Clear Multiple Edges (including self loops) **/
/* Complexity : O(|V| + |E|) */
void clearMultipleEdges(int n, vector<int> *AdjList){
	int visited[n+5];
	REP(i, n) {
		visited[i] = 0;
	}
	REP(i, n) {
		vector<int> temp;
		FORIT(it, AdjList[i]) {
			if (!visited[*it] && *it != i){
				temp.PB(*it);
				visited[*it] = 1;
			}
		}
		AdjList[i] = temp;
		FORIT(it, AdjList[i]) {
			visited[*it] = 0;
		}
	}
}

/** Articulation Point **/
/* complexity : O(|V| + |E|) */
void articulationPointDFS(int u, vector<int> *AdjList, int *dfs_low, int *dfs_num, int *dfs_parent, int *articulation_vertex, int &dfsRoot, int &rootChildren){
	static int dfsNumberCounter;
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (int j = 0; j < (int)AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if (dfs_num[v] == -1){
			dfs_parent[v] = u;
			if (u == dfsRoot) rootChildren++;
			articulationPointDFS(v,AdjList,dfs_low,dfs_num,dfs_parent,articulation_vertex,dfsRoot,rootChildren);
			if (dfs_low[v] >= dfs_num[u]){
				articulation_vertex[u] = 1;
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}
		else if (v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
		}
	}
}
vector<int> articulationPoint(int n, vector<int> *AdjList){
	int dfs_num[n+5], dfs_low[n+5], dfs_parent[n+5], articulation_vertex[n+5];
	for (int i = 0; i < n; ++i){
		dfs_num[i] = -1;
		dfs_low[i] = dfs_parent[i] = articulation_vertex[i] = 0;
	}
	for (int i = 0; i < n; ++i){
		if (dfs_num[i] == -1){
			int dfsRoot = i, rootChildren = 0;
			articulationPointDFS(i,AdjList,dfs_low,dfs_num,dfs_parent,articulation_vertex,dfsRoot,rootChildren);
			articulation_vertex[dfsRoot] = (rootChildren > 1);
		}
	}
	vector<int> res;
	for (int i = 0; i < n; ++i){
		if (articulation_vertex[i]) res.push_back(i);
	}
	return res;
}
void articulationPointDFS(int u, vector< pair<int,int> > *AdjList, int *dfs_low, int *dfs_num, int *dfs_parent, int *articulation_vertex, int &dfsRoot, int &rootChildren){
	static int dfsNumberCounter;
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (int j = 0; j < (int)AdjList[u].size(); j++){
		int v = AdjList[u][j].first;
		if (dfs_num[v] == -1){
			dfs_parent[v] = u;
			if (u == dfsRoot) rootChildren++;
			articulationPointDFS(v,AdjList,dfs_low,dfs_num,dfs_parent,articulation_vertex,dfsRoot,rootChildren);
			if (dfs_low[v] >= dfs_num[u]){
				articulation_vertex[u] = 1;
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}
		else if (v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
		}
	}
}
vector<int> articulationPoint(int n, vector< pair<int,int> > *AdjList){
	int dfs_num[n+5], dfs_low[n+5], dfs_parent[n+5], articulation_vertex[n+5];
	for (int i = 0; i < n; ++i){
		dfs_num[i] = -1;
		dfs_low[i] = dfs_parent[i] = articulation_vertex[i] = 0;
	}
	for (int i = 0; i < n; ++i){
		if (dfs_num[i] == -1){
			int dfsRoot = i, rootChildren = 0;
			articulationPointDFS(i,AdjList,dfs_low,dfs_num,dfs_parent,articulation_vertex,dfsRoot,rootChildren);
			articulation_vertex[dfsRoot] = (rootChildren > 1);
		}
	}
	vector<int> res;
	for (int i = 0; i < n; ++i){
		if (articulation_vertex[i]) res.push_back(i);
	}
	return res;
}
/** end of articulation point **/

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
vector<int> bridge(int n, vector< pair<int,int> > *AdjList){
	int dfs_num[n+5], dfs_low[n+5], dfs_parent[n+5];
	int m = 0;
	for (int i = 0; i < n; ++i) m += (int)AdjList[i].size();
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
	/* removing multiple edges, takes O(|E| log |E|)) */
	map <pair<int,int>,int> seen;
	for (int i = 0; i < n; ++i){
		for (vector< pair<int,int> >::iterator it = AdjList[i].begin(); it != AdjList[i].end(); ++it){
			seen[make_pair(min(i,it->first),max(i,it->first))]++;
		}
	}
	for (int i = 0; i < n; ++i){
		for (vector< pair<int,int> >::iterator it = AdjList[i].begin(); it != AdjList[i].end(); ++it){
			if (seen[make_pair(min(i,it->first),max(i,it->first))] > 2){
				bridgeList[it->second] = 0;
			}
		}
	}
	vector<int> res;
	for (int i = 0; i < m; ++i){
		if (bridgeList[i]) res.push_back(i);
	}
	return res;
}

/** biconnected components **/
//TO DO

/** Tarjan's Directed Strongly Connected Component **/
/* complexity : O(|V| + |E|) */
void directedSCCDFS(int u, vector<int> *AdjList, int *dfs_low, int *dfs_num, int *visited, vector< vector<int> > &SCCList, vector<int> &s){
	static int dfsNumberCounter;
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	s.push_back(u);
	visited[u] = 1;
	for (int j = 0; j < (int)AdjList[u].size(); ++j){
		int v = AdjList[u][j];
		if (dfs_num[v] == -1){
			directedSCCDFS(v,AdjList,dfs_low,dfs_num,visited,SCCList,s);
		}
		if (visited[v]){
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}
	}
	if (dfs_low[u] == dfs_num[u]){
		vector<int> temp;
		int v = -1;
		while (u != v){
			v = s.back(); s.pop_back(); visited[v] = 0;
			temp.push_back(v);
		}
		SCCList.push_back(temp);
	}
}
vector< vector<int> > directedSCC(int n, vector<int> *AdjList){
	int dfs_num[n+5], dfs_low[n+5], visited[n+5];
	vector< vector<int> > SCCList;
	vector<int> s;
	for (int i = 0; i < n; ++i){
		dfs_num[i] = -1;
		dfs_low[i] = visited[i] = 0;
	}
	for (int i = 0; i < n; ++i){
		if (dfs_num[i] == -1){
			directedSCCDFS(i,AdjList,dfs_low,dfs_num,visited,SCCList,s);
		}
	}
	return SCCList;
}

/** Maximum Flow **/
/* Edmond Karp | complexity : O(|V|*(|V|+|E|)) */
void augment(int v, int minEdge, int **res, int &s, int &f, vector<int> &p){
	if (v == s) { f = minEdge;return; }
	else if (p[v] != -1) { 
		augment(p[v],min(minEdge,res[p[v]][v]),res,s,f,p); res[p[v]][v]-= f; res[v][p[v]] += f; 
	}
}
int maxFlowEdmondKarp(int n, int source, int target, int **res) {
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
/* Ford Fulkerson | complexity : O(|V|^2 F) */
int findPath(int n, int **res, int *vis, int u, int t, int f){
	if (u == t) return f;
	vis[u] = 1;
	for (int v = 0; v < n; ++v){
		if (!vis[v] && res[u][v] > 0){
			int df = findPath(n, res, vis, v, t, min(f,res[u][v]));
			if (df > 0){
				res[u][v] -= df;
				res[v][u] += df;
				return df;
			}
		}
	}
	return 0;
}
int maxFlowFordFulkerson(int n, int source, int target, int **res) {
#ifndef INF
	const int INF = 1000000000;
#endif
	int vis[n+5];
	for (int flow = 0;;){
		for (int i = 0; i < n; ++i) vis[i] = 0;
		int df = findPath (n, res, vis, source, target, INF);
		if (df == 0) return flow;
		flow += df;
	}
}
/* WARNING: res will be modified during the process */

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
const int maxnodes = 200000;

int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

struct Edge {
	int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s, int t, int cap, int cost) {
	Edge a = {t, 0, cap, cost, graph[t].size()};
	Edge b = {s, 0, 0, -cost, graph[s].size()};
	graph[s].push_back(a);
	graph[t].push_back(b);
}

void bellmanFord(int s, int dist[]) {
	fill(dist, dist + nodes, 1000000000);
	dist[s] = 0;
	int qt = 0;
	q[qt++] = s;
	for (int qh = 0; (qh - qt) % nodes != 0; qh++) {
		int u = q[qh % nodes];
		inqueue[u] = false;
		for (int i = 0; i < (int) graph[u].size(); i++) {
			Edge &e = graph[u][i];
			if (e.cap <= e.f) continue;
			int v = e.to;
			int ndist = dist[u] + e.cost;
			if (dist[v] > ndist) {
				dist[v] = ndist;
				if (!inqueue[v]) {
					inqueue[v] = true;
					q[qt++ % nodes] = v;
				}
			}
		}
	}
}

pii minCostFlow(int s, int t, int maxf) {
	// bellmanFord can be safely commented if edges costs are non-negative
	bellmanFord(s, pot);
	int flow = 0;
	int flowCost = 0;
	while (flow < maxf) {
		priority_queue<ll, vector<ll>, greater<ll> > q;
		q.push(s);
		fill(prio, prio + nodes, 1000000000);
		prio[s] = 0;
		curflow[s] = 1000000000;
		while (!q.empty()) {
			ll cur = q.top();
			int d = cur >> 32;
			int u = cur;
			q.pop();
			if (d != prio[u]) continue;
			for (int i = 0; i < (int) graph[u].size(); i++) {
				Edge &e = graph[u][i];
				int v = e.to;
				if (e.cap <= e.f) continue;
				int nprio = prio[u] + e.cost + pot[u] - pot[v];
				if (prio[v] > nprio) {
					prio[v] = nprio;
					q.push(((ll) nprio << 32) + v);
					prevnode[v] = u;
					prevedge[v] = i;
					curflow[v] = min(curflow[u], e.cap - e.f);
				}
			}
		}
		if (prio[t] == 1000000000) break;
		for (int i = 0; i < nodes; i++) pot[i] += prio[i];
		int df = min(curflow[t], maxf - flow);
		flow += df;
		for (int v = t; v != s; v = prevnode[v]) {
			Edge &e = graph[prevnode[v]][prevedge[v]];
			e.f += df;
			graph[v][e.rev].f -= df;
			flowCost += df * e.cost;
		}
	}
	return make_pair(flow, flowCost);
}

/* usage example:
 * addEdge (source, target, capacity, cost)
 * minCostFlow(source, target, INF) -> <flow, flowCost>
 */

/** Dijkstra's Single Source Shortest Path **/
/* complexity : O(|E| log |V|) */
template <class T> T dijkstra(vector<int> adjList[], vector<T> edgeWeight[], int n, int v1, int v2){
#ifndef INF
	const T INF = numeric_limits<T>::max( )/(T)2;
#endif
	int vis[n+5];
	T dis[n+5], d;
	priority_queue <pair<T,int> > pq;
	for (int i=0; i<n; ++i){
		vis[i] = 0;
		dis[i] = i==v1 ? 0 : INF;
	}
	pq.push(make_pair(0,v1));
	while (!pq.empty()){
		int v = pq.top().second;
		T d = -pq.top().first;
		pq.pop();
		if (v==v2) return d;
		if (vis[v] || d>dis[v]) continue;
		vis[v] = 1;
		for (int i=0; i<(int)adjList[v].size(); ++i){
			int vv = adjList[v][i];
			if (dis[vv] > d+edgeWeight[v][i]){
				dis[vv] = d+edgeWeight[v][i];
				pq.push(make_pair(-dis[vv],vv));
			}
		}
	}
	return INF;
}

/** Lowest Common Ancestor **/
/* complexity : LCApre : O(N log N), LCAquery : O(log N) */
/* legend:
 * N : number of vertices. WARNING: zero based
 * T : direct parent. T[v] is parent of v
 * L : L[v] is the level of v. zero/one based is okay
 * P : dp table of size [MAXN][LOGMAXN]. P[v][i] is the 2^i-th parent of v
 */
void LCApre(int N, int *T, int **P){
	int i, j;

	//we initialize every element in P with -1
	for (i = 0; i < N; i++)
		for (j = 0; 1 << j < N; j++)
			P[i][j] = -1;

	//the first ancestor of every node i is T[i]
	for (i = 0; i < N; i++)
		P[i][0] = T[i];
	
	//bottom up dynamic programing
	for (j = 1; 1 << j < N; j++)
		for (i = 0; i < N; i++)
			if (P[i][j - 1] != -1)
				P[i][j] = P[P[i][j - 1]][j - 1];
}
int LCAquery(int N, int **P, int *T, int *L, int p, int q){
	int log, i;
	
	//if p is situated on a higher level than q then we swap them
	if (L[p] < L[q]) swap(p,q);
	
	//we compute the value of [log(L[p)]
	for (log = 1; 1 << log <= L[p]; log++);
	log--;
	
	//we find the ancestor of node p situated on the same level
	//with q using the values in P
	for (i = log; i >= 0; i--)
		if (L[p] - (1 << i) >= L[q])
			p = P[p][i];
	
	if (p == q) return p;
	
	//we compute LCA(p, q) using the values in P
	for (i = log; i >= 0; i--)
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];
	
	return T[p];
}

int main(){
	
	return 0;
}
