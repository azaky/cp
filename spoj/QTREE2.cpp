#include <vector>
#include <map>
#include <set>
#include <queue>
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
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long LL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) (s.find(a) != s.end())

/* -------------- end of azaky's template -------------- */

#define MAXN 11111
#define MAXLOG 20

int n, cot, par[MAXN], L[MAXN], P[MAXN][MAXLOG];
vector<PII> adj[MAXN];
LL edge[MAXN], cost[MAXN];

void dfs(int v, int ie, int _par, LL _cost){
	cost[v] = _cost;
	par[v] = _par; L[v] = _par == -1 ? 0 : L[_par]+1;
	REP(i,(int)adj[v].size()) if (adj[v][i].se != _par) dfs(adj[v][i].se,adj[v][i].fi,v,_cost+edge[adj[v][i].fi]);
}
void initLCA(){
	FOR(i,1,n) for(int j=0; (1 << j) <= n; ++j) P[i][j] = -1;
	FOR(i,1,n) P[i][0] = par[i];
	for (int j=1; (1 << j) <= n; ++j) FOR(i,1,n) if (P[i][j-1] != -1) P[i][j] = P[P[i][j-1]][j-1];
}
int lca(int p, int q){
	int log;
	if (L[p] < L[q]) swap(p,q);
	for (log = 1; (1 << log) <= L[p]; ++log);
	log--;
	REPD(i,log+1) if (L[p] - (1 << i) >= L[q]) p = P[p][i];
	if (p == q) return p;
	REPD(i,log+1) if (P[p][i] != -1 && P[p][i] != P[q][i]) p = P[p][i], q = P[q][i];
	return par[p];
}
int kthParent(int p, int k){
	int log;
	for (log = 1; (1 << log) <= L[p]; ++log);
	REPD(i,log) if (k >= (1 << i)) k -= (1 << i), p = P[p][i];
	return p;
}

int main(){
	int ntc; scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d",&n);
		FOR(i,1,n) adj[i].clear();
		FOR(i,1,n-1){
			int a, b, w;
			scanf("%d%d%d",&a,&b,&w);
			edge[i] = (LL)w;
			adj[a].pb(mp(i,b)); adj[b].pb(mp(i,a));
		}
		cot = 0;
		dfs(1,0,-1,0);
		initLCA();
		while(true){
			char task[10];
			scanf("%s",task);
			if (task[0] == 'D' && task[1] == 'O') break;
			if (task[0] == 'D'){
				int a, b;
				scanf("%d%d",&a,&b);
				int c = lca(a,b);
				printf(LLD "\n",cost[a]+cost[b]-2*cost[c]);
			}
			if (task[0] == 'K'){
				int a, b, k;
				scanf("%d%d%d",&a,&b,&k);
				int c = lca(a,b);
				if (L[a] - L[c] + 1 >= k) printf("%d\n",kthParent(a,k-1));
				else printf("%d\n",kthParent(b,L[a]+L[b]-2*L[c]-k+1));
			}
		}
	}
	
	return 0;
}
