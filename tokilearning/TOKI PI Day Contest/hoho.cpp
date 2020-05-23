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
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

typedef pair<PII,PII> PI;
int random(int r){return rand()%r;}
int random(int l, int r){return rand()%(r-l+1)+l;}

#define MAXN 111
int n, m, k, a[MAXN][MAXN];
vector<PI> all, ans;

void tukar(PI x){swap(a[x.fi.fi][x.fi.se],a[x.se.fi][x.se.se]);}

int main(){
	srand(time(NULL));
	
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	
	FOR(i,1,n) FOR(j,1,m){
		if (j < m) all.pb(mp(mp(i,j),mp(i,j+1)));
		if (i < n) all.pb(mp(mp(i,j),mp(i+1,j)));
	}
	REP(i,k){
		int take;
		do{
			take = random((int)all.size());
		} while (a[all[take].fi.fi][all[take].fi.se] < a[all[take].se.fi][all[take].se.se]);
		ans.pb(all[take]);
		tukar(all[take]);
	}
	printf("%d\n",k);
	REP(i,k){
		printf("%d %d %d %d\n",ans[i].fi.fi,ans[i].fi.se,ans[i].se.fi,ans[i].se.se);
	}
	
	return 0;
}
