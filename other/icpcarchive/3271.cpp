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

#define MAXN 22
#define INF 1000000000
int n, m, s, q, adj[MAXN][MAXN], dp[1<<MAXN], prev[1<<MAXN], f[MAXN];

int main(){
	int itc = 0;
	while (++itc) {
		scanf("%d", &n);
		if (n == -1) break;
		scanf("%d%d", &s, &m);
		s--;
		REP(i, n) REP(j, n) {
			adj[i][j] = INF;
		}
		REP(i, m) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			x--; y--;
			adj[x][y] = adj[y][x] = z;
		}
		int maskf = 1<<s;
		scanf("%d", &q);
		REP(i, q) {
			scanf("%d", &f[i]);
			f[i]--;
			maskf |= 1 << f[i];
		}
		REP(i, 1<<n) {
			dp[i] = INF;
		}
		dp[1<<s] = 0;
		int ans = 0;
		REP(mask, 1<<n) {
			if (!(mask&(1<<s)) || dp[mask] == INF) continue;
			REP(u, n) {
				if (!(mask&(1<<u))) continue;
				REP(v, n) {
					if (mask&(1<<v)) continue;
					int dnow = dp[mask] + adj[u][v];
					if (dp[mask|(1<<v)] > dnow) {
						dp[mask|(1<<v)] = dnow;
						prev[v] = u;
					}
				}
			}
			if ((mask&maskf) == maskf) {
				if (dp[mask] < dp[ans]) {
					ans = mask;
				}
			}
		}
		if (itc != 1) printf("\n");
		printf("Case %d: distance = %d\n", itc, dp[ans]);
		REP(iq, q) {
			int v = f[iq], mask = ans;
			printf("   %d", v+1);
			if (v != s) do {
				v = prev[v];
				printf("-%d", v+1);
			} while (v != s);
			printf("\n");
		}
	}

	return 0;
}
