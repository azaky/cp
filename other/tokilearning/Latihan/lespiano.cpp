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
#include <limits>
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
template <class T> inline T dijkstra(vector<int> adj[], vector<T> w[], int n, int v1, int v2){
	const int _n = n+5;
	const T INF = numeric_limits<T>::max( )/(T)2;
	int vis[_n],v,vv;
	T dis[_n],d;
	priority_queue <pair<T,int> > pq;
	for (int i=0; i<_n; ++i){
		vis[i] = 0;
		dis[i] = i==v1 ? 0 : INF;
	}
	pq.push(make_pair(0,v1));
	while (!pq.empty()){
		v = pq.top().second;
		d = -pq.top().first;
		pq.pop();
		if (v==v2) return d;
		if (vis[v] || d>dis[v]) continue;
		vis[v] = 1;
		for (int i=0; i<(int)adj[v].size(); ++i){
			vv = adj[v][i];
			if (dis[vv] > d+w[v][i]){
				dis[vv] = d+w[v][i];
				pq.push(make_pair(-dis[vv],vv));
			}
		}
	}
	return INF;
}

/* -------------- end of azaky's template -------------- */

const int MAXN = 5000;
int v,e,a,b,x,y,z;
vector<int> _adj[MAXN],adj[MAXN],w[MAXN];

int main(){
	scanf("%d%d%d%d",&v,&e,&a,&b);
	for (int i=0; i<e; ++i){
		scanf("%d%d%d",&x,&y,&z);
		if (x==y) continue;
		adj[x].push_back(y); w[x].push_back(z);
		adj[y].push_back(x); w[y].push_back(z);
	}
	printf("%d\n",dijkstra(adj,w,v,a,b));
	return 0;
}
