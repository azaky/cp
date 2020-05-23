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

#define MOD1 1000000009LL
#define MOD2 1000000007LL
pair<ll,ll> calc(ll a, ll b, ll s, ll n){
	ll s1 = s%MOD1, s2 = s%MOD2;
	return MP((((n*n)%MOD1)*((a+b)%MOD1)-(n*((7LL*a+5LL*b+2LL*s1)%MOD1))%MOD1+12LL*s1+MOD1)%MOD1,(((n*n)%MOD1)*((a+b)%MOD2)-(n*((7LL*a+5LL*b+2LL*s2)%MOD2))%MOD2+12LL*s2+MOD2)%MOD2);
}

// n*n*(a+b) - n*(7*a+5*b+2*s) + 12*s == 0

ll ntc, a, b, s;

int main(){
	scanf("%lld",&ntc);
//	cin >> ntc;
	FOR(itc,1,ntc){
		scanf("%lld%lld%lld",&a,&b,&s);
//		cin >> a >> b >> s;
		for (ll n = 7; ; ++n){
			if (n > 10000000) assert(false);
			pair<ll,ll> haha = calc(a,b,s,n);
			if (haha.A != 0 || haha.B != 0) continue;
			ll diff = (b-a)/(n-6LL);
			ll firs = a - diff-diff;
			ll last = firs + (n-1LL)*diff;
			printf("%lld\n",n);
//			cout << n << endl;
			for (; firs <= last; firs += diff){
				printf("%lld",firs);
//				cout << firs;
				if (firs == last) printf("\n"); else printf(" ");
			}
			break;
		}
	}
	return 0;
}
