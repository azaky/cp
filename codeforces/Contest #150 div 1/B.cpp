#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime()	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

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

/* -------------- end of azaky's template -------------- */

#define MAXN 100100

int n, m, h, t;
vector<int> adj[MAXN];
vector<pii> edge;

vector<int> common(int u, int v){
	vector<int> ans;
	int iv = 0;
	REP(iu,SZ(adj[u])){
		while (adj[v][iv] < adj[u][iu]){
			++iv;
			if (iv == SZ(adj[v])) break;
		}
		if (iv == SZ(adj[v])) break;
		if (adj[v][iv] == adj[u][iu]) ans.PB(adj[v][iv]);
	}
	return ans;
}
int deg(int v){return SZ(adj[v]);}
void ans(int u, int v){
	vector<int> com = common(u,v), head, tail;
	map<int,int> used;
	FORIT(it,com) used[*it] = 1;
	used[u] = used[v] = 1;
	REP(i,SZ(adj[u])){
		if (used[adj[u][i]]) continue;
		head.PB(adj[u][i]);
		if (SZ(head) == h) break;
	}
	REP(i,SZ(adj[v])){
		if (used[adj[v][i]]) continue;
		tail.PB(adj[v][i]);
		if (SZ(tail) == t) break;
	}
	int x = 0;
	while (SZ(head) < h) head.PB(com[x++]);
	while (SZ(tail) < t) tail.PB(com[x++]);
	assert(x <= SZ(com));
	printf("YES\n%d %d\n",u+1,v+1);
	REP(i,h) printf("%d ",head[i]+1);
	REP(i,t) printf("%d ",tail[i]+1);
	exit(0);
}

int main(){
	scanf("%d%d%d%d",&n,&m,&h,&t);
	REP(i,m){
		int _a, _b;
		scanf("%d%d",&_a,&_b);
		--_a; --_b;
		edge.PB(MP(_a,_b)); edge.PB(MP(_b,_a));
		adj[_a].PB(_b); adj[_b].PB(_a);
	}
	REP(i,n) sort(ALL(adj[i]));
	FORIT(it,edge){
		int u = it->A, v = it->B;
		if (deg(u) <= h || deg(v) <= t) continue;
		else if (deg(u) > h+t || deg(v) > h+t) ans(u,v);
		else if (deg(u)+deg(v)-SZ(common(u,v)) >= h+t+2) ans(u,v);
	}
	puts("NO");
	
	return 0;
}
