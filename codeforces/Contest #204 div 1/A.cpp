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

#define MAXN 4222
int n, a[MAXN];
ll s[MAXN];

int main(){
/*
	db y;
	while (1){
		scanf("%lf",&y);
		printf("%d\n",int(y));
	}
	return 0;
*/
	scanf("%d",&n);
	FOR(i,1,n+n){
		double x;
		scanf("%lf",&x);
		x -= floor(x);
		x *= 1000;
		a[i] = (int)round(x);
//		printf("[%d]\n",a[i]);
	}
	sort(a+1,a+1+n+n);
	int c0 = 0;
	FOR(i,1,n+n) if (a[i] == 0) c0++;
	s[0] = 0;
	FOR(i,1,n+n) s[i] = s[i-1] + (ll) a[i];
	int t = n + n - c0;
	ll ans = 1LL << 60LL;
	for (int l = 0, r = t; r >= 0; ++l, --r){
		if (l > n || r > n) continue;
		ll suml = s[c0+l];
		ll sumr = 1000 * r - (s[n+n] - s[c0+l]);
		if (abs(suml-sumr) < ans) ans = abs(suml-sumr);
	}

	printf("%.3lf\n",(db)ans/1000.);
	
	return 0;
}
