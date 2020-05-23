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

#define INF 0x7FFFFFFF
#define MAXN 1100
#define MAXK 33

int ntc, n, k, pp, c[MAXN][MAXK];
int memo[MAXN][MAXK][2], dp[MAXN][MAXK][2];
vector<int> adj[MAXN];

int calc(int v, int x, int same, int p) {
	if (memo[v][x][same]) {
		return dp[v][x][same];
	}
	memo[v][x][same] = 1;
	vector<vector<int> > temp;
	FORIT(it, adj[v]) {
		if (*it == p) continue;
		int min0 = INF, min1 = INF;
		FOR(i, 1, k) {
			if (i == x) {
				min1 = calc(*it, i, 1, v);
			} else {
				MN(min0, calc(*it, i, 0, v));
			}
		}
		vector<int> ttemp;
		ttemp.PB(min0);
		ttemp.PB(min1);
		temp.PB(ttemp);
	}
	int dpp[SZ(temp) + 1][3];
	dpp[0][0] = dpp[0][1] = dpp[0][2] = 0;
	printf("v = %d, x = %d\n", v, x);
	FOR(i, 1, SZ(temp)) {
		dpp[i][0] = dpp[i - 1][0] + temp[i - 1][0];
		dpp[i][1] = min(dpp[i - 1][0] + temp[i - 1][1], dpp[i - 1][1] + temp[i - 1][0]);
		dpp[i][2] = min(dpp[i - 1][1] + temp[i - 1][1], dpp[i - 1][2] + min(temp[i - 1][0], temp[i - 1][1]));
		REP(j, 3) {
			printf("dpp[%d][%d] = %d\n", i, j, dpp[i][j]);
		}
	}
	if (same) {
		dp[v][x][same] = min(dpp[SZ(temp)][0], min(dpp[SZ(temp)][1], dpp[SZ(temp)][2]) + pp);
	} else {
		// printf("SZ = %d\n", SZ(temp));
		// printf("%d\n", dpp[SZ(temp)][0]);
		// printf("%d\n", dpp[SZ(temp)][1]);
		// printf("%d\n", dpp[SZ(temp)][2] + p);
		// printf("P = %d\n", p);
		dp[v][x][same] = min(min(dpp[SZ(temp)][0], dpp[SZ(temp)][1]), dpp[SZ(temp)][2] + pp);
	}
	dp[v][x][same] += c[v][x];
	printf("dp[%d][%d][%d] = %d\n", v, x, same, dp[v][x][same]);
	return dp[v][x][same];
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &n, &k, &pp);
		FOR(i, 1, n) FOR(j, 1, k) {
			scanf("%d", &c[i][j]);
		}
		FOR(i, 1, n) {
			adj[i].clear();
		}
		REP(i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			adj[x].PB(y);
			adj[y].PB(x);
		}
		RESET(memo, 0);
		int ans = INF;
		FOR(i, 1, k) {
			MN(ans, calc(1, i, 0, -1));
		}
		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}