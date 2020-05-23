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

/* -------------- end of azaky's template -------------- */

void dfs(int v, int par){
	t++;
	pos[v] = t;
	idx[t] = v;
	FORIT(it,adj[v]){
		if (*it != par) dfs(*it,v);
	}
	next[pos[v]] = t;
}

bool cmp(const query &a, const query &b){
	if (a.l != b.l) return a.l < b.l;
	return a.r < b.r;
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",&c[i]);
	REP(i,n-1){
		int x, y;
		scanf("%d%d",&x,&y);
		adj[x].PB(y); adj[y].PB(x);
	}
	t = 0;
	dfs(1,0);
	//scanning queries
	REP(i,m){
		scanf("%d%d",&q[i].v,&q[i].k);
		q[i].i = i;
		q[i].l = pos[q[i].v];
		q[i].r = next[q[i].l];
	}
	sort(q,q+m,cmp);
	
	
	return 0;
}
