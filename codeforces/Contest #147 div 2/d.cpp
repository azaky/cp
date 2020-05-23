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

const int maxn = 100100;
vector <int> adj[maxn];
int n, a[maxn], b[maxn], node[maxn][2];

void dfs(int v, int par);

int main(){
	scanf("%d",&n);
	if (n == 1){ printf("1\n1 1\n"); return 0;}
	for (int i=1; i<n; ++i){
		scanf("%d%d",&a[i],&b[i]);
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	dfs(1,0);
	printf("%d\n",n-1);
	for (int i=1; i<n; ++i) printf("2 %d %d\n",node[i][0],node[i][1]);
	for (int i=1; i<(int)adj[1].size(); ++i) printf("%d %d\n",adj[1][i]-1,adj[1][i-1]-1);
	for (int i=1; i<n; ++i)
		if (a[i] != 1 && b[i] != 1) printf("%d %d\n",a[i]-1,b[i]-1);
	return 0;
}

void dfs(int v, int par){
	if (v != 1){
		node[v-1][0] = v;
		node[v-1][1] = par;
	}
	int u;
	for (int i=0; i<(int)adj[v].size(); ++i){
		u = adj[v][i];
		if (u != par) dfs(u,v);
	}
}
