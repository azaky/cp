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

#define MAXN 170
#define INF 1000000000
int ntc, n, energy, sleep, ndrink, drink, crash;
int eneed[MAXN], score[MAXN];
int dp[170][1700][25][4];

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d%d%d%d", &n, &energy, &sleep, &ndrink, &drink, &crash);
		// dp[hour][score / 10][drink][mask]
		// 168 * 168 * 10 * 24 * 2
		int totalscore = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &eneed[i], &score[i]);
			score[i] /= 10;
			totalscore += score[i];
		}
		int ans = 0;
		FOR(ih, 0, n) {
			FOR(it, 0, totalscore) {
				FOR(id, 0, ndrink) {
					FOR(im, 0, 3) {
						dp[ih][it][id][im] = -INF;
						if (ih == 0) {
							// only zero will have values
							if (im == 0 && id == 0 && it == 0) {
								dp[ih][it][id][im] = energy;
							}
						} else {
							int coffee = im & 1;
							REP(i, 2) {
								int pim = (i << 1) | (im >> 1);
								// attempt to solve problems
								if (it >= score[ih]) {
									if (coffee && id == 0) {
										// salah cuy
									} else {
										if (dp[ih - 1][it - score[ih]][id - coffee][pim] == -INF) {
											// salah cuy
										} else {
											int e = dp[ih - 1][it - score[ih]][id - coffee][pim] + (coffee ? drink : 0);
											if (i) {
												e -= crash;
											}
											if (e >= eneed[ih]) {
												MX(dp[ih][it][id][im], e - eneed[ih]);
											}
										}
									}
								}
								// sleep deh
								if (dp[ih - 1][it][id - coffee][pim] == -INF || coffee) {
									// salah cuy
								} else {
									int e = dp[ih - 1][it][id][pim] + sleep;
									if (i) {
										e -= crash;
									}
									MX(dp[ih][it][id][im], e);
								}
							}
						}
						if (ih == n) {
							if (dp[ih][it][id][im] > -INF) {
								MX(ans, it);
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans * 10);

	}

	return 0;
}