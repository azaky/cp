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

#define MAXH 1100
#define MAXN 10100
int n, cl, cr, hmax, l[MAXN], r[MAXN], _h[MAXN], h[MAXH];
vector<int> add[MAXH], rem[MAXH];
char ans[MAXH][MAXH], r_ans[MAXH][MAXH];

int main() {
	scanf("%d", &n);
	cl = 1000, cr = 0, hmax = 0;
	REP(i, n) {
		scanf("%d%d%d", &l[i], &r[i], &_h[i]);
		MN(cl, l[i]);
		MX(cr, r[i]);
		MX(hmax, _h[i]);
		rem[r[i]].PB(_h[i]);
		add[l[i]].PB(_h[i]);
	}
	multiset<int> hs;
	FOR(i, cl, cr) {
		FORIT(it, add[i]) {
			hs.insert(-*it);
		}
		FORIT(it, rem[i]) {
			hs.erase(hs.find(-*it));
		}
		if (hs.empty()) {
			h[i] = 0;
		}
		else {
			h[i] = -*(hs.begin());
		}
	}
	// drawing time!
	int anscount = 0;
	RESET(ans, '.');
	FOR(i, 0, hmax) FOR(j, cl, cr-1) {
		if (i == 0) ans[i][j] = '*';
		r_ans[i][j] = 0;
	}
	FOR(i, cl, cr-1) {
		FOR(j, 1, h[i]) ans[j][i] = '#';
	}
	FOR(i, 1, hmax) FOR(j, cl, cr-1) {
		if (ans[i][j] == '#' && ans[i][j-1] == '#' && ans[i][j+1] == '#' && ans[i+1][j-1] == '#' && ans[i+1][j] == '#' && ans[i+1][j+1] == '#') {
			r_ans[i][j] = 1;
		}
		if (ans[i][j] == '#') {
			if (ans[i][j-1] != '#') anscount++;
			if (ans[i][j+1] != '#') anscount++;
			if (ans[i+1][j] != '#') anscount++;
		}
	}
	FOR(i, 1, hmax) FOR(j, cl, cr-1) {
		if (r_ans[i][j]) {
			ans[i][j] = '.';
		}
	}
	printf("%d\n", anscount);
	FORD(i, hmax, 0) {
		FOR(j, cl, cr-1) {
			putchar(ans[i][j]);
		}
		puts("");
	}

	return 0;
}