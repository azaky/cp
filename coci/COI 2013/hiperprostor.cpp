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

const int MAXN = 1111;
const int INF  = 1000000000;
int n, m, path[MAXN], visit[MAXN];
vector<PII> adj[MAXN];

int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int a, b; char w[10];
		scanf("%d %d %s",&a,&b,w);
		if (!strcmp(w,"x")) adj[a].pb(mp(b,INF));
		else adj[a].pb(mp(b,atoi(w)));
	}

	int total = 0;
	FOR(i,1,n) REP(j,(int)adj[i].size()) total += (adj[i][j].se == INF) ? 0 : adj[i][j].se;
	
	int q;
	scanf("%d",&q);
	while (q--){
		int a, b;
		scanf("%d%d",&a,&b);
		//reset everything
		
		//INF and zero check
		FOR(i,1,n) path[i] = INF, visit[i] = 0;
		priority_queue <PII> pq;
		pq.push(mp(0,a)); path[a] = 0;
		while (!pq.empty()){
			int v = pq.top().se; pq.pop();
			if (visit[v]) continue; else visit[v] = 1;
			if (v == b) break;
			REP(i,(int)adj[v].size()){
				int u = adj[v][i].fi;
				if (!visit[u] || path[u] > path[v] + adj[v][i].se) pq.push(mp(-(path[u] = min(path[u],path[v]+adj[v][i].se)),u));
			}
		}
		if (!visit[b]){
			puts("0 0"); continue;
		}
		if (path[b] == INF){
			puts("inf"); continue;
		}
		//Brute Force check
		set <int> ans;
		FOR(inf,1,total){
			FOR(i,1,n) path[i] = INF, visit[i] = 0;
			while (!pq.empty()) pq.pop(); pq.push(mp(0,a)); path[a] = 0;
			
			while (!pq.empty()){
				int v = pq.top().se; pq.pop();
				if (visit[v]) continue; else visit[v] = 1;
				if (v == b) break;
				REP(i,(int)adj[v].size()){
					int u = adj[v][i].fi;
					if (!visit[u] || path[u] > path[v] + (adj[v][i].se == INF ? inf : adj[v][i].se)) pq.push(mp(-(path[u] = min(path[u],path[v]+(adj[v][i].se == INF ? inf : adj[v][i].se))),u));
				}
			}
			ans.insert(path[b]);
		}
		int sum = 0;
		for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it) sum += *it;
		printf("%d %d\n",(int)ans.size(),sum);
		
	}
	
	return 0;
}
