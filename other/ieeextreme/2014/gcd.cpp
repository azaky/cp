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

#define MAXV 10000
#define MAXN 100100
#define MOD 1000000007LL

ll power(ll a, ll b) {
	if (b == 0) return 1;
	ll temp = power(a, b/2LL);
	temp *= temp;
	temp %= MOD;
	if (b%2LL) {
		temp *= a;
		temp %= MOD;
	}
	return temp;
}

int n, a[MAXN], q;
ll s[MAXV+5];

int main(){
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &a[i]);
		for (int x = 1; x*x <= a[i]; x++) {
			if (a[i] % x) continue;
			s[x]++;
			if (x*x != a[i]) {
				s[a[i]/x]++;
			}
		}
	}
	FORD(i, MAXV, 1) {
		s[i] = power(2, s[i]) - 1;
		for (int x = i+i; x <= MAXV; x += i) {
			s[i] += MOD - s[x];
			s[i] %= MOD;
		}
	}
	scanf("%d", &q);
	REP(iq, q) {
		int x;
		scanf("%d", &x);
		printf("%d\n", (int)s[x]);
	}
	
	return 0;
}
