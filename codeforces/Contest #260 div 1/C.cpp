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

#define MAXN 300300

int p[MAXN];
int findSet(int v) {
	if (p[v] == v) {
		return v;
	}
	else {
		return p[v] = findSet(p[v]);
	}
}
void merge(int u, int v) {
	int ux = findSet(u);
	int vx = findSet(v);
	if (ux < vx) {
		p[vx] = ux;
	}
	else {
		p[ux] = vx;
	}
}

int n, m, q, d[MAXN];
vector<int> adj[MAXN];

int maxdepth, tranch;
void dfs(int v, int p, int depth) {
	if (depth > maxdepth) {
		maxdepth = depth;
		tranch = v;
	}
	FORIT(it, adj[v]) {
		if (*it == p) continue;
		dfs(*it, v, depth + 1);
	}
}
int calc(int v) {
	maxdepth = 0;
	tranch = v;
	dfs(v, -1, 0);
	maxdepth = 0;
	dfs(tranch, -1, 0);
	return maxdepth;
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	FOR(i, 1, n) {
		p[i] = i;
	}
	REP(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].PB(y);
		adj[y].PB(x);
		merge(x, y);
	}
	FOR(i, 1, n) {
		int x = findSet(i);
		if (d[x] > 0) continue;
		d[x] = calc(x);
	}
	FOR(i, 1, q) {
		int task;
		scanf("%d", &task);
		if (task == 1) {
			int x;
			scanf("%d", &x);
			printf("%d\n", d[findSet(x)]);
		}
		else {
			int x, y;
			scanf("%d%d", &x, &y);
			int dx = d[findSet(x)], dy = d[findSet(y)];
			if (findSet(x) != findSet(y)) {
				merge(x, y);
				d[findSet(x)] = max(max(dx, dy), 1 + (dx + 1) / 2 + (dy + 1) / 2);
			}
		}
	}
	
	return 0;
}
