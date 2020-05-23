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

#define MAXN 100100
#define MOD 1000000007

int n, two[MAXN], deg[MAXN], c[MAXN], memo[MAXN][2][2];
ll dp[MAXN][2][2];
vector<int> adj[MAXN];

ll calc(int v, int col, int p, int par = -1) {
	if (memo[v][col][p]) return dp[v][col][p];

	vector<ll> d[2];
	FORIT(it, adj[v]) {
		if (*it == par) continue;
		REP(i, 2) d[i].PB(calc(*it, i, col, v));
	}
	int s = SZ(d[0]);
	ll all = 1, same[2];
	same[0] = same[1] = 1;
	REP(i, s) {
		all = (all * (d[0][i] + d[1][i])) % MOD;
		REP(j, 2) {
			same[j] = (same[j] * d[j][i]) % MOD;
		}
	}
	if (v == 1) {
		dp[v][col][p] = all - same[1 - col];
	} else {
		if (p == col) {
			dp[v][col][p] = all;
		} else {
			dp[v][col][p] = all - same[p];
		}
	}
	while (dp[v][col][p] < 0) dp[v][col][p] += MOD;
	memo[v][col][p] = 1;
	// printf("dp[%d][%d][%d] = %lld\n", v, col, p, dp[v][col][p]);
	return dp[v][col][p];
}

int main(){
	scanf("%d", &n);
	two[0] = 1;
	FOR(i, 1, n) {
		two[i] = (two[i - 1] + two[i - 1]) % MOD;
	}
	REP(i, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].PB(y);
		adj[y].PB(x);
		deg[x]++;
		deg[y]++;
	}
	FOR(i, 1, n) {
		if (deg[i] == 1) {
			c[adj[i][0]]++;
		}
	}

	printf("%lld\n", (calc(1, 0, 0) * 2) % MOD);
	
	return 0;
}