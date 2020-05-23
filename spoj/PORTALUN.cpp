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
int n,m,grundy[MAXN],visit[MAXN];
vector<int> adj[MAXN];

int calc(int v){
	if (visit[v]) return grundy[v];
	visit[v] = 1;
	int x[MAXN];
	REP(i,n) x[i] = 0;
	REP(i,(int)adj[v].size()) x[calc(adj[v][i])] = 1;
	REP(i,MAXN) if (!x[i]) return grundy[v] = i;
}

int main(){
	if (scanf("%d%d",&n,&m) != 2) return 0;
	REP(i,n) adj[i].clear();
	REP(i,m){
		int a, b;
		scanf("%d%d",&a,&b);
		if (b < a) swap(a,b);
		adj[b].pb(a);
	}
	RESET(visit,0);
	REP(i,n) grundy[i] = calc(i);
	int k;
	scanf("%d",&k);
	int ans = 0;
	REP(i,k){
		int a;
		scanf("%d",&a);
		ans ^= grundy[a];
	}
	puts(ans ? "I win" : "I lose");
	
	main();
}
