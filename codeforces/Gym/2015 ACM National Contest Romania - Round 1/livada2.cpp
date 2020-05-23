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

#define MAXN 305
int n, m, a[MAXN][MAXN], sum[MAXN][MAXN], dp[MAXN][MAXN], dpans[MAXN][MAXN];

int main(){
	int ntc;

	OPEN("livada2");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &m);
		FOR(i, 1, n) FOR(j, 1, m) {
			scanf("%d", &a[i][j]);
		}
		FOR(i, 1, n) {
			sum[i][0] = 0;
			FOR(j, 1, m) {
				sum[i][j] = sum[i][j - 1] + a[i][j];
			}
		}
		int ans = 0;
		FOR(i, 1, n) {
			FORD(len, m, 1) {
				FOR(f, 1, m - len + 1) {
					dp[f][f + len - 1] = sum[i][f + len - 1] - sum[i][f - 1];
					if (f > 1) {
						MX(dp[f][f + len - 1], dp[f - 1][f + len - 1]);
					}
					if (f + len - 1 < m) {
						MX(dp[f][f + len - 1], dp[f][f + len]);
					}
					dp[f + len - 1][f] = dp[f][f + len - 1];
				}
			}
			FOR(j, 1, m) {
				// start from here
				dpans[i][j] = dp[j][j];
				// or continue
				FOR(k, 1, m) {
					MX(dpans[i][j], dpans[i - 1][k] + dp[k][j]);
				}
				MX(ans, dpans[i][j]);
				// printf("dpans[%d][%d] = %d\n", i, j, dpans[i][j]);
			}
		}
		if (ans == 0) {
			// just to make sure
			ans = a[1][1];
			FOR(i, 1, n) FOR(j, 1, m) {
				MX(ans, a[i][j]);
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
