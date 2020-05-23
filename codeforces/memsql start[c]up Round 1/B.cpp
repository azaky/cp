#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
	#define GetTime()	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
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

bool PerfectSquare(ll x){
	if (x < 0) return false;
	ll r = (ll)floor(sqrt((double)x));
	while (r*r < x) ++r;
	return r*r == x;
}
ll SquareRoot(ll x){
	ll r = (ll)floor(sqrt((double)x));
	while (r*r < x) ++r;
	return r;
}

ll n;
vector<ll> ans;

int main(){
	scanf("%I64d",&n);
	ll c = -n-n;
	ll two = 1LL, k = 0;
	for(;;k++, two += two){
		ll b = two+two - 3LL;
		if (b > n+n-1LL) break;
		ll dis = b*b - 4LL*c;
		if (!PerfectSquare(dis)) continue;
		ll sd = SquareRoot(dis);
		ll r1 = (-b+sd), r2 = (-b-sd);
		if (r1 > 0 && r1 % 2LL == 0 && r1 % 4LL != 0) ans.PB(two*(r1/2LL));
		if (r2 > 0 && r1 % 2LL == 0 && r2 % 4LL != 0) ans.PB(two*(r2/2LL));
	}
	sort(ALL(ans));
	if (ans.empty()) puts("-1");
	else FORIT(it,ans) printf("%I64d\n",*it);
	
	return 0;
}
