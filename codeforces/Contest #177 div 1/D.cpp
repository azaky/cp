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

const int MAXN = 111111;
int n, cot, par[MAXN], size[MAXN];
LL u[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p){
	par[v] = p;
	int temp = cot; cot++;
	REP(i,(int)adj[v].size()){
		if (adj[v][i] == par[v]) continue;
		dfs(adj[v][i],v);
	}
	size[v] = cot-temp;
}
LL c2(LL x){return (x*(x-1))>>1;}

int main(){
	scanf("%d",&n);
	REP(i,(int)n-1){
		int a, b;
		scanf("%d%d",&a,&b);
		adj[a].pb(b); adj[b].pb(a);
	}
	cot = 0;
	dfs(1,0);
	LL ans1 = 0;
	FOR(v,1,n){
		int k = 0;
		REP(i,(int)adj[v].size()){
			if (adj[v][i] == par[v]) continue;
			u[++k] = ((LL)size[adj[v][i]]);
		}
		LL sum = 0, sumsquare = 0;
		FOR(i,1,k) sum += u[i], sumsquare += u[i]*u[i];
		ans1 += c2((LL)(n-size[v]))*((LL)(size[v]-1) + (sum*sum-sumsquare)/2LL);
	}
		
	LL ans2 = 0;
	FOR(v,1,n){
		int k = 0;
		REP(i,(int)adj[v].size()){
			if (adj[v][i] == par[v]) continue;
			u[++k] = c2((LL)size[adj[v][i]]);
		}
		LL sum = 0, sumsquare = 0;
		FOR(i,1,k) sum += u[i], sumsquare += u[i]*u[i];
		ans2 += (sum*sum-sumsquare)/2;
	}
	//printf("ans1 = %I64d, ans2 = %I64d\n",ans1,ans2);
	printf("%I64d\n",2*(ans1-ans2));
	
	return 0;
}
