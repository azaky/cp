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

#define MAXN 100100

int r, c, n;
int x[MAXN], y[MAXN];
ll ans[11];

int main(){
	scanf("%d%d%d", &r, &c, &n);
	vector<pii> points;
	set<pii> colored;
	REP(i, n) {
		scanf("%d%d", &x[i], &y[i]);
		colored.insert(MP(x[i], y[i]));
		for (int ix = x[i] - 2; ix <= x[i]; ++ix) {
			for (int iy = y[i] - 2; iy <= y[i]; ++iy) {
				if (ix >= 1 && iy >= 1 && ix + 2 <= r && iy + 2 <= c) {
					points.PB(MP(ix, iy));
				}
			}
		}
	}
	sort(ALL(points));
	points.resize(unique(ALL(points)) - points.begin());
	
	FORIT(it, points) {
		int xx = it->A, yy = it->B;
		int tot = 0;
		REP(i, 3) REP(j, 3) {
			if (EXIST(MP(xx + i, yy + j), colored)) {
				tot++;
			}
		}
		ans[tot]++;
	}
	ans[0] = 1LL * (r - 2) * (c - 2);
	FOR(i, 1, 9) {
		ans[0] -= ans[i];
	}
	FOR(i, 0, 9) {
		printf("%lld\n", ans[i]);
	}

	return 0;
}
