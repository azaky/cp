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
int n, a, b, vis[maxn][2], dp[maxn][2];
vector <int> adj[maxn];

int tree(int par, int v, int ada){
	if (vis[v][ada]) return dp[v][ada];
	vis[v][ada] = 1;
	dp[v][ada] = ada;
	if (ada) for (int i=0; i<(int)adj[v].size(); ++i)
		if (adj[v][i] != par) dp[v][ada] += min(tree(v,adj[v][i],1),tree(v,adj[v][i],0));
		else;
	else for (int i=0; i<(int)adj[v].size(); ++i)
		if (adj[v][i] != par) dp[v][ada] += tree(v,adj[v][i],1);
	return dp[v][ada];
}	

int main(){
	scanf("%d",&n);
	for (int i=1; i<n; ++i){
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	printf("%d",min(tree(0,1,0),tree(0,1,1)));
	return 0;
}
