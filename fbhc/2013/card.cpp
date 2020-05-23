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

#define MAXN 111111
#define MOD 1000000007LL
LL n, k, a[MAXN], ans, dp[MAXN];

LL p(LL a, LL b){
	if (b == 0) return 1;
	LL ret = p(a,b/2);
	ret = (ret*ret) % MOD;
	if (b % 2 == 1) ret = (ret*a) % MOD;
	return ret;
}

LL c(LL n, LL k){
	if (n == k) return dp[n] = 1LL;
	return dp[n] = (((dp[n-1]*n) % MOD)*p(n-k,MOD-2))%MOD;
}

int main(){
	if ('?' < 'a') printf("HEHE"); return 0;
	int ntc; scanf("%d",&ntc);
	FOR(itc,1,ntc){
		cin >> n >> k;
		FOR(i,1,n) cin >> a[i];
		sort(a+1,a+n+1);
		ans = 0;
		FOR(i,k,n) ans = (ans + a[i] * c(i-1,k-1)) % MOD;
		cout << "Case #" << itc << ": " << ans << endl;
	}
	
	return 0;
}
