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

int code[256], r, c;
char grid[MAXN][MAXN];
int w[MAXN][MAXN][16], v[MAXN][MAXN][16];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(){
	code['r'] = 1;
	code['g'] = 2;
	code['b'] = 3;
	code['y'] = 4;
	code['R'] = 5;
	code['G'] = 6;
	code['B'] = 7;
	code['Y'] = 8;
	while (scanf("%d%d", &r, &c) == 2) {
		if (r == 0 && c == 0) break;
		REP(i, r) {
			scanf("%s", grid[i]);
		}

		pii start;
		REP(i, r) REP(j, c) {
			if (grid[i][j] == '*') {
				start = MP(i, j);
			}
		}

		queue<pii> q;
		q.push(MP(c * start.A + start.B, 0));
		RESET(w, 0x7F);
		RESET(v, 0);
		w[start.A][start.B][0] = 0;
		v[start.A][start.B][0] = 1;

		int ans = -1;
		while (!q.empty()) {
			pii now = q.front(); q.pop();
			int pos = now.A, mask = now.B;
			int posr = pos / c;
			int posc = pos % c;
			int curw = w[posr][posc][mask];
			if (grid[posr][posc] == 'X') {
				ans = curw;
				break;
			}
			REP(d, 4) {
				int nr = posr + dir[d][0];
				int nc = posc + dir[d][1];
				if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
					continue;
				}
				int nmask = mask;
				char cell = grid[nr][nc];
				if (cell == '#') {
					continue;
				} else if (1 <= code[cell] && code[cell] <= 4) {
					nmask |= 1 << (code[cell] - 1);
				} else if (5 <= code[cell] && code[cell] <= 8) {
					if (!(nmask & (1 << (code[cell] - 5)))) {
						continue;
					}
				}
				if (v[nr][nc][nmask]) {
					continue;
				}
				w[nr][nc][nmask] = curw + 1;
				v[nr][nc][nmask] = 1;
				q.push(MP(c * nr + nc, nmask));
			}
		}
		if (ans == -1) {
			puts("The poor student is trapped!");
		} else {
			printf("Escape possible in %d steps.\n", ans);
		}
	}
	
	return 0;
}