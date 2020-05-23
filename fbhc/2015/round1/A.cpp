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
	freopen((s + ".txt").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 10000000
int next[MAXN+5], s[11][MAXN+5], ntc;

int main() {
	OPEN("homework");
	// sieve
	for (int i = 1; i <= MAXN; ++i) {
		next[i] = i;
	}
	for (int i = 2; i*i <= MAXN; ++i) {
		if (next[i] == i) {
			for (int j = i; i*j <= MAXN; ++j) {
				next[i*j] = i;
			}
		}
	}
	FOR(i, 1, MAXN) {
		int k = 0;
		int x = i;
		while (x > 1) {
			int p = next[x];
			while (x % p == 0) x /= p;
			k++;
		}
		s[k][i] = 1;
	}
	FOR(i, 1, MAXN) {
		FOR(j, 0, 10) {
			s[j][i] += s[j][i-1];
		}
	}
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		int l, r, k, ans;
		scanf("%d%d%d", &l, &r, &k);
		if (k > 10) {
			ans = 0;
		}
		else {
			ans = s[k][r] - s[k][l-1];
		}
		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}