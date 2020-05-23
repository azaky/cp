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

#define MAXN 777
int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, visit[MAXN][MAXN][4], area, temp[MAXN][MAXN];
ll h[MAXN][MAXN], v[MAXN][MAXN];
vector<pii> cur;

pair<ll, ll> t;
void fill(int r, int c, int d) {
	if (r < 1 || c < 1 || r > n || c > n) return;
	if (visit[r][c][d]) return;
	visit[r][c][d] = 1;
	if (!temp[r][c]) {
		temp[r][c] = 1;
		cur.PB(MP(r, c));
	}
	REP(dir, 4) {
		int rr = r + next[dir][0];
		int cc = c + next[dir][1];
		ll h1 = h[r][c], h2 = h[rr][cc], v1 = v[r][c], v2 = v[rr][cc];
		if (t.second * (h1 - h2) == t.first * (v2 - v1) && !(h1 == h2 && v1 == v2)) {
			fill(rr, cc, (dir + 2) % 4);
		}
	}
}

int main(){
	scanf("%d", &n);
	FOR(i, 1, n) FOR(j, 1, n) {
		scanf("%lld", &h[i][j]);
	}
	FOR(i, 1, n) FOR(j, 1, n) {
		scanf("%lld", &v[i][j]);
	}
	// first flood fill:
	int nscc = 0;
	FOR(i, 1, n) FOR(j, 1, n) {
		
	}
	int ans = 0;
	FOR(i, 1, n) FOR(j, 1, n) {
		// check to four directions
		REP(dir, 4) {
			int ii = i + next[dir][0];
			int jj = j + next[dir][1];
			// calculate when both (i, j) and (ii, jj) will have the same height
			// solve the current equation:
			// h1 + v1 * t = h2 + v2 * t
			// (h1 - h2) = t * (v2 - v1)
			// t = (h1 - h2) / (v2 - v1)
			ll h1 = h[i][j], h2 = h[ii][jj], v1 = v[i][j], v2 = v[ii][jj];
			if (v1 == v2 || h1 == h2) continue;
			if ((h1 - h2) * (v2 - v1) < 0) continue;
			t = MP(h1 - h2, v2 - v1);
			cur.clear();
			fill(i, j, dir);
			MX(ans, SZ(cur));
			FORIT(it, cur) {
				temp[it->A][it->B] = 0;
			}
		}
	}
	RESET(visit, 0);
	// now check if tree has same height :v
	FOR(i, 1, n) FOR(j, 1, n) {
		REP(dir, 4) {
			int ii = i + next[dir][0];
			int jj = j + next[dir][1];
			ll h1 = h[i][j], h2 = h[ii][jj], v1 = v[i][j], v2 = v[ii][jj];
			if (h1 == h2) {
				t = MP(0, 1);
				cur.clear();
				fill(i, j, dir);
				MX(ans, SZ(cur));
				FORIT(it, cur) {
					temp[it->A][it->B] = 0;
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}
