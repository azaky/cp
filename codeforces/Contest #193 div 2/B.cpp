#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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

#define MAXN 222222

int n, k, dp1[MAXN];
pii dp2[MAXN];
ll a[MAXN], sum[MAXN];

ll getsum(int a, int l){
	return sum[a+l-1] - sum[a-1];
}

int main(){
	cin >> n >> k;
	FOR(i,1,n) scanf("%I64d",&a[i]);
	FOR(i,1,n) sum[i] = sum[i-1] + a[i];
	dp1[k] = 1;
	FOR(i,k+1,n){
		dp1[i] = dp1[i-1];
		if (getsum(i-k+1,k) > getsum(dp1[i],k)) dp1[i] = i-k+1;
	}
	dp2[2*k] = MP(1,k+1);
	FOR(i,2*k+1,n){
		dp2[i] = dp2[i-1];
		if (getsum(i-k+1,k) + getsum(dp1[i-k],k) > getsum(dp2[i].A,k) + getsum(dp2[i].B,k)) dp2[i] = MP(dp1[i-k],i-k+1);
	}
	printf("%d %d\n",dp2[n].A,dp2[n].B);
	
	return 0;
}
