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

#define MAXN 100100
int q[MAXN], a[MAXN], m,n,d, total,totaldis;

int main(){
	scanf("%d",&m);
	REP(i,m) scanf("%d",&q[i]);
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n); reverse(a,a+n);
	d = 100000;
	REP(i,m) if (q[i] < d) d = q[i];
	d += 2;
	REP(i,n) if ((i+1) % d == 0 || (i+2) % d == 0) totaldis += a[i];
	REP(i,n) total += a[i];
	printf("%d\n",total-totaldis);
	
	return 0;
}
