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

#define MOD 1000000007

int ntc, n, m, k;
ll dp[10][500][100], comb[100][100];

string toBinaryString(int mask, int n) {
	string res = "";
	REP(i, n) {
		if (mask & (1 << i)) {
			res += '1';
		} else {
			res += '0';
		}
	}
	return res;
}

int main() {
	REP(i, 100) REP(j, 100) {
		if (i == 0 || j == 0) {
			comb[i][j] = 1;
		} else {
			comb[i][j] = (comb[i - 1][j] + comb[i][j - 1]) % MOD;
		}
	}

	scanf("%d", &ntc);

	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &n, &m, &k);

		RESET(dp, 0);
		FOR(c, 1, m) {
			REP(mask, 1 << n) {
				int wall[8], nwall = 0;;
				REP(i, n) {
					wall[i] = (mask & (1 << i)) >> i;
					nwall += wall[i];
				}
				if (c == 1) {
					int pass[8];
					pass[0] = (wall[0] == 0);
					for (int i = 1; i < n; ++i) {
						pass[i] = pass[i - 1] && (wall[i] == 0);
					}
					int tmask = 0;
					REP(i, n) {
						tmask |= pass[i] << i;
					}
					dp[c][tmask][nwall]++;
				} else {
					REP(pmask, 1 << n) {
						int pass[8];
						pass[0] = (wall[0] == 0) && (pmask & 1);
						for (int i = 1; i < n; ++i) {
							pass[i] = (wall[i] == 0) && (pass[i - 1] || (pmask & (1 << i)));
						}
						int tmask = 0;
						REP(i, n) {
							tmask |= pass[i] << i;
						}
						FOR(ik, nwall, k) {
							dp[c][tmask][ik] += dp[c - 1][pmask][ik - nwall];
							dp[c][tmask][ik] %= MOD;
						}
					}
				}
			}
			// REP(i, 1 << n) {
			// 	REP(ik, k + 1) {
			// 		printf("dp[c = %d][mask = %s][k = %d] = %lld\n", c, toBinaryString(i, n).c_str(), ik, dp[c][i][ik]);
			// 	}
			// }
		}
		ll ans = 0;
		FOR(ik, 0, k) {
			ans += comb[n * m - ik][ik];
			ans %= MOD;
			REP(mask, 1 << (n - 1)) {
				ans += MOD - dp[m][mask ^ (1 << (n - 1))][ik];
				ans %= MOD;
				// printf("dp[%d][%d][%d] = %lld\n", m, mask, ik, dp[m][mask][ik]);
			}
		}
		printf("Case #%d: %d\n", itc, (int)ans);
	}

	return 0;
}