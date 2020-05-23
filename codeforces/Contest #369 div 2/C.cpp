/* DELAPAN.3gp */
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

/* -------------- end of DELAPAN.3gp's template -------------- */


#define MAXN 111

int n, m, k, c[MAXN];
ll p[MAXN][MAXN], dp[MAXN][MAXN][MAXN];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 1, n) {
		scanf("%d", &c[i]);
	}
	FOR(i, 1, n) FOR(j, 1, m) {
		scanf("%I64d", &p[i][j]);
	}

	// dp[n][k][c]
	FOR(i, 0, n) FOR(j, 0, k) FOR(t, 0, m) {
		dp[i][j][t] = 3e12;
	}
	RESET(dp[0][0], 0);
	FOR(i, 1, n) {
		FOR(j, 1, k) {
			if (c[i]) {
				MN(dp[i][j][c[i]], dp[i - 1][j][c[i]]);
				FOR(t, 1, m) {
					if (t != c[i] || i == 1) {
						MN(dp[i][j][c[i]], dp[i - 1][j - 1][t]);
					}
				}
			} else {
				FOR(cc, 1, m) {
					MN(dp[i][j][cc], dp[i - 1][j][cc] + p[i][cc]);
					FOR(t, 1, m) {
						if (t != cc || i == 1) {
							MN(dp[i][j][cc], dp[i - 1][j - 1][t] + p[i][cc]);
						}
					}
				}
			}
			// FOR(t, 1, m) {
			// 	printf("dp[%d][%d][%d] = %lld\n", i, j, t, dp[i][j][t]);
			// }
		}
	}

	ll ans = 3e12;
	FOR(cc, 1, m) {
		MN(ans, dp[n][k][cc]);
	}
	if (ans > 1e12) {
		ans = -1;
	}
	cout << ans << endl;
	
	return 0;
}
