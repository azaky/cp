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

ll ten[19];

ll reverse(ll n) {
	ll ret = 0;
	while (n > 0) {
		ret *= 10LL;
		ret += n % 10LL;
		n /= 10LL;
	}
	return ret;
}

int calc(vector<vector<int> > a) {
	int r = a.size();
	int c = a[0].size();
	int unhappiness = 0;

	REP(i, r) {
		REP(j, c) {
			if (a[i][j]) {
				if (i > 0 && a[i-1][j]) unhappiness++;
				if (i < r-1 && a[i+1][j]) unhappiness++;
				if (j > 0 && a[i][j-1]) unhappiness++;
				if (j < c-1 && a[i][j+1]) unhappiness++;
			}
			// if (a[i][j]) printf("1"); else printf("0");
		}
		// printf("\n");
	}
	// printf("unhappiness = %d\n", unhappiness);
	return unhappiness / 2;
}

int main(int argc, char** argv) {
	if (argc > 1) {
		OPEN(argv[1]);
	}

	int ntc;

	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		int r, c, k;
		scanf("%d%d%d", &r, &c, &k);

		// naive bruteforce solution
		int ans = r * (c - 1) + (r - 1) * c;
		int rc = r * c;
		REP(mask, 1 << rc) {
			if (__builtin_popcount(mask) != k) continue;

			vector<vector<int> > a;
			REP(i, r) {
				a.PB(vector<int>());
				REP(j, c) {
					int shift = i * c + j;
					a[i].PB(mask & (1 << shift));
				}
			}

			MN(ans, calc(a));
		}
		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}