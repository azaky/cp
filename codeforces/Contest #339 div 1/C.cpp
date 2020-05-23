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

#define MAXN 30

int n, a[MAXN], odd, nodd = 0;

int main() {
	scanf("%d", &n);
	int ans = 0;
	REP(i, n) {
		scanf("%d", &a[i]);
		ans = __gcd(ans, a[i]);
		if (a[i] & 1) {
			nodd++;
			odd = i;
		}
	}
	if (nodd > 1) {
		puts("0");
		REP(i, n) {
			REP(j, a[i]) {
				putchar('a' + i);
			}
		}
		puts("");
	} else if (nodd == 1) {
		printf("%d\n", ans);
		REP(k, ans) {
			REP(i, n) {
				if (i == odd) continue;
				REP(j, a[i] / 2 / ans) {
					putchar('a' + i);
				}
			}
			REP(j, a[odd] / ans) {
				putchar('a' + odd);
			}
			REPD(i, n) {
				if (i == odd) continue;
				REP(j, a[i] / 2 / ans) {
					putchar('a' + i);
				}
			}
		}
		puts("");
	} else {
		int ans = a[0];
		REP(i, n) {
			ans = __gcd(ans, a[i]);
		}
		printf("%d\n", ans);
		REP(k, ans) {
			if (k & 1) {
				REP(i, n) {
					REP(j, a[i] / ans) {
						putchar('a' + i);
					}
				}
			} else {
				REPD(i, n) {
					REP(j, a[i] / ans) {
						putchar('a' + i);
					}
				}
			}
		}
		puts("");
	}

	return 0;
}
