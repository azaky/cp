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

const int next[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
const int MAXN = 111;
int ntc, r, c, sr, sc, gr, gc, a[MAXN][MAXN], grid[4][MAXN][MAXN], path[4][MAXN][MAXN];
char temp[MAXN];

bool outOfBounds(int nr, int nc) {
	return nr < 1 || r < nr || nc < 1 || c < nc;
}

struct State {
	int r, c, d;
	State (int _r, int _c, int _d) : r(_r), c(_c), d(_d) {}
};

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &r, &c);
		REP(i, r) {
			scanf("%s", temp);
			REP(j, c) {
				if (temp[j] == '#') {
					a[i+1][j+1] = -1;
				}
				else if (temp[j] == '.') {
					a[i+1][j+1] = 0;
				}
				else if (temp[j] == '<') {
					a[i+1][j+1] = 1;
				}
				else if (temp[j] == '^') {
					a[i+1][j+1] = 2;
				}
				else if (temp[j] == '>') {
					a[i+1][j+1] = 3;
				}
				else if (temp[j] == 'v') {
					a[i+1][j+1] = 4;
				}
				else if (temp[j] == 'S') {
					a[i+1][j+1] = 0;
					sr = i+1;
					sc = j+1;
				}
				else if (temp[j] == 'G') {
					a[i+1][j+1] = 0;
					gr = i+1;
					gc = j+1;
				}
			}
		}
		// calculate huba huba
		REP(d, 4) {
			FOR(i, 1, r) FOR(j, 1, c) {
				grid[d][i][j] = a[i][j];
				if (1 <= a[i][j] && a[i][j] <= 4) {
					a[i][j] += 1;
					if (a[i][j] > 4) {
						a[i][j] = 1;
					}
				}
			}
			FOR(i, 1, r) FOR(j, 1, c) {
				if (1 <= grid[d][i][j] && grid[d][i][j] <= 4) {
					int dir = grid[d][i][j] % 4;
					int pr = i + next[dir][0], pc = j + next[dir][1];
					while (!outOfBounds(pr, pc) && (grid[d][pr][pc] == 0 || grid[d][pr][pc] == 5)) {
						grid[d][pr][pc] = 5;
						pr += next[dir][0];
						pc += next[dir][1];
					}
				}
			}
			FOR(i, 1, r) FOR(j, 1, c) {
				if (grid[d][i][j] > 0) {
					grid[d][i][j] = -1;
				}
			}
			// print huba huba
			// printf("grid[%d]\n", d);
			// FOR(i, 1, r) {
			// 	FOR(j, 1, c) {
			// 		printf("%d", abs(grid[d][i][j]));
			// 	}
			// 	printf("\n");
			// }
		}
		// huba huba first search
		queue<State> q;
		q.push(State(sr, sc, 0));
		FOR(i, 1, r) FOR(j, 1, c) FOR(d, 0, 3) path[d][i][j] = -1;
		path[0][sr][sc] = 0;
		while (!q.empty()) {
			State now = q.front(); q.pop();
			// printf("now: (%d, %d, %d) = %d\n", now.r, now.c, now.d, path[now.d][now.r][now.c]);
			REP(d, 4) {
				int nr = now.r + next[d][0];
				int nc = now.c + next[d][1];
				int nd = (now.d + 1) % 4;
				int np = path[now.d][now.r][now.c] + 1;
				if (outOfBounds(nr, nc) || grid[nd][nr][nc]) continue;
				if (path[nd][nr][nc] != -1 && np >= path[nd][nr][nc]) continue;
				path[nd][nr][nc] = np;
				q.push(State(nr, nc, nd));
			}
		}
		int ans = -1;
		REP(d, 4) {
			if (path[d][gr][gc] != -1 && (ans == -1 || path[d][gr][gc] < ans)) {
				ans = path[d][gr][gc];
			}
		}
		printf("Case #%d: ", itc);
		if (ans == -1) {
			puts("impossible");
		}
		else {
			printf("%d\n", ans);
		}
	}

	return 0;
}
