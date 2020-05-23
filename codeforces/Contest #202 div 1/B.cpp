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

typedef pair<ll,ll> pll;

ll lcm(ll a, ll b){
	return (a * (b / __gcd(a,b)));
}

#define MAXN 111111
#define INF 10000000000000LL
vector<int> adj[MAXN];
int n, w[MAXN];
ll total = 0;

pll dfs(int par, int v){
	//leaf
	if (SZ(adj[v]) == 1 && adj[v][0] == par) return MP(1LL,(ll)w[v]);
	vector<pll> x;
	FORIT(it,adj[v]){
		int u = *it;
		if (u == par) continue;
		x.PB(dfs(v,u));
	}
	ll num = 1;
	FORIT(it,x){
		num = lcm(num,it->first);
		if (num > INF || num % it->first != 0){
			printf("%I64d\n",total);
			exit(0);
		}
	}
	if (num == 0) return MP(0,1);
	pll ans = MP(num*(ll)SZ(x),INF);
	FORIT(it,x){
		it->second /= (num/it->first);
		MN(ans.second,it->second);
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&w[i]);
	total = 0;
	REP(i,n) total += (ll)w[i];
	REP(i,n-1){
		int x, y;
		scanf("%d%d",&x,&y);
		x--; y--;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	pll ans = dfs(-1,0);
	printf("%I64d\n",total-ans.first*ans.second);
	
	return 0;
}
