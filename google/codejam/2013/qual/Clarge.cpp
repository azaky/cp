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

LL reverse(LL x){
	LL res = 0;
	while (x > 0){
		res = 10LL*res + (x%10LL);
		x /= 10;
	}
	return res;
}
bool palindrome(LL x){return x == reverse(x);}

int main(){
	vector<LL> x;
	for (LL i = 1; i <= 10000000; ++i) if (palindrome(i)) if (palindrome(i*i)) x.pb(i*i), printf("[%I64d]\n",i);
	int ntc; LL a, b;
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		cin >> a >> b;
		printf("Case #%d: %d\n",itc,(int)(upper_bound(ALL(x),b)-lower_bound(ALL(x),a)));
	}
	return 0;
}
