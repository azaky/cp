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

#define MAXN 200200
int n,m,k,a,b,ans[MAXN],visit[MAXN],pos[MAXN];
vector<int> adj[MAXN];

void dfs(int p){
	int v = ans[p];
	visit[v] = 1;
	REP(i,(int)adj[v].size()){
		int u = adj[v][i];
		if (visit[u]){
			if (p-pos[u]+1 > k){
				printf("%d\n",p-pos[u]+1);
				FOR(j,pos[u],p) printf("%d ",ans[j]); exit(0);
			}
			else continue;
		}
		else {
			ans[p+1] = u;
			pos[u] = p+1; dfs(p+1); pos[u] = 0;
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	REP(i,m){
		scanf("%d%d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}
	pos[1] = 1; ans[1] = 1;
	dfs(1);
	
	return 0;
}
