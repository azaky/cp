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
int n, a, p[MAXN];
vector<pair<int,PII> > edge;

int findSet(int x){
	return p[x] == x ? x : (p[x] = findSet(p[x]));
}
bool sameSet(int x, int y){
	return findSet(x) == findSet(y);
}
void merge(int x, int y){
	p[findSet(x)] = findSet(y);
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n) FOR(j,1,n){
		scanf("%d",&a);
		if (i < j) edge.pb(mp(a,mp(i,j)));
	}
	FOR(i,1,n){
		scanf("%d",&a);
		edge.pb(mp(a,mp(0,i)));
	}
	//DSU initialization
	FOR(i,0,n) p[i] = i;
	//MST
	int MST = 0;
	sort(ALL(edge));
	REP(i,(int)edge.size()){
		int w = edge[i].fi, x = edge[i].se.fi, y = edge[i].se.se;
		if (sameSet(x,y)) continue;
		MST += w;
		merge(x,y);
	}
	printf("%d\n",MST);
	
	return 0;
}
