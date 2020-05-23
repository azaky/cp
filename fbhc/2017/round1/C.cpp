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

#define MAXN 111
#define MAXM 5050

#define INF 10000000000LL

int ntc, n, m, k, a[MAXM], b[MAXM], g[MAXM];
ll d[MAXN][MAXN], dp[MAXM][10];
pii s[MAXM];

int main(){
	scanf("%d", &ntc);

	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &n, &m, &k);

		// RESET EVERYTHING HERE
		FOR(i, 0, n) {
			FOR(j, 0, n) d[i][j] = INF;
			d[i][i] = 0;
		}

		FOR(i, 1, m) {
			scanf("%d%d%d", &a[i], &b[i], &g[i]);
			d[a[i]][b[i]] = d[b[i]][a[i]] = g[i];
		}
		FOR(i, 1, k) {
			scanf("%d%d", &s[i].A, &s[i].B);
		}
		s[0] = MP(1, 1);

		FOR(x, 1, n) FOR(i, 1, n) FOR(j, 1, n) {
			if (d[i][j] > d[i][x] + d[x][j]) {
				d[i][j] = d[i][x] + d[x][j];
			}
		}

		// FOR(i, 1, n) {
		// 	FOR(j, 1, n) printf("%d ", d[i][j]);
		// 	puts("");
		// }

		// states are:
		// 0: delivered
		// 1: loaded
		// 2: i and i-1 both loaded
		// 3: loaded after both loaded and delivering i-1
		dp[0][0] = 0;
		dp[0][1] = dp[0][2] = dp[0][3] = INF;
		FOR(i, 1, k) {
			// calc for both loaded
			// prev must be 1
			dp[i][2] = i == 1 ? INF : dp[i - 1][1] + d[s[i - 1].A][s[i].A];
			MN(dp[i][2], INF);

			// calc for loaded
			// prev is either delivered
			dp[i][1] = dp[i - 1][0] + d[s[i - 1].B][s[i].A];
			MN(dp[i][2], INF);

			// calc for loaded after both loaded
			// prev is both loaded
			dp[i][3] = i == 1 ? INF : dp[i][2] + d[s[i].A][s[i - 1].B];
			MN(dp[i][3], INF);

			// calc for delivered
			dp[i][0] = min(dp[i][1] + d[s[i].A][s[i].B], dp[i][3] + d[s[i - 1].B][s[i].B]);
			MN(dp[i][0], INF);

			// FOR(state, 0, 2) printf("dp[%d][%d] = %d\n", i, state, dp[i][state]);
		}

		if (dp[k][0] == INF) dp[k][0] = -1;

		printf("Case #%d: %lld\n", itc, dp[k][0]);
	}

	return 0;
}
