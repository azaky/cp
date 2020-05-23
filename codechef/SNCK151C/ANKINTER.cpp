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

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &w);
		REP(i, n) {
			scanf("%d", &a[i]);
		}
		// init here

		vector<pii> maxx, minn;
		ll ans = 0;
		REP(i, n) {
			int x = a[i];
			int imin = SZ(minn), imax = SZ(maxx);
			while (imin >= 0 && minn[imin - 1].A > x) {
				imin--;
			}
			while (imax >= 0 && maxx[imax - 1].A < x) {
				imax--;
			}

			// increasing index
			data.update(1, i, -1);

			// updating min and max
			FOR(j, imin, SZ(minn) - 1) {
				int l = j ? minn[j - 1].B + 1 : 1;
				int r = minn[j].B;
				data.update(l, r, minn[j].A - x);
			}
			FOR(j, imax, SZ(maxx) - 1) {
				int l = j ? maxx[j - 1].B + 1 : 1;
				int r = maxx[j].B;
				data.update(l, r, x - maxx[j].A);
			}
			while (SZ(minn) > imin) minn.pop_back();
			while (SZ(maxx) > imax) maxx.pop_back();
			minn.PB(MP(x, i + 1));
			maxx.PB(MP(x, i + 1));

			ans += (ll)data.query(1, i - w + 2);
		}
		printf("%lld\n", ans);
	}
    
	return 0;
}