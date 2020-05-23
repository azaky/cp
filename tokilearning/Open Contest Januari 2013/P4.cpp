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

LL p(LL K){
	LL ret = 1;
	REP(i,K) ret *= 10LL;
	return ret;
}
LL gcd(LL a, LL b){
	if (a == 0) return b;
	return gcd(b%a,a);
}

int main(){
	
	LL K, N, d, ans1, ans2;
	
	cin >> K >> N;
	
	d = gcd(N,p(K));
	
	ans1 = p(K)/d + 1;
	ans2 = N/d;
	
	cout << ans1 << " " << ans2 << endl;
	
	return 0;
}
