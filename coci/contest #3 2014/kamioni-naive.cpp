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
#define MAXK 300100

int n, m, k[MAXK];
vector<int> a[MAXN];

int solve(int x, int y) {
	int encounter = 0;
	int ix = 1, iy = 1;
	int px = a[x][0], py = a[y][0];
	int dx = a[x][1] > a[x][0] ? 1 : -1;
	int dy = a[y][1] > a[y][0] ? 1 : -1;
	while (ix < k[x] && iy < k[y]) {
		int disx = abs(a[x][ix] - px);
		int disy = abs(a[y][iy] - py);
		int nx, ny;

		nx = px + min(disx, disy) * dx;
		ny = py + min(disx, disy) * dy;

		if (dx != dy && !(max(px, nx) < min(py, ny) || max(py, ny) < min(px, nx))) {
			encounter++;
		}

		px = nx; py = ny;
		if (px == a[x][ix]) {
			ix++;
			dx *= -1;
		}
		if (py == a[y][iy]) {
			iy++;
			dy *= -1;
		}
	}
	return encounter;
}

int main() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) {
		scanf("%d", &k[i]);
		a[i].resize(k[i]);
		REP(j, k[i]) {
			scanf("%d", &a[i][j]);
		}
	}
	REP(q, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", solve(x, y));
	}

	return 0;
}