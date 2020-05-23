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

#define MAXN 200200

int ntc, n, k, idxnode[MAXN], dp[MAXN], p[MAXN];
bool memo[MAXN];
vector<int> adjtemp[MAXN], adj[MAXN];

int find(int x) {
	if (p[x] == x) {
		return x;
	} else {
		return p[x] = find(p[x]);
	}
}

void join(int x, int y) {
	p[find(x)] = find(y);
}

int calc(int v) {
	if (memo[v]) {
		return dp[v];
	}
	memo[v] = true;
	dp[v] = 0;
	FORIT(it, adj[v]) {
		MX(dp[v], 1 + calc(*it));
	}
	// printf("dp[%d] = %d\n", v, dp[v]);
	return dp[v];
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &k);
		// upper: x
		// lower: x + n
		FOR(i, 1, n + n) {
			adjtemp[i].clear();
			p[i] = i;
		}
		REP(i, k) {
			int x, y, z;
			char tipe[10];
			scanf("%s%d%d%d", tipe, &x, &y, &z);
			if (tipe[0] == 'J') {
				swap(y, z);
				swap(x, y);
			}
			join(x, y);
			join(x + n, z + n);
			join(y + n, z);
			adjtemp[x].PB(x + n);
			adjtemp[y].PB(y + n);
			adjtemp[z].PB(z + n);
			// printf("ADDING (%d %d %d)...\n", x, y, z);
			// FOR(i, 1, n + n) {
			// 	printf("find(%d) = %d\n", i, find(i));
			// }
		}
		// find unique nodes
		int nnode = 0;
		FOR(i, 1, n + n) {
			if (find(i) == i) {
				idxnode[i] = nnode++;
			}
		}
		// printf("nnode = %d\n", nnode);
		REP(i, nnode) {
			adj[i].clear();
			memo[i] = false;
		}
		FOR(i, 1, n + n) {
			// printf("idxnode[%d] = %d\n", i, idxnode[find(i)]);
			FORIT(it, adjtemp[i]) {
				int from = idxnode[find(i)], to = idxnode[find(*it)];
				adj[from].PB(to);
			}
		}
		int ans = 0;
		REP(i, nnode) {
			MX(ans, calc(i));
		}
		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}
