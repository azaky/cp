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
int n, q, a[MAXN], b[MAXN], l[MAXN], subtree[MAXN];
db w[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int parent) {
	subtree[v] = 1;
	FORIT(it, adj[v]) {
		int u = a[*it] + b[*it] - v;
		if (u == parent) continue;
		dfs(u, v);
		subtree[v] += subtree[u];

		db aa = subtree[u], bb = n - subtree[u], nn = n;
		w[*it] = (aa * bb * (aa + bb - 2.) * 6.) / nn / (nn - 1.) / (nn - 2.);
	}
}

int main() {
	scanf("%d", &n);
	REP(i, n-1) {
		scanf("%d%d%d", &a[i], &b[i], &l[i]);
		adj[a[i]].PB(i);
		adj[b[i]].PB(i);
	}
	dfs(1, -1);

	db ans = 0;
	REP(i, n-1) {
		ans += w[i] * l[i];
	}
	scanf("%d", &q);
	REP(i, q) {
		int r, s;
		scanf("%d%d", &r, &s);
		r--;
		ans -= w[r] * (l[r] - s);
		l[r] = s;
		printf("%.17lf\n", ans);
	}

	return 0;
}