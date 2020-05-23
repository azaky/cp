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

/* -------------- end of azaky's template -------------- */

#define MAXN 55

int ntc, n, r, x[MAXN], y[MAXN];

int main(){
	scanf("%d", &ntc);

	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &r);
		vector<int> xs, ys;
		FOR(i, 1, n) {
			scanf("%d%d", &x[i], &y[i]);
			xs.PB(x[i]);
			xs.PB(x[i] - r);
			ys.PB(y[i]);
			ys.PB(y[i] - r);
		}

		sort(ALL(xs)); xs.resize(unique(ALL(xs)) - xs.begin());
		sort(ALL(ys)); ys.resize(unique(ALL(ys)) - ys.begin());

		vector<ll> masks;
		FORIT(itx, xs) FORIT(ity, ys) {
			ll mask = 0;
			int xx = *itx;
			int yy = *ity;
			FOR(i, 1, n) {
				if (xx <= x[i] && x[i] <= xx + r && yy <= y[i] && y[i] <= yy + r) {
					mask |= 1LL << i;
				}
			}
			masks.PB(mask);
		}

		int ans = 0;
		FORIT(ita, masks) FORIT(itb, masks) {
			MX(ans, __builtin_popcountll((*ita) | (*itb)));
		}
		printf("Case #%d: %d\n", itc, ans);
	}
	
	return 0;
}