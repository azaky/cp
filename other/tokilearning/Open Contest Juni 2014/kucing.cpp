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

#define MAXN 27

int vis[MAXN][MAXN][MAXN], a[MAXN][MAXN][MAXN];
int n, r, c, kk;
int _lo, _hi;
void fill(int i, int j, int k) {
	if (i < 1 || i > n || j < 1 || j > r || k < 1 || k > c) {
		return;
	}
	if (vis[i][j][k]) {
		return;
	}
	if (a[i][j][k] < _lo || a[i][j][k] > _hi) {
		return;
	}
	vis[i][j][k] = 1;
	fill(i+1, j, k);
	fill(i-1, j, k);
	fill(i, j+1, k);
	fill(i, j-1, k);
	fill(i, j, k+1);
	fill(i, j, k-1);
}

bool kucing(int lo, int hi) {
	FOR(i, 1, n) FOR(j, 1, r) FOR(k, 1, c) vis[i][j][k] = 0;
	//RESET(vis, 0);
	_lo = lo; _hi = hi;
	fill(1, 1, 1);
	return vis[n][r][c] == 1;
}

int main(){
	scanf("%d%d%d%d", &n, &r, &c, &kk);
	int mn = 555, mx = 0;
	FOR(i, 1, n) {
		FOR(j, 1, r) {
			FOR(k, 1, c) {
				scanf("%d", &a[i][j][k]);
				MN(mn, a[i][j][k]);
				MX(mx, a[i][j][k]);
			}
		}
	}
	
	int ans = 555;
	int lo = min(a[1][1][1], a[n][r][c]);
	int hi = max(a[1][1][1], a[n][r][c]);
	int l = hi - lo, r = mx - mn;
	while (l < r) {
		int m = (l + r) / 2;
		int can = 0;
		for (int i = max(0, hi - m); i <= min(500 - m, lo); i++) {
			if (kucing(i, i + m)) {
				can = 1;
				break;
			}
		}
		if (can) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	assert(l == r);
	ans = l;
/*
	FOR(lo, 0, min(a[1][1][1], a[n][r][c])) {
		if (!kucing(lo, 500)) {
			break;
		}
		int l = max(a[1][1][1], a[n][r][c]), r = 500;
		while (l < r) {
			int m = (l + r) / 2;
			if (kucing(lo, m)) {
				r = m;
			}
			else {
				l = m + 1;
			}
		}
		assert(l == r);
		MN(ans, l - lo);
	}
*/
	
	if (abs(ans - (mx - mn)) >= kk) {
		printf("%d\n", abs(ans - (mx - mn)));
	}
	else {
		puts("Lala harus delivery");
	}
		
	return 0;
}
