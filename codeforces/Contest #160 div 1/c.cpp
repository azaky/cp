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

LL v[100][100], dp[100][100];

LL c(LL n, LL k){
	if (n < k) return 0;
	if (n == k || k == 0) return 1LL;
	if (v[n-k][k]) return dp[n-k][k];
	v[n-k][k] = 1;
	return dp[n-k][k] = c(n-1,k)+c(n-1,k-1);
}

int main(){
	LL n, _n, t, ans = 0;
	int kt, kn, bit[100];
	cin >> n >> t;
	//t power of 2
	kt = 1;
	for (; !(t & 1); ++kt, t >>= 1);
	if (t != 1){
		printf("0\n"); return 0;
	}
	n += 2;
	_n = n; kn = 0;
	while (_n > 0){
		bit[kn++] = _n & 1;
		_n >>= 1;
	}
	//REPD(i,kn) printf("%d",bit[i]); printf("\n");
	
	REP(i,kn){
		if (bit[i]){
			int has = 0;
			FOR(j,i+1,kn-1) has += bit[j];
			if (has > kt) continue;
			ans += c(i,kt-has);
		}
	}
	
	if (kt == 1) ans--;
	
	cout << ans << endl;
	
	return 0;
}
