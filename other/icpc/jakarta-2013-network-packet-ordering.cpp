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

#define MAXN 50005
#define MAXD 101
#define MOD 1000000009

int n, m, ntc, a[MAXN], b[MAXN], d, dp[MAXN][MAXD << 1];
bool memo[MAXN][MAXD << 1];

int calc(int i, int j) {
	if (i == 0 || j == 0) return 1;
	if (a[i] - b[j] > d) {
		return calc(i - 1, j);
	}
	if (b[j] - a[i] > d) {
		return calc(i, j - 1);
	}
	int delta = a[i] - b[j] + d;
	assert(0 <= delta && delta <= 200);
	if (memo[i][delta]) {
		return dp[i][delta];
	}
	memo[i][delta] = true;
	dp[i][delta] = 0;
	if (b[j] - a[i] < d) {
		dp[i][delta] += calc(i - 1, j);
		dp[i][delta] %= MOD;
	}
	if (a[i] - b[j] < d) {
		dp[i][delta] += calc(i, j - 1);
		dp[i][delta] %= MOD;
	}
	// printf("dp[%d][%d] = %d\n", i, j, dp[i][delta]);
	return dp[i][delta];
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &n, &m, &d);
		FOR(i, 1, n) {
			scanf("%d", &a[i]);
		}
		FOR(j, 1, m) {
			scanf("%d", &b[j]);
		}
		
		RESET(memo, 0);
		printf("Case #%d: %d\n", itc, calc(n, m));
	}

	return 0;
}