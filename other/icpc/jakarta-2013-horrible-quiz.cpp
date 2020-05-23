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

#define MAXN 1500

int ntc, n, m;
double c[MAXN], w[MAXN], x[MAXN], dpmax[MAXN][MAXN], dpmin[MAXN][MAXN];

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &m);
		FOR(i, 1, n) {
			int p;
			scanf("%d", &p);
			c[i] = (double)p / 100.;
		}
		FOR(i, 1, n) {
			int p;
			scanf("%d", &p);
			w[i] = (double)p / 100.;
			x[i] = 1. - c[i] - w[i];
		}
		// dp[n_soal][n_wrong]
		FOR(i, 0, m) {
			dpmax[0][i] = dpmin[0][i] = 1;
		}
		FOR(i, 1, n) {
			FOR(j, 0, m) {
				// give correct answer
				db vmax = dpmax[i - 1][j] * (x[i] + c[i]) - dpmax[i - 1][j] * w[i];
				db vmin = dpmin[i - 1][j] * (x[i] + c[i]) - dpmin[i - 1][j] * w[i];
				dpmax[i][j] = max(vmax, vmin);
				dpmin[i][j] = min(vmax, vmin);
				// give wrong answer
				if (j) {
					vmax = dpmax[i - 1][j - 1] * c[i] - dpmax[i - 1][j - 1] * (w[i] + x[i]);
					vmin = dpmin[i - 1][j - 1] * c[i] - dpmin[i - 1][j - 1] * (w[i] + x[i]);
					MX(dpmax[i][j], max(vmax, vmin));
					MN(dpmin[i][j], min(vmax, vmin));
				}
				// printf("dpmin[%d][%d] = %.3lf\n", i, j, dpmin[i][j]);
				// printf("dpmax[%d][%d] = %.3lf\n", i, j, dpmax[i][j]);
			}
		}
		double ans = 1;
		FOR(i, 0, m) {
			MN(ans, dpmin[n][i]);
		}
		printf("Case #%d: %.3lf\n", itc, ans * 15000);
	}

	return 0;
}
