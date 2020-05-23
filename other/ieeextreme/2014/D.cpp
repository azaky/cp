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

bool leftTurn(pii a, pii b, pii c) {
	return (b.A - a.A) * (c.B - b.B) - (b.B - a.B) * (c.A - b.A) >= 0;
}

#define MAXN 20200
#define MAXL 111
int n, q, nlapis[MAXL];
pii lapis[MAXL][MAXN];

int main(){
	scanf("%d", &n);
	REP(i, n+1) {
		scanf("%d", &nlapis[i]);
		REP(j, nlapis[i]) {
			scanf("%d%d", &lapis[i][j].A, &lapis[i][j].B);
		}
	}
	scanf("%d", &q);
	REP(iq, q) {
		pii x;
		scanf("%d%d", &x.A, &x.B);
		int l = 1, r = n;
		while (l < r) {
			int m = (l + r) >> 1;
			// check apakah x di atas / di bawah garis ke-m
			int lm = 1, rm = nlapis[m]-1;
			while (lm < rm) {
				int mm = (lm + rm) >> 1;
				if (x.A < lapis[m][mm-1].A) {
					rm = mm - 1;
				}
				else if (x.A > lapis[m][mm].A) {
					lm = mm + 1;
				}
				else {
					lm = rm = mm;
				}
			}
			assert(lm == rm);
			if (leftTurn(lapis[m][lm-1], x, lapis[m][lm])) {
				r = m;
			}
			else {
				l = m+1;
			}
		}
		assert(l == r);
		printf("%d\n", l);
	}
	
	return 0;
}
