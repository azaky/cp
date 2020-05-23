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

#define MAXN 3300

int ntc, n, k;
db p, e[MAXN], pp[MAXN], temp[MAXN], dp[MAXN];

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%lf", &n, &k, &p);
		FOR(i, 0, k - 1) {
			e[i] = 0;
		}
		pp[0] = 1;
		FOR(i, 1, n) {
			pp[i] = pp[i - 1] * p;
		}
		temp[k] = pp[k];
		e[k] = temp[k];
		FOR(i, k + 1, n) {
			temp[i] = pp[i];
			FOR(j, k, i - 1) {
				temp[j] *= (1 - p) * i / (i - j);
				MN(temp[j], 1.);
			}
			e[i] = 0;
			FOR(j, k, i) {
				e[i] += temp[j];
			}
			MN(e[i], 1.);
		}
		// FOR(i, 0, n) {
		// 	printf("e[%d] = %.17lf\n", i, e[i]);
		// }
		dp[0] = 0;
		FOR(i, 1, n) {
			dp[i] = 0;
			FOR(j, 1, i) {
				MX(dp[i], dp[i - j] + e[j]);
			}
		}
		printf("Case #%d: %.17lf\n", itc, dp[n]);
		// break;
	}

	return 0;
}