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
int n, a[MAXN], ada[MAXN], next[MAXN], pi[MAXN];

int main(){
	/* read input */
	scanf("%d",&n); n++;
	REP(i,n) scanf("%d",&a[i]);
	
	/* do some suspicious calculations */
	REP(i,n){
		for (int j = 1; j * j <= a[i]; ++j) {
			if (a[i] % j != 0) continue;
			ada[j] = ada[a[i] / j] = 1;
		}
	}
	FOR(i,2,MAXN-1) next[i] = i;
	for (int i = 2; i * i < MAXN; ++i) {
		if (next[i] != i) continue;
		for (int j = i; i * j < MAXN; ++j) {
			next[i * j] = i;
		}
	}
	pi[1] = 1;
	FOR(i,2,MAXN-1) {
		int p = next[i];
		int x = i;
		int pp = 1;
		while (x % p == 0) {
			x /= p;
			pp *= p;
		}
		pi[i] = pi[x] * pp / p * (p-1);
	}
	
	/* now the rest is easy! */
	ll ans = 0;
	FOR(i,2,MAXN-1) {
		ans += (ll)(pi[i] * ada[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}
