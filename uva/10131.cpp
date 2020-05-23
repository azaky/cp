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

#define MAXN 1111
struct elephant{
	int w, iq, idx;
} a[MAXN];
int n, dp[MAXN], next[MAXN];

int calc(int k){
	if (dp[k] != 0) return dp[k];
	next[k] = -1;
	REP(i,n) if (a[i].w > a[k].w && a[i].iq < a[k].iq){
		if (calc(i) > dp[k]){
			dp[k] = calc(i);
			next[k] = i;
		}
	}
	dp[k]++;
	return dp[k];
}

int main(){
	n = 0;
	int _w, _iq;
	while (scanf("%d %d",&_w,&_iq) == 2){
		a[n].w = _w;
		a[n].iq = _iq;
		a[n].idx = n;
		++n;
	}
	int ans = 0;
	REP(i,n) if (calc(i) > ans) ans = calc(i);
	printf("%d\n",ans);
	REP(i,n) if (calc(i) == ans){
		int now = i;
		REP(j,ans){
			printf("%d\n",now+1);
			now = next[now];
		}
		break;
	}
	return 0;
}
