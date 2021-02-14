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

#define INF 1e100
#define MAXN 111111

int ntc, n;
db a[MAXN], b[MAXN];

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%d",&n);
		REP(i,n){
			double x;
			scanf("%lf",&x);
			if (x == 1.) a[i] = INF; else a[i] = x/log(x);
		}
		REP(i,n){
			double x;
			scanf("%lf",&x);
			if (x == 1.) b[i] = INF; else b[i] = x/log(x);
		}
		sort(a,a+n); sort(b,b+n);
		
		db ans = 0;
		int ib = 0;
		REP(ia,n){
			while (b[ib] <= a[ia] && ib < n) ++ib;
			ans += (db)(n-ib)/(db)n;
		}
		printf("%.17lf\n",ans);
	}
	
	return 0;
}
