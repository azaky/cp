/* DELAPAN.3gp */
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
using namespace std;

#ifdef DEBUG
	// #define debug(...) //printf(__VA_ARGS__)
	// #define GetTime() f//printf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
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

#define MAXN 111

const int next[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int dmirror[4] = {2, 3, 0, 1};
const int dleft[4] = {1, 0, 3, 2};
const int dright[4] = {3, 2, 1, 0};

int ntc, r, c, a[MAXN * 4], match[MAXN * 4];
char grid[MAXN][MAXN];
int visited[MAXN][MAXN][4], best[MAXN][MAXN][4];
pair<pii, int> prev[MAXN][MAXN][4];
deque<pair<pii, int> > d;

pair<pii, int> find(int x) {
	if (1 <= x && x <= c) {
		return MP(MP(0, x - 1), 0);
	} else if (c < x && x <= r + c) {
		return MP(MP(x - c - 1, c - 1), 3);
	} else if (r + c < x && x <= r + c + c) {
		return MP(MP(r - 1, c - (x - r - c)), 2);
	} else if (r + c + c < x && x <= 2 * (r + c)) {
		return MP(MP(2 * (r + c) - x, 0), 1);
	} else {
		assert(false);
	}
}

void push(int rx, int cx, int dx, int dist, pair<pii, int> prevv, int front = 0) {
	if (rx < 0 || rx >= r || cx < 0 || cx >= c) {
		return;
	}
	if (visited[rx][cx][dx]) {
		return;
	}
	visited[rx][cx][dx] = 1;
	best[rx][cx][dx] = dist;
	prev[rx][cx][dx] = prevv;
	if (front) {
		printf("pushing front ((%d, %d), %d)\n", rx, cx, dx);
		d.push_front(MP(MP(rx, cx), dx));
	} else {
		printf("pushing back ((%d, %d), %d)\n", rx, cx, dx);
		d.push_back(MP(MP(rx, cx), dx));
	}
}

bool connect(int x, int y) {
	printf("Connecting %d and %d\n", x, y);
	pair<pii, int> px = find(x);
	pair<pii, int> py = find(y);
	printf("(%d, %d), %d\n", px.A.A, px.A.B, px.B);
	printf("(%d, %d), %d\n", py.A.A, py.A.B, py.B);

	d.clear();
	RESET(visited, 0);
	RESET(best, 63);

	push(px.A.A, px.A.B, px.B, 0, px);
	bool found = false;
	while (!d.empty()) {
		pair<pii, int> pnow = d.front(); d.pop_front();
		if (pnow == py) {
			found = true;
			break;
		}
		int rnow = pnow.A.A, cnow = pnow.A.B, dnow = pnow.B;
		int distnow = best[rnow][cnow][dnow];
		// coinciding edges
		push(rnow + next[dnow][0], cnow + next[dnow][1], dmirror[dnow], distnow, pnow, 1);

		if (grid[rnow][cnow] == '.') {
			push(rnow, cnow, dleft[dnow], distnow + 1, pnow);
			push(rnow, cnow, dright[dnow], distnow + 1, pnow);
		} else if (grid[rnow][cnow] == '/') {
			push(rnow, cnow, dleft[dnow], distnow + 1, pnow);
		} else if (grid[rnow][cnow] == '\\') {
			push(rnow, cnow, dright[dnow], distnow + 1, pnow);
		} else {
			assert(false);
		}
	}
	if (!found) {
		printf("not found!\n");
		return false;
	} else {
		printf("found!\n");
		// traceback!
		int rnow = py.A.A, cnow = py.A.B, dnow = py.B;
		int dist = best[rnow][cnow][dnow];
		bool prevmirror = false;
		while (!(rnow == px.A.A && cnow == px.A.B && dnow == px.B)) {
			pair<pii, int> pprev = prev[rnow][cnow][dnow];
			int rprev = pprev.A.A, cprev = pprev.A.B, dprev = pprev.B;
			if (rnow == rprev && cnow == cprev) {
				if (dprev == dleft[dnow]) {
					grid[rnow][cnow] = '/';
				} else {
					grid[rnow][cnow] = '\\';
				}
			}
			rnow = rprev;
			cnow = cprev;
			dnow = dprev;
		}
		REP(i, r) {
			REP(j, c) {
				putchar(grid[i][j]);
			}
			putchar('\n');
		}
		return true;
	}
}

int main(){
	// OPEN("C-small-attempt0");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &r, &c);
		int n = 2 * (r + c);
		REP(i, n) {
			scanf("%d", &a[i]);
		}
		REP(i, n / 2) {
			match[a[i * 2]] = a[i * 2 + 1];
			match[a[i * 2 + 1]] = a[i * 2];
		}
		bool valid = true;
		RESET(grid, '.');
		vector<int> s;
		FOR(i, 1, n) {
			if (!s.empty() && s.back() == match[i]) {
				s.pop_back();
				if (!connect(i, match[i])) {
					valid = false;
					break;
				}
			} else {
				s.push_back(i);
			}
		}
		// valid = false;
		// REP(mask, (1 << (r * c))) {
		// 	bool correct = true;
		// 	REP(i, r * c) {
		// 		int ir = i / c;
		// 		int ic = i % c;
		// 		if (mask & (1 << i)) {
		// 			grid[ir][ic] = '/';
		// 		} else {
		// 			grid[ir][ic] = '\\';
		// 		}
		// 	}
		// 	// REP(i, r) {
		// 	// 	REP(j, c) {
		// 	// 		putchar(grid[i][j]);
		// 	// 	}
		// 	// 	putchar('\n');
		// 	// }
		// 	FOR(i, 1, n) {
		// 		if (!connect(i, match[i])) {
		// 			correct = false;
		// 			break;
		// 		}
		// 	}
		// 	if (correct) {
		// 		valid = true;
		// 		break;
		// 	}
		// }
		// printf("Case #%d:\n", itc);
		if (valid && s.empty()) {
			REP(i, r) REP(j, c) {
				if (grid[i][j] == '.') {
					grid[i][j] = '/';
				}
			}
			REP(i, r) {
				REP(j, c) {
					putchar(grid[i][j]);
				}
				putchar('\n');
			}
		} else {
			puts("IMPOSSIBLE");
		}
	}
	
	return 0;
}
