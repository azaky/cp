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

#define MAXN 100100

int n, e;
vector<pii> adj[MAXN];

int vis[MAXN], mark[MAXN][11];
ll ans[MAXN];

void huba(int root) {
	set<int> vs;

	queue<pii> q;
	q.push(MP(root, 0));
	mark[root][0] = 1;
	while (!q.empty()) {
		pii top = q.front(); q.pop();

		int v = top.A, d = top.B;
		if (!vis[v]) vs.insert(v);
		vis[v] = 1;
		FORIT(it, adj[v]) {
			int dd = (top.B + it->B) % 10;
			if (!mark[it->A][dd]) {
				// printf("mark[%d][%d] from [%d][%d]\n", it->A, dd, v, d);
				mark[it->A][dd] = 1;
				q.push(MP(it->A, dd));
			}
		}
	}

	int c[10];
	REP(i, 10) c[i] = 0;
	FORIT(it, vs) {
		REP(i, 10) if (mark[*it][i]) {
			// printf("mark[%d][%d]\n", *it, i);
			c[i]++;
		}
	}

	int s = SZ(vs);
	// REP(i, 10) {
	// 	printf("c[%d] = %d\n", i, c[i]);
	// }
	if (mark[root][1]) {
		REP(i, 10) ans[i] += (ll)s * (s - 1);
	} else if (mark[root][2]) {
		// puts("Were at 2");
		REP(i, 10) assert(c[i] == c[i % 2]);
		FORIT(it, vs) {
			REP(i, 2) {
				if (mark[*it][i]) {
					REP(d, 10) {
						int ot = (d + i) % 2;
						ans[d] += c[ot];
					}
				}
			}
		}
		REP(i, 5) ans[i * 2] -= s;
	} else if (mark[root][5]) {
		// puts("Were at 5");
		REP(i, 10) assert(c[i] == c[i % 5]);
		FORIT(it, vs) {
			REP(i, 5) {
				if (mark[*it][i]) {
					REP(d, 10) {
						int ot = (d + i) % 5;
						ans[d] += c[ot];
						// printf("ans[%d] added %d by %d %d->%d\n", d, c[ot], *it, i, ot);
					}
				}
			}
		}
		REP(i, 2) ans[i * 5] -= s;
	} else {
		// puts("Were at 10");
		FORIT(it, vs) {
			REP(i, 10) {
				if (mark[*it][i]) {
					REP(d, 10) {
						int ot = (d + i) % 10;
						ans[d] += c[ot];
					}
				}
			}
		}
		ans[0] -= s;
	}
}

int main(){
	scanf("%d%d", &n, &e);
	FOR(i, 1, e) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		adj[x].PB(MP(y, z % 10));
		adj[y].PB(MP(x, (1000 - z) % 10));
	}

	FOR(i, 1, n) {
		if (!vis[i]) {
			huba(i);
		}
	}
	REP(i, 10) {
		printf("%lld\n", ans[i]);
	}
	
	return 0;
}
