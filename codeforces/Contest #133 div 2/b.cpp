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

int n,m,ans,cycle,con[111][111],e[111],f[111],vis[111];

void dfs(int p,int v,int c){
	if (vis[v]){
		debug("voila! %d %d\n",v,c);
		if (!cycle) cycle = c;
		return;
	}
	vis[v] = 1;
	for (int i=0; i<n; ++i)
		if (con[v][i] && i!=p) dfs(v,i,c+1);
	return;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; ++i){
		scanf("%d%d",&e[i],&f[i]);
		--e[i]; --f[i];
		con[e[i]][f[i]] = 1;
		con[f[i]][e[i]] = 1;
	}
	for (int i=0; i<n; ++i){
		if (vis[i]) continue;
		cycle = 0;
		dfs(-1,i,0);
		if (cycle & 1) ans++;
		debug("%d %d\n",i,cycle);
	}
	if ((n-ans)&1) ans++;
	printf("%d\n",ans);
	return 0;
}
