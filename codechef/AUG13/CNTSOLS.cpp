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

#define MOD 1000000007

ll p(ll a, ll b, ll n){
	if (b == 0) return 1LL%n;
	ll temp = p(a,b/2,n);
	temp = (temp*temp)%n;
	if (b%2) temp = (temp*a)%n;
	return temp;
}

int main(){
	int ntc;
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		ll upper, d, m, n, r[44], tot[44], par[44], c[44];
		cin >> upper >> d >> m >> n;
		ll ans = 0;
		FOR(i,1,n) r[i] = p(i,d,n);
		REP(i,n) tot[i] = par[i] = 0;
		int lim = (upper % n);
		FOR(i,1,n){
			tot[r[i]]++;
			if (i <= lim) par[r[i]]++;
		}
		REP(i,n) c[i] = ((upper/n)*tot[i] + par[i]);
		if (d == 0) c[1%n] = (c[1%n]+1LL); else c[0] = (c[0]+1LL);
		ll total = 0;
		REP(i,n) total += c[i];
//		REP(i,n) printf("c[%d] = %I64d\n",i,c[i]);
		assert(total == upper+1);
		REP(d1,n){
			REP(d2,n){
				REP(d3,n){
					if ((d1+d2+d3)%n != m%n) continue;
					ans += (((c[d1]*c[d2])%MOD)*c[d3])%MOD;
					ans %= MOD;
				}
			}
		}
		ll ans0 = 0;
//		FOR(i,0,upper) FOR(j,0,upper) FOR(k,0,upper) if ((p(i,d,n)+p(j,d,n)+p(k,d,n))%n == m%n) ans0++;
//		cout << "ANS0 = " << ans0 << endl;
		cout << ans << endl;
	}
	
	return 0;
}
