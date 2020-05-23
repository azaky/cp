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

#define MAXN 1100
int ntc, n, k, s[MAXN], dmin[MAXN], dmax[MAXN];

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &k);
		REP(i, n - k + 1) {
			scanf("%d", &s[i]);
		}

		int ans = 0;
		REP(i, k) {
			int _min = 0, _max = 0, diff = 0;
			for (int j = i + k; j < n; j += k) {
				diff += s[j - k + 1] - s[j - k];
				MN(_min, diff);
				MX(_max, diff);
			}
			dmin[i] = _min;
			dmax[i] = _max;
			MX(ans, dmax[i] - dmin[i]);
		}

		int f = 0, sum = 0;
		REP(i, k) {
			sum += -dmin[i];
			f += ans - (dmax[i] - dmin[i]);
		}
		sum %= k;
		sum += k;
		sum %= k;
		s[0] %= k;
		s[0] += k;
		s[0] %= k;

		int diff = s[0] - sum;
		diff %= k;
		diff += k;
		diff %= k;
		if (f < diff) {
			ans++;
		}

		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}