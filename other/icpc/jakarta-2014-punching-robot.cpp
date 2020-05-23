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

#define MOD 997
#define MAXN 15
int ntc, n, m, k;
int adj[MAXN][MAXN];
pii r[MAXN];
int c[MOD + 5][MOD + 5];

int comb(int n, int k) {
	int ret = 1;
	while (n > 0 || k > 0) {
		int nm = n % MOD;
		int km = k % MOD;
		if (nm < km) {
			ret = 0;
		} else {
			ret *= c[nm - km][km];
			ret %= MOD;
		}
		n /= MOD;
		k /= MOD;
	}
	return ret;
}

int numWays(int r, int c) {
	if (r <= 0 || c <= 0) {
		return 0;
	} else {
		return comb(r + c - 2, c - 1);
	}
}

int main() {
	for (int i = 0; i < MOD; ++i) {
		for (int j = 0; j < MOD; ++j) {
			if (i == 0 || j == 0) {
				c[i][j] = 1;
			} else {
				c[i][j] = (c[i - 1][j] + c[i][j - 1]) % MOD;
			}
		}
	}
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &n, &m, &k);
		REP(i, k) {
			scanf("%d%d", &r[i].A, &r[i].B);
			r[i].A--; r[i].B--;
		}
		// determine order
		RESET(adj, 0);
		REP(i, k) REP(j, k) {
			if (i == j) continue;
			if (r[j].A < r[i].A - 2 || r[j].B < r[i].B - 2) {
				adj[i][j] = 0;
			} else {
				adj[i][j] = 1;
			}
		}
		// inclusion-exclusion
		int ans = 0;
		REP(mask, 1 << k) {
			int used[k], visited[k];
			int nk = 0;
			REP(i, k) {
				used[i] = (mask & (1 << i)) >> i;
				nk += used[i];
				visited[i] = 0;
			}
			if (nk == 0) continue;
			bool valid = true;
			vector<int> order;
			REP(ik, nk) {
				vector<int> candidates;
				REP(i, k) {
					if (!used[i] || visited[i]) continue;
					bool yes = true;
					REP(j, k) {
						if (used[j] && !visited[j] && adj[j][i]) {
							yes = false;
							break;
						}
					}
					if (yes) {
						candidates.PB(i);
					}
				}
				if (SZ(candidates) != 1) {
					valid = false;
					break;
				}
				order.PB(candidates[0]);
				visited[candidates[0]] = 1;
			}
			if (!valid) continue;
			int ways[k][3];
			REP(i, 3) {
				ways[0][i] = numWays(r[order[0]].A + i, r[order[0]].B + 2 - i);
			}
			FOR(ik, 1, nk - 1) {
				REP(i, 3) {
					ways[ik][i] = 0;
					REP(ip, 3) {
						ways[ik][i] += ways[ik - 1][ip] * numWays(r[order[ik]].A + i - r[order[ik - 1]].A - ip + 1, r[order[ik]].B - i - r[order[ik - 1]].B + ip + 1);
						ways[ik][i] %= MOD;
					}
				}
			}
			int totalways = 0;
			REP(i, 3) {
				totalways += ways[nk - 1][i] * numWays(n - (r[order[nk - 1]].A + i) + 1, m - (r[order[nk - 1]].B + 2 - i) + 1);
				totalways %= MOD;
				// printf("(%d, %d)\n", n - (r[order[nk - 1]].A + i) + 1, m - (r[order[nk - 1]].B + 2 - i) + 1);
			}
			if (nk & 1) {
				ans += totalways;
			} else {
				ans += MOD - totalways;
			}
			ans %= MOD;
			// printf("mask = %d, ways = %d\n", mask, totalways);
			// FORIT(it, order) {
			// 	printf("[%d, %d]:", r[*it].A, r[*it].B);
			// 	REP(i, 3) printf(" %d", ways[*it][i]);
			// 	printf("\n");
			// }
		}
		// printf("ans = %d\n", ans);
		ans = (numWays(n, m) + MOD - ans) % MOD;
		printf("Case #%d: %d\n", itc, (int)ans);
	}


	return 0;
}