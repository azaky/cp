/*
 * Contest	: TOKI Open Contest November 2014
 * Problem	: Map Testing
 * Author	: Pusaka Kaleb Setiabudi
 * Tester	: Ahmad Zaky
 * Desc		: O(MN). Traverse the graph with DFS, and mark
 			each nodes with white, grey, black (IYKWIM). We 
 			will get stuck if we cannot get to "safe" nodes
 			from current node.
 			(ngaco sih ini kayaknya)
 */
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

#define MAXN 555
#define WHITE -1
#define GREY 0
#define BLACK 1
#define PINK 2

const int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int ntc, n, m, k, a[MAXN][MAXN], v[MAXN][MAXN], idx[MAXN][MAXN], p[MAXN*MAXN];
pii coor[MAXN*MAXN];

int findSet(int v) {
	if (p[v] == v) return v;
	else return p[v] = findSet(p[v]);
}
void unionSet(int x, int y) {
	pii cx = coor[findSet(x)], cy = coor[findSet(y)];
	if (v[cx.A][cx.B] == PINK) {
		p[findSet(y)] = findSet(x);
	}
	else {
		p[findSet(x)] = findSet(y);
	}
}

bool outOfBounds(int r, int c) {
	return r < 1 || r > n || c < 1 || c > m;
}
void dfs(int r, int c) {
	assert(!outOfBounds(r, c));
	assert(v[r][c] == WHITE);

	printf("dfs(%d, %d):\n", r, c);
	// FOR(i, 1, n) {
	// 	printf("\t");
	// 	FOR(j, 1, m) {
	// 		printf("%3d", v[i][j]);
	// 		if (j == m) puts("");
	// 	}
	// }

	// if we reached our goal, pink
	if (r == n && c == m) {
		v[r][c] = PINK;
		return;
	}

	// processed, change to grey
	v[r][c] = GREY;

	// types of neighbor
	int cot[3] = {0};
	// check all neighbors
	REP(dir, 4) {
		int rr = r + next[dir][0];
		int cc = c + next[dir][1];

		// if out of bounds
		if (outOfBounds(rr, cc)) continue;

		// if we cannot go there
		if (a[rr][cc] - a[r][c] > k) continue;

		// if this neighbor is white, do dfs
		if (v[rr][cc] == WHITE) {
			dfs(rr, cc);
		}

		pii parent = coor[findSet(idx[rr][cc])];
		cot[v[parent.A][parent.B]]++;
	}

	// stuck, or may be stuck
	if (cot[GREY] + cot[PINK] == 0 || cot[BLACK] != 0) {
		v[r][c] = BLACK;
	}
	// not sure: all grey: union them
	else if (cot[PINK] == 0) {
		REP(dir, 4) {
			int rr = r + next[dir][0];
			int cc = c + next[dir][1];

			// if out of bounds
			if (outOfBounds(rr, cc)) continue;

			// if we cannot go there
			if (a[rr][cc] - a[r][c] > k) continue;

			// union!
			unionSet(idx[r][c], idx[rr][cc]);
			// printf("at dfs(%d, %d): union (%d, %d) and (%d, %d)\n", r, c, r, c, rr, cc);
		}
	}
	// sure: some pink
	else {
		v[r][c] = PINK;
		pii p = coor[findSet(idx[r][c])];
		v[p.A][p.B] = PINK;
	}

	// printf("end dfs(%d, %d):\n", r, c);
	// FOR(i, 1, n) {
	// 	printf("\t");
	// 	FOR(j, 1, m) {
	// 		printf("%3d", v[i][j]);
	// 		if (j == m) puts("");
	// 	}
	// }
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &n, &m, &k);
		FOR(i, 1, n) FOR(j, 1, m) {
			scanf("%d", &a[i][j]);

			// initialize DSU
			idx[i][j] = i * m + j;
			coor[i * m + j] = MP(i, j);
			p[idx[i][j]] = idx[i][j];
		}

		RESET(v, WHITE);
		dfs(1, 1);
		
		// analyze result
		bool goodMap = true;
		FOR(i, 1, n) FOR(j, 1, m) {
			if (v[i][j] == WHITE) continue;
			pii c = coor[findSet(idx[i][j])];
			if (v[c.A][c.B] != PINK) {
				goodMap = false;
			}
			// printf("parent of (%d, %d) is (%d, %d)\n", i, j, c.A, c.B);
		}

		// FOR(i, 1, n) FOR(j, 1, m) {
		// 	printf("%3d", v[i][j]);
		// 	if (j == m) puts("");
		// }

		puts(goodMap ? "YES" : "NO");
	}

	return 0;
}