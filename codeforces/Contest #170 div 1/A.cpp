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

const int MAXN = 111;
int n, m, k[MAXN], lang[MAXN][MAXN], visit[MAXN], ans;
set<int> known;

void fill(int v){
	if (visit[v]) return;
	visit[v] = 1;
	REP(i,k[v]) known.insert(lang[v][i]);
	FOR(i,1,n){
		if (visit[i]) continue;
		bool match = false;
		REP(j,k[i]) if (EXIST(lang[i][j],known)){
			match = true;
			break;
		}
		if (match) fill(i);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n){
		scanf("%d",&k[i]);
		REP(j,k[i]) scanf("%d",&lang[i][j]);
	}
	ans = 0;
	FOR(i,1,n){
		if (visit[i]) continue;
		known.clear();
		fill(i);
		ans ++;
	}
	printf("%d\n",ans-1);
	
	return 0;
}
