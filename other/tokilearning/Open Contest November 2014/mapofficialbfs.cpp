/*
 * Contest	: TOKI Open Contest November 2014
 * Problem	: Map Testing
 * Author	: Pusaka Kaleb Setiabudi
 * Tester	: Ahmad Zaky
 * Desc		: O(MN). BFS from (1,1) and (m,n)
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

int ntc, n, m, k, a[MAXN][MAXN], v1[MAXN][MAXN], v2[MAXN][MAXN];
queue<pii> q1, q2;

bool outOfBounds(int r, int c) {
	return r < 1 || r > n || c < 1 || c > m;
}
void bfs1(int r, int c) {
	q1.push(MP(r, c));
	v1[r][c] = GREY;
	while (!q1.empty()) {
		pii p = q1.front(); q1.pop();
		r = p.A, c = p.B;
		v1[r][c] = BLACK;
		REP(dir, 4) {
			int rr = r + next[dir][0];
			int cc = c + next[dir][1];

			// if out of bounds
			if (outOfBounds(rr, cc)) continue;

			// if we cannot go there
			if (a[rr][cc] - a[r][c] > k) continue;

			// if this neighbor is white, do dfs
			if (v1[rr][cc] == WHITE) {
				q1.push(MP(rr, cc));
				v1[rr][cc] = GREY;
			}
		}
	}
}
void bfs2(int r, int c) {
	q2.push(MP(r, c));
	v2[r][c] = GREY;
	while (!q2.empty()) {
		pii p = q2.front(); q2.pop();
		r = p.A, c = p.B;
		v2[r][c] = BLACK;
		REP(dir, 4) {
			int rr = r + next[dir][0];
			int cc = c + next[dir][1];

			// if out of bounds
			if (outOfBounds(rr, cc)) continue;

			// if we cannot go there
			if (a[r][c] - a[rr][cc] > k) continue;

			// if this neighbor is white, do dfs
			if (v2[rr][cc] == WHITE) {
				q2.push(MP(rr, cc));
				v2[rr][cc] = GREY;
			}
		}
	}
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &n, &m, &k);
		FOR(i, 1, n) FOR(j, 1, m) {
			scanf("%d", &a[i][j]);
		}

		RESET(v1, WHITE);
		while (!q1.empty()) q1.pop();
		bfs1(1, 1);

		RESET(v2, WHITE);
		while (!q2.empty()) q2.pop();
		bfs2(n, m);
		
		// analyze result
		bool goodMap = true;
		FOR(i, 1, n) FOR(j, 1, m) {
			if (v1[i][j] != v2[i][j]) {
				goodMap = false;
			}
		}

		puts(goodMap ? "YES" : "NO");
	}

	return 0;
}