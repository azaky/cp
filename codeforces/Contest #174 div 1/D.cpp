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

#define MAXN 5555
int n, dp[MAXN];
LL a[MAXN], odd[MAXN], two[MAXN];

int main(){
	scanf("%d",&n);
	FORD(i,n,1) scanf("%I64d",&a[i]);
	a[0] = 1; dp[0] = 0;
	FOR(i,0,n){
		odd[i] = a[i];
		while (odd[i] % 2 == 0) odd[i] >>= 1LL;
		two[i] = 0;
		LL dummy = a[i];
		while (dummy % 2 == 0) dummy >>= 1LL, two[i]++;
	}
	FOR(i,1,n){
		dp[i] = i-1;
		FOR(j,1,i-1){
			if (odd[i] % odd[j] != 0) continue;
			if (two[j] >= i-j){
				if (two[j]-two[i] != i-j) continue;
			}
			dp[i] = min(dp[i],dp[j] + i-j-1);
		}
	}
	int ans = n;
	FOR(i,1,n) ans = min(ans,n-i+dp[i]);
	printf("%d\n",ans);
	
	return 0;
}
