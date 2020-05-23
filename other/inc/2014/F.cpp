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
#include <limits>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

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

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 100100
int ntc, n, dp[MAXN][2], p[MAXN], x[MAXN];
vector<int> child[MAXN];

int calc(int v, int xxx) {
	if (dp[v][xxx] != -1) {
		return dp[v][xxx];
	}
	dp[v][xxx] = xxx ^ x[v];
	if (xxx == 1) {
		//all child must be true
		FORIT(it, child[v]) {
			dp[v][xxx] += calc(*it, 1);
		}
	}
	else {
		// suka suka
		FORIT(it, child[v]) {
			dp[v][xxx] += min(calc(*it, 0), calc(*it, 1));
		}
	}
	// printf("dp[%d][%d] = %d\n", v, xxx, dp[v][xxx]);
	return dp[v][xxx];
}

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		FOR(i, 1, n) {
			child[i].clear();
			dp[i][0] = dp[i][1] = -1;
		}
		FOR(i, 1, n) {
			scanf("%d", &p[i]);
			child[p[i]].PB(i);
		}
		FOR(i, 1, n) {
			scanf("%d", &x[i]);
		}
		printf("Case #%d: %d\n", itc, min(calc(1, 0), calc(1, 1)));
	}
	
	return 0;
}
