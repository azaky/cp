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
	#define GetTime() //fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
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

int ntc, n, d, as, cs, rs, am, cm, rm, now;
int s[MAXN], m[MAXN], istree[MAXN];
vector<int> child[MAXN];
vector<int> t[MAXN];

void dfs(int v) {
	if (s[0] - d <= s[v] && s[v] <= s[0]) {
		istree[v] = 1;
		if (istree[m[v]]) {
			FORIT(it, child[v]) {
				dfs(*it);
			}
		}
	}
}

void fire(int v) {
	if (istree[v] != 1) {
		istree[v] = 0;
		return;
	}

	// printf("Fire %d\n", v);

	now--;
	FORIT(it, child[v]) {
		fire(*it);
	}

	istree[v] = 0;
}

void hire(int v) {
	if (istree[v] != -1) return;
	if (istree[m[v]] != 1 && v) return;

	istree[v] = 1;

	// printf("Hire %d\n", v);
	now++;
	FORIT(it, child[v]) {
		hire(*it);
	}
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		//fprintf(stderr, "TC %d\n", itc);
		scanf("%d%d", &n, &d);
		scanf("%d%d%d%d", &s[0], &as, &cs, &rs);
		scanf("%d%d%d%d", &m[0], &am, &cm, &rm);

		REP(i, n - 1) {
			s[i + 1] = (s[i] * as + cs) % rs;
			m[i + 1] = (m[i] * am + cm) % rm;
		}
		REP(i, n - 1) {
			m[i + 1] = m[i + 1] % (i + 1);
		}
		m[0] = 0;

		FOR(i, 0, 1000000) {
			t[i].clear();
		}
		REP(i, n) {
			child[i].clear();
		}
		REP(i, n) {
			if (i) child[m[i]].PB(i);
			t[s[i]].PB(i);
			istree[i] = 0;
		}

		//fprintf(stderr, "Done this\n");

		// insert all in range [S[0] - D, S[0]]
		now = 0;
		FOR(ss, max(s[0] - d, 0), s[0]) {
			FORIT(it, t[ss]) {
				istree[*it] = -1;
				hire(*it);
			}
		}
		int ans = now;

		//fprintf(stderr, "Done hiring\n");

		int maxs = min(s[0] + d, 1000000);

		FOR(ss, s[0] + 1, maxs) {
			// printf("SS = %d\n", ss);
			// fire all with salary == ss - d - 1
			if (ss - d - 1 >= 0) {
				FORIT(it, t[ss - d - 1]) {
					fire(*it);
				}
			}
			// hire all with salary == ss
			FORIT(it, t[ss]) {
				istree[*it] = -1;
				hire(*it);
			}
			MX(ans, now);

			if (ss % 10000 == 0) {
				//fprintf(stderr, "Done SS = %d\n", ss);
			}
		}

		printf("Case #%d: %d\n", itc, ans);

	}

	return 0;
}