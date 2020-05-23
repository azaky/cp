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

#define MAXN 555
#define MAXE 11111
PII edge[MAXE];
int n, m, TL[MAXE][MAXN], TR[MAXE][MAXN], L[MAXN], R[MAXN];

int findSetL(int h, int x){return TL[h][x] == x ? x : TL[h][x] = findSetL(h,TL[h][x]);}
void mergeL(int h, int a, int b){if (findSetL(h,a) < findSetL(h,b)) TL[h][findSetL(h,b)] = findSetL(h,a); else TL[h][findSetL(h,a)] = findSetL(h,b);}

int findSetR(int h, int x){return TR[h][x] == x ? x : TR[h][x] = findSetR(h,TR[h][x]);}
void mergeR(int h, int a, int b){if (findSetR(h,a) < findSetR(h,b)) TR[h][findSetR(h,b)] = findSetR(h,a); else TR[h][findSetR(h,a)] = findSetR(h,b);}

int findSet(int x){return L[x] == x ? x : L[x] = findSet(L[x]);}
void merge(int a, int b){if (findSet(a) < findSet(b)) L[findSet(b)] = findSet(a); else L[findSet(a)] = findSet(b);}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m) scanf("%d%d",&edge[i].fi,&edge[i].se);
	FOR(i,1,n) TL[0][i] = i;
	FOR(h,1,m){
		FOR(i,1,n) TL[h][i] = TL[h-1][i];
		mergeL(h,edge[h].fi,edge[h].se);
	}
	FOR(i,1,n) TR[m+1][i] = i;
	FORD(h,m,1){
		FOR(i,1,n) TR[h][i] = TR[h+1][i];
		mergeR(h,edge[h].fi,edge[h].se);
	}
	int ntc; scanf("%d",&ntc);
	while (ntc--){
		int l, r; scanf("%d%d",&l,&r);
		FOR(i,1,n) L[i] = TL[l-1][i], R[i] = TR[r+1][i];
		FOR(i,1,n) if (findSet(L[i]) != R[i]) merge(findSet(L[i]),R[i]);
		int ans = 0; FOR(i,1,n) if (L[i] == i) ++ans;
		printf("%d\n",ans);
	}
	
	return 0;
}
