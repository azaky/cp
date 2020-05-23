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
#include <numeric>
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
#define MAXN 1111111
int n;
ll a[MAXN],ans[MAXN],BIT[MAXN],last[MAXN];

void add(int k, ll s){
	for (int x = k; x <= 1000000; x += (x & -x)) BIT[x] = (BIT[x]+s)%MOD;
}
ll query(int k){
	ll sum = 0;
	for (int x = k; x > 0; x -= (x & -x)) sum = (sum + BIT[x])%MOD;
	return sum;
}

int main(){
	scanf("%d",&n);
	RESET(last,0);
	FOR(i,1,n){
		scanf("%I64d",&a[i]);
		ans[i] = (query((int)a[i])*(a[i]) + a[i] - last[a[i]] + MOD) % MOD;
		last[a[i]] = (last[a[i]] + ans[i])%MOD;
		add(a[i],ans[i]);
//		printf("%I64d\n",ans[i]);
	}
	ll total = 0;
	FOR(i,1,n) total = (total + ans[i]) % MOD;
	printf("%I64d\n",total);
	//REP(i,1000001) total -= last[i];
	//assert(total == 0);
	
	return 0;
}
