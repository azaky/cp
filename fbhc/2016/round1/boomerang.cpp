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

#define MAXN 18
#define MAX2N (1 << MAXN)

const int m[] = {1, 2, 3, 5, 9};

int ntc, n, a[MAXN][MAXN];
int dp[MAXN][MAX2N], ansmax[MAXN], ansmin[MAXN];
int lg2[MAX2N];

void dfs(int x, int mask2, const int t, const int mask, const int k) {
	if (x == n) {
		if (__builtin_popcount(mask2) != k) return;
		int thismask = mask ^ mask2;
		REP(i, n) {
			if ((1 << i) & mask2) {
				if (dp[i][mask2] && dp[t][thismask] && a[t][i]) {
					dp[t][mask] = 1;
					// printf("[%d][%d] cause [%d][%d]\n", t, mask, i, mask2);
				}
			}
		}
	} else {
		if ((1 << x) & mask) {
			dfs(x + 1, mask2, t, mask, k);
			if (x != t) {
				dfs(x + 1, mask2 ^ (1 << x), t, mask, k);
			}
		} else {
			dfs(x + 1, mask2, t, mask, k);
		}
	}
}

int main() {
	REP(i, 10) {
		lg2[1 << i] = i;
	}

	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		REP(i, n) REP(j, n) {
			scanf("%d", &a[i][j]);
		}
		REP(i, n) {
			ansmax[i] = 0;
		}
		REP(mask, 1 << n) {
			int k = __builtin_popcount(mask);
			if ((k & -k) != k) continue;
			if (k == 0) continue;
			REP(i, n) {
				if ((1 << i) & mask) {
					if (k == 1) {
						dp[i][mask] = 1;
					} else {
						dp[i][mask] = 0;
						dfs(0, 0, i, mask, k / 2);
					}
					if (dp[i][mask]) {
						MX(ansmax[i], lg2[k]);
						// printf("%2d %x\n", i, mask);
					}
				}
			}
		}
		REP(i, n) {
			ansmin[i] = 0;
			int total = 0;
			REP(j, n) {
				total += a[i][j];
			}
			if (total == n - 1) {
				ansmin[i] = lg2[n];
			}
		}
		printf("Case #%d:\n", itc);
		REP(i, n) {
			printf("%d %d\n", m[lg2[n] - ansmax[i]], m[lg2[n] - ansmin[i]]);
		}
	}

	return 0;
}