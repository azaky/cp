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
int n, m, p[MAXN], root, c[MAXN], v[MAXN];
int par[MAXN];
vector<int> ans, adj[MAXN], child[MAXN];

void fill(int u) {
	assert(!v[u]);
	v[u] = 1;
	FORIT(it, adj[u]) {
		if (v[*it]) continue;
		par[*it] = u;
		child[u].PB(*it);
		fill(*it);
	}
}

void gogo(int u) {
	ans.PB(u);
	c[u] = 1 ^ c[u];
	// anak dulu baru bapak2
	FORIT(it, child[u]) {
		gogo(*it);
		ans.PB(u);
		c[u] = 1 ^ c[u];
	}
	if (c[u] != p[u]) {
		if (u == root) {
			ans.pop_back();
			c[u] = 1 ^ c[u];
		}
		else {
			ans.PB(par[u]);
			c[par[u]] = 1 ^ c[par[u]];
			ans.PB(u);
			c[u] = 1 ^ c[u];
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	REP(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	REP(i, n) {
		scanf("%d", &p[i]);
	}
	
	// cari komponen
	REP(i, n) {
		v[i] = 0;
	}
	root = -1;
	REP(i, n) {
		if (p[i]) {
			// build tree
			root = i;
			fill(i);
			break;
		}
	}
	if (root == -1) {
		puts("0");
		return 0;
	}
	// huhuhu :'(
	REP(i, n) {
		if (!v[i] && p[i]) {
			puts("-1");
			return 0;
		}
	}
	
	// yeay!
	REP(i, n) {
		c[i] = 0;
	}
	gogo(root);
	
	// hahahaha
	printf("%d\n", SZ(ans));
	FORIT(it, ans) {
		printf("%d ", (*it) + 1);
	}
	printf("\n");
	
	return 0;
}
