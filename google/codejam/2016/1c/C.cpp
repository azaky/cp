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

struct outfit {
	int a, b, c;
	outfit(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

int a, b, c, k;
int cota[22][22], cotb[22][22], cot[22][22][22];

int main() {
	OPEN("C-large");
	int ntc;
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d%d", &a, &b, &c, &k);
		vector<outfit> ans;
		MN(k, c);
		int nans = a * b * k;
		int start = 0;
		REP(ia, a) {
			int ic = start;
			REP(ib, b) REP(i, k) {
				ans.PB(outfit(ia, ib, ic));
				ic = (ic + 1) % c;
			}
			start = (start + 1) % c;
		}
		RESET(cota, 0);
		RESET(cotb, 0);
		RESET(cot, 0);
		REP(i, nans) {
			cota[ans[i].a][ans[i].c]++;
			cotb[ans[i].b][ans[i].c]++;
			cot[ans[i].a][ans[i].b][ans[i].c]++;
		}
		bool valid = true;
		REP(ia, a) REP(ib, b) REP(ic, c) {
			if (cota[ia][ic] > k) {
				valid = false;
			}
			if (cotb[ib][ic] > k) {
				valid = false;
			}
			if (cot[ia][ib][ic] > 1) {
				valid = false;
			}
		}
		if (!valid) {
			fprintf(stderr, "CASE #%d INVALID\n", itc);
		}
		printf("Case #%d: %d\n", itc, nans);
		REP(i, nans) {
			printf("%d %d %d\n", ans[i].a + 1, ans[i].b + 1, ans[i].c + 1);
		}
	}

	return 0;
}