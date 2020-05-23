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

#define sqr(x) ((x)*(x))

ll a[8][3], dst[28];

void brute(int k) {
	if (k == 8) {
		int n = 0;
		ll mind = -1;
		REP(i, 8) {
			FOR(j, i + 1, 7) {
				ll x = sqr(a[i][0] - a[j][0]) + sqr(a[i][1] - a[j][1]) + sqr(a[i][2] - a[j][2]);
				if (mind == -1 || x < mind) {
					mind = x;
				}
				dst[n++] = x;
			}
		}
		int c1 = 0, c2 = 0, c3 = 0;
		ll mind2 = mind + mind;
		ll mind3 = mind + mind2;
		REP(i, 28) {
			if (dst[i] == mind) {
				c1++;
			} else if (dst[i] == mind2) {
				c2++;
			} else if (dst[i] == mind3) {
				c3++;
			} else {
				return;
			}
		}
		if (c1 == 12 && c2 == 12 && c3 == 4) {
			puts("YES");
			REP(i, 8) {
				printf("%lld %lld %lld\n", a[i][0], a[i][1], a[i][2]);
			}
			exit(0);
		}
	} else {
		ll temp[3];
		REP(i, 3) {
			temp[i] = a[k][i];
		}
		do {
			brute(k + 1);
		} while (next_permutation(a[k], a[k] + 3));
		REP(i, 3) {
			a[k][i] = temp[i];
		}
	}
}

int main() {
	REP(i, 8) {
		REP(j, 3) {
			scanf("%lld", &a[i][j]);
		}
		sort(a[i], a[i] + 3);
	}

	brute(0);
	puts("NO");

	return 0;
}