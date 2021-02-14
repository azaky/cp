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

#define MAXN 1111
int ntc, n, nr, nc, maxr[MAXN], maxc[MAXN], dp[MAXN][MAXN], v[MAXN][MAXN];
pii a[MAXN];

int calc(int r, int c){
	if (r > nr || c > nc) return 0;
	if (v[r][c]) return dp[r][c];
	v[r][c] = 1;
	if (maxr[r] < c) return dp[r][c] = calc(r+1,c);
	if (maxc[c] < r) return dp[r][c] = calc(r,c+1);
	return dp[r][c] = 1 + min(calc(r+1,c),calc(r,c+1));
}

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		map<int,int> r, c;
		nr = 0; nc = 0;
		scanf("%d",&n);
		REP(i,n){
			scanf("%d%d",&a[i].A,&a[i].B);
			//normalize
			if (!EXIST(a[i].A,r)) r[a[i].A] = ++nr;
			a[i].A = r[a[i].A];
			if (!EXIST(a[i].B,c)) c[a[i].B] = ++nc;
			a[i].B = c[a[i].B];
		}
		//
		FOR(i,1,nr) maxr[i] = 0;
		FOR(i,1,nc) maxc[i] = 0;
		REP(i,n){
			MX(maxr[a[i].A],a[i].B);
			MX(maxc[a[i].B],a[i].A);
		}
		RESET(v,0);
		printf("%d\n",calc(1,1));
	}
	
	return 0;
}
