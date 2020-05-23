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

ll task1(ll n, ll p){
	p--;
	if (p == (1LL << n)-1) return (1LL << n)-1;
	if (p < (1LL << (n-1))) return (1LL << n)-2;
	
	return 0;
}

ll task2(ll n, ll p){
	p--;
	if (p == 0) return 0;
	if (p == (1LL << n)-1) return (1LL << n)-1;
	if (p >= (1LL << (n-1))) return (1LL << n)-2;
/*
	ll s[111];
	REP(i,n) s[n-i] = (p & (1LL << (ll)i)) >> (ll)i;
*/
//	FOR(i,1,n) printf("%I64d ",s[i]); puts("");
	ll k;
	for(k = n-1; k > 0; --k){
		if ((1LL << k)-1 <= p) return (1LL << n) - (1LL << k);
	}

	return 0;
}

int main(){
	int ntc; scanf("%d",&ntc);
	FOR(itc,1,ntc){
		ll n, p;
		cin >> n >> p;
		printf("Case #%d: %I64d %I64d\n",itc,task1(n,p),task2(n,p));
	}
	
	return 0;
}
