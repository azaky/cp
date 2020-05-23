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
#define REPD(i,n) for (int i = n-i; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) (s.find(a) != s.end())

/* -------------- end of azaky's template -------------- */

#define MAX 300300
#define INF 1000000001
int n, x[MAX], y[MAX];
LL ans,tx,ty;
map<int,int> mapx,mapy;
map<PII,bool> exist;

int main(){
	freopen("triangles.in","r",stdin);
	freopen("triangles.out","w",stdout);
	
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&x[i],&y[i]);
	REP(i,n){
		if (EXIST(mp(x[i],y[i]),exist)) x[i] = y[i] = -INF;
		exist[mp(x[i],y[i])] = true;
		mapx[x[i]]++;
		mapy[y[i]]++;
	}
	ans = 0;
	REP(i,n){
		if (x[i] == -INF) continue;
		tx = (LL)mapx[x[i]]; ty = (LL)mapy[y[i]];
		ans += (tx-1LL)*(ty-1LL);
	}
	printf(LLD,ans);
	return 0;
}
