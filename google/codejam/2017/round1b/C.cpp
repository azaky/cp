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

#define INF 1e15
#define EPS 1e-7

#define MAXN 111

int ntc, n, q;
int e[MAXN], d[MAXN][MAXN];
db s[MAXN];
int source, sink;
db path[MAXN][MAXN];
int prem[MAXN][MAXN];
db ans[MAXN];

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &q);
		FOR(i, 1, n) {
			scanf("%d%lf", &e[i], &s[i]);
		}
		FOR(i, 1, n) FOR(j, 1, n) {
			scanf("%d", &d[i][j]);
		}
		FOR(iq, 1, q) {
			scanf("%d%d", &source, &sink);

			FOR(i, 1, n) FOR(j, 1, n) {
				path[i][j] = INF;
				prem[i][j] = 0;
			}

			// <<time, remaining>, <city, horse>>
			priority_queue<pair<pair<db, int>, pii> > pq;
			pq.push(MP(MP(0, e[source]), MP(source, source)));

			// printf("q [%d] to [%d]\n", source, sink);
			while (!pq.empty()) {
				pair<pair<db, int>, pii> top = pq.top(); pq.pop();

				db t = -top.A.A;
				int rem = top.A.B;
				int v = top.B.A;
				int h = top.B.B;

				if (path[v][h] < t) continue;
				if (prem[v][h] > rem) continue;

				// printf("\tin city [%d] with horse [%d] remaining [%d], time = [%g]\n", v, h, rem, t);

				// change horse
				if (v != h && path[v][v] > t) {
					path[v][v] = t;
					prem[v][v] = e[v];
					pq.push(MP(MP(-t, e[v]), MP(v, v)));
				}

				FOR(u, 1, n) {
					if (d[v][u] == -1) continue;
					if (d[v][u] > rem) continue;

					db t2 = t + (db)d[v][u] / s[h];
					int rem2 = rem - d[v][u];

					if (path[u][h] > t2 || (fabs(path[u][h] - t2) < EPS && rem2 > prem[u][h])) {
						path[u][h] = t2;
						prem[u][h] = rem2;
						pq.push(MP(MP(-t2, rem2), MP(u, h)));
					}
				}
			}

			ans[iq] = INF;
			FOR(i, 1, n) {
				MN(ans[iq], path[sink][i]);
			}
		}

		printf("Case #%d:", itc);
		FOR(i, 1, q) {
			printf(" %.17lf", ans[i]);
		}
		puts("");
	}
	
	return 0;
}