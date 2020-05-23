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
int n, a[MAXN], s[MAXN], ns;

int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	
	int ans = 0;
	
	s[0] = 1111111111;
	
	ns = 1; s[ns] = a[0];
	FOR(i,1,n-1){
		while (a[i] > s[ns]){
			if (ns > 1){
				if ((s[ns] ^ s[ns-1]) > ans) ans = s[ns] ^ s[ns-1];
			}
			ns--;
		}
		s[++ns] = a[i];
	}
	FOR(i,2,ns) if ((s[i] ^ s[i-1]) > ans) ans = s[i] ^ s[i-1];
	
	ns = 1; s[ns] = a[n-1];
	FORD(i,n-2,0){
		while (a[i] > s[ns]){
			if (ns > 1){
				if ((s[ns] ^ s[ns-1]) > ans) ans = s[ns] ^ s[ns-1];
			}
			ns--;
		}
		s[++ns] = a[i];
	}
	FOR(i,2,ns) if ((s[i] ^ s[i-1]) > ans) ans = s[i] ^ s[i-1];
	
	printf("%d\n",ans);

	
	return 0;
}
