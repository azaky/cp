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
	#define debug(...) fprintf(stderr, __VA_ARGS__)
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

#define MAXN 1100100
int n, ntc, sieve[MAXN], idxp[MAXN], v[MAXN];

int main(){
	FOR(i, 1, 1000000) {
		sieve[i] = i;
	}
	for (int i = 2; i * i <= 1000000; i++) {
		if (sieve[i] != i) continue;
		for (int j = 2; i * j <= 1000000; j++) {
			sieve[i*j] = i;
		}
	}
	int np = 0;
	FOR(i, 2, 1000000) {
		if (sieve[i] == i) {
			idxp[i] = np++;
		}
	}
	
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		REP(i, np) {
			v[i] = 0;
		}
		bool primetot = true;
		REP(i, n) {
			int a;
			scanf("%d", &a);
			while (a > 1) {
				int p = sieve[a];
				if (v[idxp[p]]) primetot = false;
				v[idxp[p]] = 1;
				while (a % p == 0) a /= p;
			}
		}
		if (primetot) {
			puts("YA");
		}
		else {
			puts("TIDAK");
		}
	}

	return 0;
}
