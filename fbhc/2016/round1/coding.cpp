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

#define MAXN 100100

int ntc, n, a[MAXN], dp[MAXN];

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		FOR(i, 1, n) {
			scanf("%d", &a[i]);
		}
		dp[0] = 0;
		FOR(i, 1, n) {
			dp[i] = dp[i - 1] + 3;
			FOR(k, 2, 4) {
				if (i < k) {
					break;
				}
				// use last k probs in a contest
				bool increasing = true;
				REP(j, k - 1) {
					if (a[i - j] <= a[i - j - 1]) {
						increasing = false;
						break;
					}
				}
				if (!increasing) {
					continue;
				}
				// check gap
				int gap = 0;
				REP(j, k - 1) {
					gap += (a[i - j] - a[i - j - 1] - 1) / 10;
				}
				if (k + gap <= 4) {
					MN(dp[i], dp[i - k] + 4 - k);
				}
			}
		}
		printf("Case #%d: %d\n", itc, dp[n]);
	}

	return 0;
}