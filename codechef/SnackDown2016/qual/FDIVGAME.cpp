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

/* -------------- end of azaky's template -------------- */

vector<pair<int, ll> > mgrundy;

int grundy(ll x) {
	if (x == 0) {
		return 0;
	}
	ll total = 0;
	int i = -1;
	while (total < x) {
		total += mgrundy[++i].B;
		// printf("total = %lld\n", total);
	}
	// printf("grundy(%lld) = %d: i = %d\n", x, mgrundy[i].A, i);
	return mgrundy[i].A;
	// if (EXIST(x, mgrundy)) {
	// 	return mgrundy[x];
	// }
	// set<int> g;
	// FOR(i, 2, 6) {
	// 	g.insert(grundy(x / i));
	// }
	// int ret = 0;
	// while (EXIST(ret, g)) {
	// 	++ret;
	// }
	// return mgrundy[x] = ret;
}

int ntc, n;

int main(){
	// mgrundy[0] = 0;
	// int last = -1, cot = 0;
	// FOR(i, 1, 10000) {
	// 	int g = grundy(i);
	// 	if (g == last) {
	// 		cot++;
	// 	} else {
	// 		printf("%d: %d\n", last, cot);
	// 		last = g;
	// 		cot = 1;
	// 	}
	// }
	ll now = 1;
	ll total = 0;
	while (total < 1000000000000000000LL && total >= 0) {
		// printf("%lld\n", total);
		// fflush(stdout);
		ll add = 0, lastnow;
		mgrundy.PB(MP(1, now));
		add += now;
		lastnow = now;
		now *= 2LL;
		if (now < lastnow) {
			break;
		}
		mgrundy.PB(MP(2, now));
		add += now;
		mgrundy.PB(MP(3, now));
		add += now;
		lastnow = now;
		now *= 3LL;
		if (now < lastnow) {
			break;
		}
		mgrundy.PB(MP(0, now));
		add += now;
		now *= 2LL;
		if (now < lastnow) {
			break;
		}
		total += add;
	}

	// ll x = 1e18;
	// printf("grundy(%lld) = %d\n", x, grundy(x));
	// printf("%d\n", SZ(mgrundy));
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		int g = 0;
		REP(i, n) {
			ll x;
			scanf("%lld", &x);
			g ^= grundy(x);
		}
		if (g) {
			puts("Henry");
		} else {
			puts("Derek");
		}
	}
	
	return 0;
}
