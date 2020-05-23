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
typedef unsigned long long ll;
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

int ntc, np;
ll p[100], n;

ll ans;
void dfs(int v, ll num, ll count) {
	if (v == np) {
		// printf("num = %lld, count = %lld\n", num, count);
		if (count) {
			if (count & 1) {
				ans += ((n / num) << (count - 1));
			} else {
				ans -= ((n / num) << (count - 1));
			}
		}
	} else {
		dfs(v + 1, num, count);
		ll nextnum = num * p[v];
		if (nextnum <= n && nextnum / p[v] == num) {
			dfs(v + 1, nextnum, count + 1);
		}
	}
}

int main() {
	scanf("%d", &ntc);
	vector<ll> anss;
	FOR(itc, 1, ntc) {
		scanf("%lld%d", &n, &np);
		REP(i, np) {
			scanf("%lld", &p[i]);
		}
		ans = 0;
		dfs(0, 1, 0);
		anss.PB(ans);
	}
	FORIT(it, anss) {
		printf("%lld\n", *it);
	}

	return 0;
}
