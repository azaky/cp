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

ll n, s;

void check(ll b) {
	if (b < 2) {
		return;
	}
	ll sum = 0;
	ll t = n;
	while (t > 0) {
		sum += t % b;
		t /= b;
	}
	if (s == sum) {
		printf("%lld\n", b);
		exit(0);
	}
}

int main(){
	scanf("%lld%lld", &n, &s);

	ll b = 2;
	while (b * b <= n + n) {
		check(b++);
	}

	ll ns = n - s;
	ll ans = n;
	vector<ll> factors;
	for (ll f = 1; f * f <= ns; ++f) {
		if (ns % f == 0) {
			factors.push_back(f);
			factors.push_back(ns / f);
		}
	}
	sort(ALL(factors));
	FORIT(it, factors) {
		check(*it + 1);
	}

	check(n);
	check(n + 1);

	puts("-1");
	
	return 0;
}
