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

LL calc(pair<LL,LL> x){
	LL ret = (LL)x.fi, p = 1;
	while (p < x.se){
		ret ++; p *= 4LL;
	}
	return ret;
}

#define MAXN 111111

pair<LL,LL> a[MAXN];
int n;
LL ans, m;

int main(){
	scanf("%d",&n);
	REP(i,n) cin >> a[i].fi >> a[i].se;
	ans = calc(a[0]); m = a[0].fi;
	FOR(i,1,n-1){
		ans = max(ans,calc(a[i]));
		m = max(m,a[i].fi);
	}
	if (ans == m) ans++;
	cout << ans << endl;
	return 0;
}
