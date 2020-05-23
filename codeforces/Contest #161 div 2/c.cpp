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

#define MAXN 100100
int n, a, b, ans[MAXN], used[MAXN];
vector<int> adj[MAXN];

void nosol(void){puts("-1"); exit(0);}
bool con(int a, int b){
	if (a == 0 || b == 0) return true;
	REP(i,4) if (adj[a][i] == b) return true;
	return false;
}
void dfs(int p){
	if (p == n){
		if (!(con(ans[n-1],ans[1]) && con(ans[n],ans[1]) && con(ans[n],ans[2]))) return;
		FOR(i,1,n) printf("%d ",ans[i]); exit(0);
	}
	REP(i,4){
		ans[p+1] = adj[ans[p]][i];
		if (used[ans[p+1]] || !con(ans[p+1],ans[p-1])) continue;
		used[ans[p+1]] = 1;
		dfs(p+1);
		used[ans[p+1]] = 0;
	}
}

int main(){
	scanf("%d",&n);
	REP(i,2*n){
		scanf("%d%d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}
	FOR(i,1,n) if (adj[i].size() != 4) nosol();
	used[1] = 1; ans[1] = 1;
	dfs(1);
	nosol();
}
