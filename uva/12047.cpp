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

#define MAXN 100100
#define INF 100100100
int ntc, n, m, s, t, p;
vector<pii> adj[MAXN];
int path[MAXN][2], v[MAXN][2];

bool guguk(int x) {
	FOR(i, 1, n) {
		path[i][0] = path[i][1] = INF;
		v[i][0] = v[i][1] = 0;
	}
	path[s][0] = 0;
	priority_queue<pair<int, pii> > pq;
	pq.push(MP(0, MP(s, 0)));
	while (!pq.empty()) {
		pair<int, pii> now = pq.top(); pq.pop();
		int u = now.B.A;
		int f = now.B.B;
		int d = -now.A;
		if (v[u][f]) continue;
		if (u == t && f) break;
		FORIT(it, adj[u]) {
			int w = it->first;
			int c = it->second;
			int ff = f;
			if (c >= x) ff = 1;
			if (path[w][ff] > d + c) {
				path[w][ff] = d + c;
				pq.push(MP(-path[w][ff], MP(w, ff)));
			}
		}
	}
	return (path[t][1] <= p);
}

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
		FOR(i, 1, n) {
			adj[i].clear();
		}
		REP(i, m) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			adj[x].PB(MP(y, z));
		}
		if (!guguk(0)) {
			puts("-1");
		}
		else {
			int l = 0, r = 100000;
			while (l < r) {
				int m = (l + r + 1) / 2;
				if (guguk(m)) {
					l = m;
				}
				else {
					r = m-1;
				}
			}
			printf("%d\n", l);
		}
	}
	
	return 0;
}
