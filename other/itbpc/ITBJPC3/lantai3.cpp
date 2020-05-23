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

LL dp[100000][2], T, n;

int main(){
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[2][0] = 5;
	dp[2][1] = 2;
	FOR(i,3,40){
		dp[i][0] = dp[i-1][0] + 2*dp[i-1][1] + 2*dp[i-2][0] + 2*dp[i-2][1] + 2*dp[i-3][0];
		dp[i][1] = dp[i-1][0] + dp[i-2][0] + dp[i-3][0];
	}
	cin >> T;
	while (T--){
		cin >> n;
		if (n == 0) cout << 0 << endl;
		else cout << dp[n][0] << endl;
	}
	
	return 0;
}
