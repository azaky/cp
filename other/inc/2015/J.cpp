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

#define MAXN 1000
#define MAXX 1000

int ntc, n, c[MAXX + 5][MAXX + 5];
pii p[MAXN + 5];

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &p[i].A, &p[i].B);
			c[p[i].A][p[i].B] = 1;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			bool exist = false;
			for (int j = 0; j < n && !exist; ++j) {
				if (i == j) {
					continue;
				}
				int minx = min(p[i].A, p[j].A);
				int maxx = max(p[i].A, p[j].A);
				int miny = min(p[i].B, p[j].B);
				int maxy = max(p[i].B, p[j].B);
				if (maxx - minx != maxy - miny) {
					continue;
				}
				if (c[minx][miny] && c[minx][maxy] && c[maxx][miny] && c[maxx][maxy]) {
					exist = true;
				}
			}
			if (exist) ans++;
		}
		printf("Case #%d: %d\n", itc, ans);
		for (int i = 0; i < n; ++i) {
			c[p[i].A][p[i].B] = 0;
		}
	}

	return 0;
}