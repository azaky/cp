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

#define MOD 1000000007LL
#define MAXN 2020

int ntc, n, q, p[2][MAXN], c[MAXN][MAXN];

int find(int t, int a) {
	if (p[t][a] == a) {
		return a;
	} else {
		return p[t][a] = find(t, p[t][a]);
	}
}

void join(int t, int a, int b) {
	p[t][find(t, a)] = find(t, b);
}

bool familiar(int a, int b) {
	return find(0, a) == find(0, b) && find(1, a) == find(1, b);
}

int check(int a, int b) {
	if (find(0, a) == find(0, b) && find(1, a) == find(1, b) && !c[a][b]) {
		c[a][b] = c[b][a] = 1;
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &q);

		// reset everything here
		REP(i, n) {
			p[0][i] = p[1][i] = i;
		}
		REP(i, n) REP(j, n) {
			c[i][j] = 0;
		}
		// ll ans = 0;

		ll totalans = 0;

		REP(i, q) {
			int tipe, a, b;
			scanf("%d%d%d", &tipe, &a, &b);

			tipe--; a--; b--;

			join(tipe, a, b);

			ll ans = 0;
			REP(x, n) REP(y, n) {
				if (x <= y) break;
				if (familiar(x, y)) {
					ans++;
				}
			}

			// REP(j, n) {
			// 	if (j == a || j == b) continue;

			// 	ans += check(a, j);
			// 	ans += check(b, j);
			// }

			// ans += check(a, b);

			totalans += ans * (i + 1);
			totalans %= MOD;

			// printf("ans = %d\n", ans);
		}
		printf("%lld\n", totalans);
		fprintf(stderr, "case %d\n", itc);
	}

	return 0;
}