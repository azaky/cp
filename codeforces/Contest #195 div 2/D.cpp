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

#define MOD 1000000007LL

ll p(ll a, ll b){
	ll mul = 1;
	for (ll t = 30; t >= 0; --t){
		mul *= mul;
		mul %= MOD;
		if (b & (1LL << t)){
			mul *= a;
			mul %= MOD;
		}
	}
	return mul;
}

ll com(ll n, ll k){
//	assert(k <= n && k >= 0);
	ll c = 1;
	for (ll i = n-k+1; i <= n; ++i){
		c *= i;
		c %= MOD;
	}
	for (ll i = 1; i <= k; ++i){
		c *= p(i,MOD-2);
		c %= MOD;
	}
	return c;
}

int main(){
	ll n, m, g;
	cin >> n >> m >> g;
	if (m == 0){
		if (n % 2LL != g) puts("1"); else puts("0");
		return 0;
	}
	//count 0s
	ll ans = 0, c;
	for (ll k = 0LL; k <= n; k += 2){
		if (!k) c = com(n+m-k-1,m-1);
		else{
			c *= ((n-k+1)*(n-k+2))%MOD;
			c %= MOD;
			c *= p(((n+m-k)*(n+m-k+1))%MOD,MOD-2);
			c %= MOD;
		}
//		printf("C = %I64d\n",c);
		if (k + 1LL != n+m) ans += c;
		ans %= MOD;
	}
	if (n%2LL == 1LL && m == 1LL) ans++;
	if (g) ans = com(n+m,n) - ans + MOD;
	ans %= MOD;
	cout << ans << endl;
	
	return 0;
}
