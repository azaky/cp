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
#define REPD(i,n) for (int i = n-i; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) (s.find(a) != s.end())

/* -------------- end of azaky's template -------------- */

#define MAXN 100100
int n, c, a[MAXN], l, r, m;

int cows(int m){
	int ret = 1, last = a[0];
	REP(i,n){
		if (a[i] - last < m) continue;
		last = a[i]; ret++;
	}
	return ret;
}

int main(){
	int ntc; scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d",&n,&c);
		REP(i,n) scanf("%d",&a[i]);
		sort(a,a+n);
		l = 0, r = 1000000000;
		REP(i,100){
			m = (l+r)>>1;
			if (cows(m) < c) r = m-1; else l = m;
		}
		int ans = 0;
		FOR(i,l,r) if (cows(i) >= c) ans = i;
		printf("%d\n",ans);
	}
	
	return 0;
}
