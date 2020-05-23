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

#define MAXN 111
int ntc, r, c, n, ct[3], ir[MAXN], ic[MAXN], t[MAXN], s[3][MAXN][MAXN], dp[MAXN][MAXN][MAXN];

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &r, &c, &n);
		set<int> vr, vc;
		ct[1] = ct[2] = 0;
		REP(i, n) {
			char _s[3];
			scanf("%d%d%s", &ir[i], &ic[i], _s);
			if (_s[0] == 'X') {
				t[i] = 1;
			}
			else {
				t[i] = 2;
			}
			ct[t[i]]++;
			vr.insert(ir[i]);
			vc.insert(ic[i]);
		}
		map<int, int> mr, mc;
		int pr = 0, pc = 0;
		FORIT(it, vr) {
			mr[*it] = ++pr;
		}
		FORIT(it, vc) {
			mc[*it] = ++pc;
		}
		RESET(s, 0);
		REP(i, n) {
			s[t[i]][mr[ir[i]]][mc[ic[i]]] = 1;
		}
		// FOR(k, 1, 2) FOR(i, 1, pr) FOR(j, 1, pc) {
		// 	s[k][i][j] = s[k][i][j] + s[k][i][j-1];
		// }
		int ans = n;
		FOR(ik, 1, 2) {
			FOR(i, 0, pr) {
				pii lo = MP(0, 0);
				FOR(j, 0, pc) {
					if (s[ik][i][j]) {
						lo.A++;
					}
					else if (s[3-ik][i][j]) {
						lo.B++;
					}
					FOR(k, 0, ct[ik]) {
						dp[i][j][k]  = -1;
						if (i == 0 && j == 0) {
							if (k == 0) dp[i][j][k] = 0;
							continue;
						}
						// ambil dari atas
						if (i) {
							if (k >= lo.A && dp[i-1][j][k-lo.A] != -1) {
								dp[i][j][k] = dp[i-1][j][k-lo.A] + lo.B;
							}
						}
						// ambil dari kiri
						if (j) {
							if (dp[i][j-1][k] != -1) {
								if (dp[i][j][k] == -1) {
									dp[i][j][k] = dp[i][j-1][k];
								}
								else {
									MN(dp[i][j][k], dp[i][j-1][k]);
								}
							}
						}
					}
				}
			}
			// evaluate answer
			FOR(k, 0, ct[ik]) {
				if (dp[pr][pc][k] != -1) {
					// printf("ik = %d, dp[%d] = %d\n", ik, k, dp[pr][pc][k]);
					MN(ans, max(dp[pr][pc][k], ct[ik] - k));
				}
			}
		}
		printf("Case #%d: %d\n", itc, ans);
	}

	//fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);

	return 0;
}
