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

int n, x[MAXN], ans[MAXN];
char s[MAXN];

bool coba(int a, int b, int c) {
	bool possible = true;
	REP(i, n) {
		x[i] = s[i] - '0';
	}
	while (a <= b && possible) {
		int na = x[a];
		int nb = x[b];
		if (c) {
			na += 10 * c;
		}
		if (a == b) {
			if (0 <= na && na < 20 && na % 2 == 0) {
				ans[a] = na / 2;
			} else {
				possible = false;
			}
		} else if (a == b - 1) {
			int t = 10 * na + nb;
			if (t % 11 == 0 && 0 <= t && t <= 198) {
				t /= 11;
				ans[a] = t - t / 2;
				ans[b] = t / 2;
			} else {
				possible = false;
			}
		} else {
			c = (x[a] - x[b] + 10) % 10;
			if (c < 0 || c > 1) {
				possible = false;
			}
			na -= c;
			x[b - 1] -= (na - x[b]) / 10;
			if (0 <= na && na < 19) {
				ans[a] = na - na / 2;
				ans[b] = na / 2;
			} else {
				possible = false;
			}
		}
		a++; b--;
	}
	return possible;
}

int main() {
	scanf("%s", s);
	n = strlen(s);

	int a = 0, b = n - 1, c = 0, k = n;
	if (coba(0, n - 1, 0) && ans[0]) {
		REP(i, n) {
			assert(0 <= ans[i] && ans[i] < 10);
			printf("%d", ans[i]);
		}
		printf("\n");
	} else if (s[0] == '1' && n > 1 && coba(1, n - 1, 1) && ans[1]) {
		FOR(i, 1, n - 1) {
			assert(0 <= ans[i] && ans[i] < 10);
			printf("%d", ans[i]);
		}
		printf("\n");
	} else {
		puts("0");
	}

	return 0;
}