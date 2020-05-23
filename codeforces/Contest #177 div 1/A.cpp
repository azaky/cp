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

int n, k, ans[1111111];

int main(){
	scanf("%d%d",&n,&k);
	if (k > n || (k == 1 && n > 1)){puts("-1"); return 0;}
	if (n == 1 && k == 1){puts("a"); return 0;}
	FORD(i,k,1) ans[n-k+i] = i;
	FOR(i,1,n-k){
		FOR(j,1,2)if(ans[i-1] != j){ans[i] = j; break;}
	}
	if (ans[n-k] == ans[n-k+1]) swap(ans[n-k+1],ans[n-k+2]);
	FOR(i,1,n) printf("%c",ans[i]+96);
	
	return 0;
}
