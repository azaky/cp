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

#define MOD 1000000007LL

LL power(LL a, LL b){
	if (b <= 0) return 1;
	LL temp = power(a,b>>1);
	temp = (temp*temp)%MOD;
	if (b&1) temp = (temp*a) % MOD;
	return temp;
}

int main(){
	LL n, k;
	scanf("%I64d%I64d",&n,&k);
	LL ans = (k*power(k,k-2)) % MOD;
	//printf("%I64d\n",ans);
	ans = (ans*power(n-k,n-k)) % MOD;
	
	printf("%I64d\n",ans);
	
	return 0;
}
