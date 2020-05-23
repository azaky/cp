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

ll calc(ll n) {
	// base case
	if (n < 10) {
		return n;
	}

	int k = 0;
	while (ten[k] <= n) k++;
	k--;

	if (n == ten[k]) {
		return 1 + calc(ten[k] - 1);
	}

	// decide when we divide it
	ll best = n;
	REP(i, k + 1) {
		// first part: k - i digits
		// second part: i + 1 digits
		ll firstPart = n / ten[i+1];
		ll secondPart = n % ten[i+1];

		if (secondPart == 0) {
			firstPart--;
			secondPart = ten[i+1];
		}

		// from ten[k]:
		// rise until reverse(firstPart * ten[i+1] + 1)
		// flip
		// rise until n
		ll temp = 1 + reverse(firstPart) + secondPart;

		// flip is unnecessary when firstPart equals ten[k]
		if (firstPart * ten[i+1] == ten[k]) {
			temp--;
		}

		// choose the best temp
		MN(best, temp);
	}

	return best + calc(ten[k] - 1);
}

int main(int argc, char** argv) {
	if (argc > 1) {
		OPEN(argv[1]);
	}
	int ntc;
	ll n;

	// precompute ten
	ten[0] = 1;
	FOR(i, 1, 18) ten[i] = 10LL * ten[i-1];

	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", itc, calc(n));
	}

	return 0;
}