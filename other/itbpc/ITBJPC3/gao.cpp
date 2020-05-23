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
#include <cassert>
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

const LL MOD = 1000007LL;

LL power(LL a, LL b){
	if (b == 0) return 1;
	LL ret = power(a,b>>1);
	ret = (ret*ret) % MOD;
	if (b & 1) ret = (ret*a) % MOD;
	return ret;
}

int main(){
	LL T, A, B;
	scanf("%lld",&T);
	assert(0 < T && T <= 10000);
	while (T--){
		scanf("%lld%lld",&A,&B);
		assert(1 < A && A <= B && B <= 100000);
		if (A > B){
			puts("TIDAK");
			continue;
		}
		LL num = 1;
		LL p = B-A;
		LL den = A-1;
		while (p > 0 && num < A-1){
			num *= 2;
			p--;
		}
		num *= B-1;
		if (num % den != 0){
			puts("TIDAK");
			continue;
		}
		num /= den;
		num = (power(2,p)*num)%MOD;
		printf("YA %lld\n",num);
	}
	
	return 0;
}
