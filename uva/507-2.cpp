#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
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

#define MAXN 21111
int ntc, n, a[MAXN], dp[MAXN];
ll sum[MAXN];

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d",&n);
		--n;
		FOR(i,1,n) scanf("%d",&a[i]);
		//FOR(i,1,n) sum[i] = sum[i-1] + a[i];
		int oda = 0, x = 0, y = 0;
		ll ans = 0;
		FOR(i,1,n){
			sum[i] = sum[i-1] + a[i];
			if (sum[i] < sum[oda]) oda = i;
			if (sum[i] - sum[oda] > ans){
				x = oda+1; y = i+1;
				ans = sum[i] - sum[oda];
			}
			else if (sum[i] - sum[oda] == ans && i-oda > y-x){
				x = oda+1; y = i+1;
			}
		}
		if (ans == 0){
			printf("Route %d has no nice parts\n",itc);
		}
		else{
			printf("The nicest part of route %d is between stops %d and %d\n",itc,x,y);
		}
	}
	
	return 0;
}
