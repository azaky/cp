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

#define sejuta 1000000

int p[sejuta + 5], phi[sejuta + 5];
ll ans[sejuta + 5], addum[sejuta + 5];

int main(){
	for (int i = 1; i <= sejuta; ++i) {
		p[i] = i;
	}
	for (int i = 2; i * i <= sejuta; ++i) {
		if (p[i] == i) {
			for (int j = i; i * j <= sejuta; ++j) {
				p[i * j] = i;
			}
		}
	}
	phi[1] = 1;
	for (int i = 2; i <= sejuta; ++i) {
		int pp = p[i], k = 0, x = i;
		while (x % pp == 0) {
			x /= pp;
			++k;
		}
		phi[i] = phi[x] * (pp - 1) * ((i / x) / pp);
	}

	// sum(i=1..n - 1, gcd(i, n)) = sum(d | n, d != n, d * phi(n / d))
	for (int i = 1; i <= sejuta; ++i) {
		for (int j = 2; i * j <= sejuta; ++j) {
			addum[i * j] += (ll)i * phi[j];
		}
	}
	ans[0] = 0;
	for (int i = 1; i <= sejuta; ++i) {
		ans[i] = ans[i - 1] + addum[i];
	}

	while (true) {
		int x;
		scanf("%d", &x);
		if (x) {
			printf("%lld\n", ans[x]);
		} else {
			break;
		}
	}
	
	return 0;
}
