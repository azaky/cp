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

#define MAXN 505

int n, k, a[MAXN], dp[MAXN][MAXN], dprev[MAXN][MAXN], ans[MAXN];

int main(){
	scanf("%d%d", &n, &k);
	FOR(i, 1, n) scanf("%d", &a[i]);
	// dp[day][last]
	RESET(dp, -1);
	FOR(i, a[1], max(a[1], k)) {
		dp[1][i] = i - a[1];
	}
	FOR(i, 2, n) {
		FOR(last, a[i], max(a[i], k)) {
			FOR(p, max(k - last, a[i - 1]), max(a[i - 1], k)) {
				if (dp[i][last] == -1) {
					dp[i][last] = dp[i - 1][p] + last - a[i];
					dprev[i][last] = p;
				} else if (dp[i][last] > dp[i - 1][p] + last - a[i]) {
					dp[i][last] = dp[i - 1][p] + last - a[i];
					dprev[i][last] = p;
				}
			}
		}
	}

	ans[n] = 0;
	FOR(last, 0, k) {
		if (dp[n][ans[n]] == -1 || dp[n][ans[n]] > dp[n][last]) {
			ans[n] = last;
		}
	}
	FORD(i, n - 1, 1) {
		ans[i] = dprev[i + 1][ans[i + 1]];
	}
	printf("%d\n", dp[n][ans[n]]);
	FOR(i, 1, n) {
		printf("%d", ans[i]);
		if (i < n) putchar(' '); else putchar('\n');
	}

	return 0;
}