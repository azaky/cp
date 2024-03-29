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

void dfs(int v){
	

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d",&n,&q);
		REP(i,n) scanf("%d",&v[i]);
		REP(i,n) adj[i].clear();
		REP(i,n){
			scanf("%d"&par[i]);
			if (i) adj[par[i]].PB(i);
		}
		REP(i,n) query[i].clear();
		REP(i,q){
			int k, x;
			scanf("%d%d",&k,&x);
			query[x].PB(MP(k,i));
		}
		s.clear();
		dfs(0);
		printf("Case #%d:\n",itc);
		REP(i,q) printf("%d\n",ans[i]);
	}
	
	return 0;
}
