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

const int MAXN = 2525;
const int INF = 1000000000;
int n,m,v1,v2,v,vv,a,b,c,path[MAXN],vis[MAXN];
vector <int> adj[MAXN],w[MAXN];

int main(){
	scanf("%d%d%d%d",&n,&m,&v1,&v2);
	for (int i=0; i<m; ++i){
		scanf("%d%d%d",&a,&b,&c);
		if (a==b) continue;
		adj[a].push_back(b); w[a].push_back(c);
		adj[b].push_back(a); w[b].push_back(c);
	}
	for (int i=0; i<=n; ++i) path[i] = INF;
	path[v1] = 0;
	while (1){
		v = 0;
		for (int i=1; i<=n; ++i)
			if (!vis[i] && path[i]<path[v]) v = i;
		if (v==v2 || v==0) break;
		vis[v] = 1;
		for (int i=0; i<(int)adj[v].size(); ++i){
			vv = adj[v][i];
			if (path[v]+w[v][i] < path[vv]) path[vv] = path[v]+w[v][i];
		}
	}
	printf("%d\n",path[v2]);
	return 0;
}
