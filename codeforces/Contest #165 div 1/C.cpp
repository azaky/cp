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
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

#define MAXN 222222
LL n, m, a[MAXN], b[MAXN], w[MAXN], tot[MAXN], tin[MAXN], ans[MAXN], visit[MAXN];
vector<pair<LL,LL> > adj[MAXN];			

void dfs(LL v){
	if (v == n) return;
	if (visit[v]) return;
	visit[v] = 1;
	if (1){
		REP(i,(LL)adj[v].size()){
			LL ii = adj[v][i].fi;
			if (ans[ii] == -1){
				LL u = adj[v][i].se;
				tin[u] += w[ii];
				if (v == a[ii]) ans[ii] = 0; else ans[ii] = 1;
			}
		}
	}
	REP(i,(LL)adj[v].size()){
		if (2*tin[adj[v][i].se] == tot[adj[v][i].se]) dfs(adj[v][i].se);
	}
}

int main(){
	scanf("%I64d%I64d",&n,&m);
	FOR(i,1,m){
		scanf("%I64d%I64d%I64d",&a[i],&b[i],&w[i]);
		tot[a[i]] += w[i]; tot[b[i]] += w[i];
		adj[a[i]].pb(mp(i,b[i])); adj[b[i]].pb(mp(i,a[i]));
	}
	RESET(ans,-1);
	dfs(1);
	FOR(i,1,m) printf("%I64d\n",ans[i]);
	return 0;
}
