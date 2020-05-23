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

#define MAXN 222
#define TWOMAXN 5555
#define INF 1000000000

const int next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char s[MAXN][MAXN];
int m, n, d[MAXN][MAXN], cost[MAXN][MAXN], dp[TWOMAXN][MAXN];

int main() {
	while (true) {
		scanf("%d%d", &m, &n);
		if (n == 0 && m == 0) {
			break;
		}

		REP(i, n) {
			scanf("%s", s[i]);
		}

		vector<pii> pos;
		pos.PB(MP(0, 0));

		REP(i, n) REP(j, m) {
			if (s[i][j] == 'o') {
				pos[0] = MP(i, j);
			} else if (s[i][j] == '*') {
				pos.PB(MP(i, j));
			}
		}

		int k = pos.size();
		REP(ik, k) {
			queue<pii> q;
			REP(i, n) REP(j, m) {
				d[i][j] = INF;
			}
			d[pos[ik].A][pos[ik].B] = 0;
			q.push(pos[ik]);
			while (!q.empty()) {
				pii top = q.front(); q.pop();
				int r = top.A;
				int c = top.B;
				REP(dir, 4) {
					int nr = r + next[dir][0];
					int nc = c + next[dir][1];
					if (nr < 0 || nc < 0 || nr >= n || nc >= m || s[nr][nc] == 'x' || d[nr][nc] != INF) {
						continue;
					}
					d[nr][nc] = d[r][c] + 1;
					q.push(MP(nr, nc));
				}
			}
			REP(i, k) {
				cost[ik][i] = d[pos[i].A][pos[i].B];
			}
		}

		REP(mask, 1 << k) REP(i, k) {
			dp[mask][i] = INF;
		}
		REP(i, k) {
			dp[1 << i][i] = cost[0][i];
		}
		REP(mask, 1 << k) {
			REP(to, k) {
				if (!(mask & (1 << to))) {
					continue;
				}
				REP(from, k) {
					if (to == from || !(mask & (1 << to))) {
						continue;
					}
					MN(dp[mask][to], dp[mask ^ (1 << to)][from] + cost[from][to]);
				}
			}
		}

		int ans = INF;
		REP(i, k) {
			MN(ans, dp[(1 << k) - 1][i]);
		}
		if (ans == INF) {
			puts("-1");
		} else {
			printf("%d\n", ans);
		}
	}

	return 0;
}