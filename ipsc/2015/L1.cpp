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

int ntc, p, d;

#define MAXN 200
int _com[MAXN][MAXN], memo[MAXN][MAXN];

int com(int n, int k) {
	if (k > n || k < 0) return 0;
	if (k == 0 || n == k) return 1;
	if (memo[n][k]) return _com[n][k];
	memo[n][k] = 1;
	return _com[n][k] = com(n - 1, k) + com(n - 1, k - 1);
}

bool possible(int p, int d, int l) {
	int c = 0;
	int oc = p * l;
	int now = 1;
	while (c < d) {
		int f = min(oc / now, com(l + now - 1, now));
		oc -= f * now;
		c += f;
		if (oc <= now) break;
		now++;
	}
	return c >= d;
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &p, &d);

		FOR(l, 1, d) {
			if (possible(p, d, l)) {
				printf("%d\n", l);
				break;
			}
		}
	}

	return 0;
}