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
	for (int i = 0; i < n; ++i){
		visited[i] = 0;
	}
	for (int i = 0; i < n; ++i){
		vector<int> temp;
		for (vector<int>::iterator it = AdjList[i].begin(); it != AdjList[i].end(); ++it){
			if (!visited[*it] && *it != i){
				temp.push_back(*it);
				visited[*it] = 1;
			}
		}
		AdjList[i] = temp;
		for (vector<int>::iterator it = AdjList[i].begin(); it != AdjList[i].end(); ++it){
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
/* complexity : O(|V|*(|V|+|E|)) */
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

int n, m;
string names[50];
vector<int> adj[50];

int main(){
	for (int ntc = 1; ; ntc++){
		scanf("%d%d",&n,&m);
		if (n + m == 0) break;
		int _n = 0;
		map<string,int> hash;
		REP(i,n) adj[i].clear();
		REP(i,m){
			string s1, s2;
			cin >> s1 >> s2;
			if (!EXIST(s1,hash)) hash[s1] = _n++;
			if (!EXIST(s2,hash)) hash[s2] = _n++;
			int v1 = hash[s1], v2 = hash[s2];
			names[v1] = s1; names[v2] = s2;
			adj[v1].PB(v2);
		}
		clearMultipleEdges(n,adj);
		vector< vector<int> > ans = directedSCC(n,adj);
		if (ntc > 1) printf("\n");
		printf("Calling circles for data set %d:\n",ntc);
		for (int i = 0; i < SZ(ans); ++i){
			printf("%s",names[ans[i][0]].c_str());
			for (int j = 1; j < SZ(ans[i]); ++j) printf(", %s",names[ans[i][j]].c_str());
			printf("\n");
		}
	}
	
	return 0;
}
