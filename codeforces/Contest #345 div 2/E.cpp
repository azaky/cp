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

void dfs(int x, int r, int c) {
	if (v[r][c]) {
		return;
	}
	v[r][c] = 1;
	ans[r][c] = counter;
	while (irows[r] < m && rows[irows[r]].A == x) {
		dfs(x, r, rows[irows[r]++].B);
	}
	while (icols[c] < n && cols[icols[c]] == x) {
		dfs(x, cols[icols[c]++].B, c);
	}
}

int main() {
	scanf("%d%d", &n, &m);

	a = vector<vector<int> >(n + 1, vector<int>(m + 1));
	v = vector<vector<int> >(n + 1, vector<int>(m + 1, 0));

	vector<pair<int, pii> > all;
	REP(i, n) REP(j, m) {
		scanf("%d", &a[i][j]);
		all.PB(MP(a[i][j], MP(i, j)));
		rows[i].PB(MP(a[i][j], j));
		cols[j].PB(MP(a[i][j], i));
	}
	sort(ALL(all));
	REP(i, n) {
		sort(ALL(rows[i]));
		irows[i] = 0;
	}
	REP(i, m) {
		sort(ALL(cols[i]));
		icols[i] = 0;
	}

	ans = vector<vector<int> >(n + 1, vector<int>(m + 1));
	FORIT(it, all) {
		int num = it->A;
		pii pos = it->B;
		if (v[pos.A][pos.B]) {
			continue;
		}
		dfs(pos.A, pos.B);
	}

	return 0;
}
