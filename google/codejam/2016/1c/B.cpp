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

ll n, x;
int adj[555][555];

int main() {
	OPEN("B-large");
	int ntc;
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%lld%lld", &n, &x);
		if (x > (1LL << (n - 2))) {
			printf("Case #%d: IMPOSSIBLE\n", itc);
			continue;
		}
		printf("Case #%d: POSSIBLE\n", itc);
		RESET(adj, 0);
		REP(i, n - 1) {
			FOR(j, i + 1, n - 2) {
				adj[i][j] = 1;
			}
		}
		ll k = n - 2;
		while (k >= 0) {
			ll addum = k ? (1LL << (k - 1)) : 1;
			if (x >= addum) {
				x -= addum;
				adj[k][n - 1] = 1;
			}
			--k;
		}
		REP(i, n) {
			REP(j, n) {
				putchar('0' + adj[i][j]);
			}
			putchar('\n');
		}
	}

	return 0;
}