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

int N, T[MAXN], P[MAXN][20], L[MAXN];

/** Lowest Common Ancestor **/
/* complexity : LCApre : O(N log N), LCAquery : O(log N) */
/* legend:
 * N : number of vertices. WARNING: zero based
 * T : direct parent. T[v] is parent of v
 * L : L[v] is the level of v. zero/one based is okay
 * P : dp table of size [MAXN][LOGMAXN]. P[v][i] is the 2^i-th parent of v
 */
void LCApre(){
	int i, j;

	//we initialize every element in P with -1
	for (i = 0; i < N; i++)
		for (j = 0; 1 << j < N; j++)
			P[i][j] = -1;

	//the first ancestor of every node i is T[i]
	for (i = 0; i < N; i++)
		P[i][0] = T[i];
	
	//bottom up dynamic programing
	for (j = 1; 1 << j < N; j++)
		for (i = 0; i < N; i++) 
			if (P[i][j - 1] != -1)
				P[i][j] = P[P[i][j - 1]][j - 1];
}
int LCAquery(int p, int q){
	int log, i;
	
	//if p is situated on a higher level than q then we swap them
	if (L[p] < L[q]) swap(p,q);
	
	//we compute the value of [log(L[p)]
	for (log = 1; 1 << log <= L[p]; log++);
	log--;
	
	//we find the ancestor of node p situated on the same level
	//with q using the values in P
	for (i = log; i >= 0; i--)
		if (L[p] - (1 << i) >= L[q])
			p = P[p][i];
	
	if (p == q) return p;
	
	//we compute LCA(p, q) using the values in P
	for (i = log; i >= 0; i--)
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];
	
	return T[p];
}

int n, k, c[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int level, int parent) {
	L[v] = level;
	T[v] = parent;
	FORIT(it, adj[v]) {
		if (*it != parent) {
			dfs(*it, level + 1, v);
		}
	}
}

void dfs2(int v) {
	FORIT(it, adj[v]) {
		if (*it != T[v]) {
			dfs2(*it);
			c[v] += c[*it];
		}
	}
}

int main() {
	OPEN("maxflow");

	scanf("%d%d", &n, &k);
	N = n;
	REP(i, n-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	dfs(0, 0, -1);
	LCApre();
	REP(i, k) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		c[x]++;
		c[y]++;
		int lca = LCAquery(x, y);
		c[lca]--;
		if (T[lca] >= 0) {
			c[T[lca]]--;
		}
	}
	dfs2(0);
	int ans = 0;
	REP(i, n) {
		MX(ans, c[i]);
	}
	printf("%d\n", ans);

	return 0;
}