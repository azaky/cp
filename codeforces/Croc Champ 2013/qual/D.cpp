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

const int MAXN = 11111;
int n, k, a[MAXN], step[22][MAXN];

void calc(int l, int r, int ns){
	if (l > r) return;
	assert(a[r] == 1);
	if (a[l] == 1) return;
	int dif = a[l]/2, mid;
	FOR(i,l,r){
		a[i] -= dif;
		if (a[i] == 1){mid = i; break;}
	}
	calc(mid+1,r,ns);
	FOR(i,l,mid) if (a[i] == dif) FOR(j,l,mid) step[ns][j] = i;
	calc(l,mid,ns-1);
}

int main(){
	scanf("%d%d",&n,&k);
	FOR(i,1,n) a[i] = n-i;
	FOR(i,1,k) FOR(j,1,n) step[i][j] = n;
	calc(1,n-1,k);
	FOR(i,1,k){
		FOR(j,1,n) printf("%d ",step[i][j]); printf("\n");
	}
	
	return 0;
}
