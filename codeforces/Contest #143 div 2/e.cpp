#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

inline int StringToInt(string s){
	int x;
	stringstream(s) >> x;
	return x;
}
inline string IntToString(int x){
	stringstream s;
	s << x;
	return s.str();
}

/* -------------- end of azaky's template -------------- */

void dfs(int par, int v);
void dfs2(int v);

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; ++i){
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(visit,0,sizeof(visit));
	nc = 0;
	dfs(0,1);
	nv = 0;
	dfs2(1);
	
	return 0;
}

void dfs(int par, int v){
	if (visit[v]){
		cycle[v] = ++nc;
		u = child[v];
		while (u != v){
			cycle[u] = nc;
			u = child[u];
		}
		return;
	}
	visit[v] = true;
	for (int i=0; i<(int)adj[v].size(); ++i){
		if (adj[v][i]==par) continue;
		child[v] = adj[v][i];
		dfs(v,adj[v][i]);
	}
}

void dfs2(int v){
	if (visit[v]) return;
	if (cycle[v]){
		if (!vv[v]) record[cycle[v]] = ++nv;
		vv[v] = record[cycle[v]];
	}
	else vv[v] = ++nv;
	for (int 
