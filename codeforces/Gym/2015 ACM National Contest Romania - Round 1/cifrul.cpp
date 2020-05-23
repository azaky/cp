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

#define MOD 1000000007LL
#define MAXN 111
int n, m, k, d;
int a[MAXN][MAXN];

int main(){
	int ntc;

	OPEN("cifrul");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d%d", &n, &m, &k, &d);
		REP(i, m) {
			REP(j, n) {
				scanf("%d", &a[i][j]);
			}
		}
		ll ans = 0;
		FOR(mask, 1, (1 << m) - 1) {
			// fprintf(stderr, "mask = %d\n", mask);
			// fflush(stderr);
			vector<int> c;
			REP(i, m) {
				if ((1 << i) & mask) {
					c.PB(i);
				}
			}
			ll ways = 1;
			REP(i, n) {
				if (2 * d + 1 >= k) {
					ways *= k;
					ways %= MOD;
					continue;
				}
				vector<pii> ranges;
				ranges.PB(MP(0, k - 1));
				FORIT(it, c) {
					vector<pii> cur, newRanges;
					int l = a[*it][i] - d, r = a[*it][i] + d;
					if (l < 0) {
						cur.PB(MP(l + k, k - 1));
						cur.PB(MP(0, r));
					} else if (r >= k) {
						cur.PB(MP(l, k - 1));
						cur.PB(MP(0, r % k));
					} else {
						cur.PB(MP(l, r));
					}
					FORIT(range, ranges) {
						vector<pii> t;
						FORIT(cc, cur) {
							l = max(range->A, cc->A);
							r = min(range->B, cc->B);
							if (l <= r) {
								t.PB(MP(l, r));
							}
						}
						FORIT(it, t) {
							newRanges.PB(*it);
						}
					}
					ranges = newRanges;
				}
				int multiplier = 0;
				FORIT(it, ranges) {
					multiplier += it->B - it->A + 1;
				}
				ways *= multiplier;
				ways %= MOD;
			}
			if (c.size() & 1) {
				ans += ways;
				ans %= MOD;
			} else {
				ans += MOD;
				ans -= ways;
				ans %= MOD;
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
