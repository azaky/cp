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

const int MAXN = 505;
const int INF = 123456789;
int n,l,t,v1,v2,d,v,vv,a,b,dis[MAXN][2],vis[MAXN][2];
vector <int> tol[MAXN],adj[MAXN];
priority_queue <pair<int,pair<int,int> > > pq;

int main(){
	scanf("%d%d%d%d%d",&n,&l,&t,&v1,&v2);
	for (int i=0; i<l; ++i){
		scanf("%d%d",&a,&b);
		if (a==b) continue;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i=0; i<t; ++i){
		scanf("%d%d",&a,&b);
		if (a==b) continue;
		tol[a].push_back(b);
		tol[b].push_back(a);
	}
	//pq <-distance,<v,tol>>
	pq.push(make_pair(0,make_pair(v1,0)));
	for (int i=1; i<=n; ++i) dis[i][0] = dis[i][1] = INF;
	dis[v1][0] = 0;
	pair<int,pair<int,int> > now;
	while (!pq.empty()){
		now = pq.top(); pq.pop();
		d = -now.first;
		v = now.second.first;
		t = now.second.second;
		if (v==v2){
			printf("%d\n",d);
			return 0;
		}
		if (dis[v][t] < d || vis[v][t]) continue;
		vis[v][t] = 1;
		for (int i=0; i<adj[v].size(); ++i){
			vv = adj[v][i];
			if (vis[vv][t]) continue;
			if (d+1 < dis[vv][t]){
				dis[vv][t] = d+1;
				pq.push(make_pair(-d-1,make_pair(vv,t)));
			}
		}
		if (!t) for (int i=0; i<tol[v].size(); ++i){
			vv = tol[v][i];
			if (vis[vv][1]) continue;
			if (d+1 < dis[vv][1]){
				dis[vv][1] = d+1;
				pq.push(make_pair(-d-1,make_pair(vv,1)));
			}
		}
	}
}
	
	
	
	
	
	
