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

int n, cot, xl[MAXN], xr[MAXN], ve[MAXN], vu[MAXN], par[MAXN], L[MAXN], P[MAXN][MAXLOG];
vector<PII> adj[MAXN];
LL edge[MAXN], cost[MAXN], node[4*MAXN];

void dfs(int v, int ie, int _par, LL _cost){
	cost[v] = _cost;
	par[v] = _par; L[v] = _par == -1 ? 0 : L[_par]+1;
	ve[ie] = v;
	cot++;
	xl[v] = cot; vu[cot] = v;
	REP(i,(int)adj[v].size()) if (adj[v][i].se != _par) dfs(adj[v][i].se,adj[v][i].fi,v,_cost+edge[adj[v][i].fi]);
	xr[v] = cot;
}
void build(int v, int l, int r){
	node[v] = 0;
	if (l == r) return;
	build(2*v,l,(l+r)/2); build(2*v+1,(l+r+2)/2,r);
}
void update(int v, int l, int r, int x, int y, LL add){
	if (x <= l && r <= y){
		node[v] += add;
		return;
	}
	if (r < x || y < l) return;
	update(2*v,l,(l+r)/2,x,y,add); update(2*v+1,(l+r+2)/2,r,x,y,add);
}
LL query(int v, int l, int r, int x){
	if (x <= l && r <= x) return node[v];
	if (r < x || x < l) return 0;
	return query(2*v,l,(l+r)/2,x)+query(2*v+1,(l+r+2)/2,r,x)+node[v];
}

void print(int v, int l, int r){
	printf("[%d..%d] : %d\n",l,r,(int)node[v]);
	if (l == r) return;
	print(2*v,l,(l+r)/2); print(2*v+1,(l+r+2)/2,r);
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
		//FOR(i,1,n) printf("%d(%d,%d) | ",vu[i],xl[vu[i]],xr[vu[i]]); printf("\n");
		initLCA();
		build(1,1,n);
		while(true){
			char task[10];
			scanf("%s",task);
			if (task[0] == 'D') break;
			if (task[0] == 'C'){
				int ie, w;
				scanf("%d%d",&ie,&w);
				update(1,1,n,xl[ve[ie]],xr[ve[ie]],(LL)w-edge[ie]);
				edge[ie] = w;
			}
			if (task[0] == 'Q'){
				int a,b;
				scanf("%d%d",&a,&b);
				int c = lca(a,b);
				LL wa = cost[a]+query(1,1,n,xl[a]);
				LL wb = cost[b]+query(1,1,n,xl[b]);
				LL wc = cost[c]+query(1,1,n,xl[c]);
				printf(LLD "\n",wa+wb-2*wc);
			}
		}
	}
	
	return 0;
}
