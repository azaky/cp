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

#define MAXN 10100

int n, na, ck, a[20];
vector<int> ans[20];

int c(int n, int k){
	ll _c = 1;
	FOR(i,n-k+1,n) _c *= (ll)i;
	FOR(i,1,k) _c /= (ll)i;
	return (int)_c;
}

void dfs(int pos, int cp){
	if (cp == na/2){
		if (ck == n) return;
		ck++;
		REP(i,na/2) ans[a[i]].PB(ck);
	}
	else if (pos < na) {
		//taroh di pos
		a[cp] = pos;
		dfs(pos+1,cp+1);
		//ignore pos
		dfs(pos+1,cp);
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d",&n);
	if (n <= 4){
		printf("%d\n",n);
		FOR(i,1,n) printf("%d\n",i);
		return 0;
	}
	
	na = 2;
	while (c(na,na/2) < n) na++;
	
	ck = 0;
	dfs(0,0);
	
	printf("%d\n",na);
	REP(i,na){
		printf("%d",ans[i][0]);
		FOR(j,1,SZ(ans[i])-1) printf(" %d",ans[i][j]);
		printf("\n");
	}
	
	return 0;
}
