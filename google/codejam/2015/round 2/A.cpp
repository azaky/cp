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

#define MAXN 110
const int next[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int ntc, r, c, v[MAXN][MAXN], grid[MAXN][MAXN];
char temp[MAXN];
pii huba[MAXN][MAXN][4];

bool outOfBounds(int rr, int cc) {
	return rr < 0 || cc < 0 || rr >= r || cc >= c;
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &r, &c);
		REP(i, r) {
			scanf("%s", temp);
			REP(j, c) {
				switch (temp[j]) {
					case '.': grid[i][j] = -1;
					break;
					case '^': grid[i][j] = 0;
					break;
					case '<': grid[i][j] = 1;
					break;
					case 'v': grid[i][j] = 2;
					break;
					case '>': grid[i][j] = 3;
					break;
				}
			}
		}

		bool impossible = false;
		REP(i, r) REP(j, c) {
			if (grid[i][j] == -1) {
				REP(dir, 4) {
					huba[i][j][dir] = MP(-1, -1);
				}
			} else {
				int chuba = 0;
				REP(dir, 4) {
					int rx = i + next[dir][0], cx = j + next[dir][1];
					while (!outOfBounds(rx, cx) && grid[rx][cx] == -1) {
						rx += next[dir][0];
						cx += next[dir][1];
					}
					if (outOfBounds(rx, cx)) {
						huba[i][j][dir] = MP(-1, -1);
						chuba++;
					} else {
						huba[i][j][dir] = MP(rx, cx);
					}
				}
				if (chuba == 4) impossible = true;
			}
		}

		if (impossible) {
			printf("Case #%d: IMPOSSIBLE\n", itc);
			continue;
		}

		// flood fill?
		int ans = 0;
		REP(i, r) REP(j, c) v[i][j] = 0;
		REP(i, r) REP(j, c) {
			if (v[i][j] || grid[i][j] == -1) continue;

			int rx = i, cx = j;
			do {
				v[rx][cx] = 1;
				pii nexthuba = huba[rx][cx][grid[rx][cx]];
				rx = nexthuba.A;
				cx = nexthuba.B;
			} while (!outOfBounds(rx, cx) && !v[rx][cx]);
			if (outOfBounds(rx, cx)) {
				ans++;
			}
		}
		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}