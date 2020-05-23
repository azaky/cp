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

#define MAXN 100100

int ntc, n, m, l;
ll w[MAXN], d;

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d%lld", &l, &n, &m, &d);
		REP(i, n) {
			scanf("%lld", &w[i]);
		}
		m = min(l, m);
		priority_queue<pair<ll, int> > washer;
		priority_queue<ll> dryer;
		REP(i, n) {
			washer.push(MP(-w[i], i));
		}
		REP(i, m) {
			dryer.push(0LL);
		}
		ll ans = 0;
		REP(i, l) {
			pair<ll, int> top = washer.top(); washer.pop();
			ll t = -top.A;
			ll x = top.B;
			washer.push(MP(-(t + w[x]), x));
			// if (i < 10) printf("times: %lld, using %lld\n", t, w[x]);

			ll dry = -dryer.top(); dryer.pop();
			MX(t, dry);
			t += d;
			MX(ans, t);
			dryer.push(-t);
		}
		printf("Case #%d: %lld\n", itc, ans);
		fprintf(stderr, "Case #%d: %lld\n", itc, ans);
	}

	return 0;
}