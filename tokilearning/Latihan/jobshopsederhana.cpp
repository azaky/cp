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
inline int MST(vector<int> adj[], vector<int> w[], int n){
	const int _n = n+5;
	int intree[_n],v,c,ret = 0;
	priority_queue <pair<int,int> > pq;
	for (int i=0; i<_n; ++i) intree[i] = 0;
	intree[0] = 1;
	for (int i=0; i<(int)adj[0].size(); ++i) pq.push(make_pair(-w[0][i],adj[0][i]));
	while (!pq.empty()){
		v = pq.top().second;
		c = -pq.top().first;
		pq.pop();
		if (intree[v]) continue;
		ret += c; intree[v] = 1;
		for (int i=0; i<(int)adj[0].size(); ++i)
			if (!intree[adj[v][i]]) pq.push(make_pair(-w[v][i],adj[v][i]));
	}
	return ret;
}

/* -------------- end of azaky's template -------------- */

const int MAXN = 555;
int n,x;
vector<int> adj[MAXN],w[MAXN];

int main(){
	scanf("%d",&n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j){
			scanf("%d",&x);
			if (i!=j){
				adj[i].push_back(j);
				w[i].push_back(x);
			}
		}
	printf("%d\n",MST(adj,w,n));
	return 0;
}
