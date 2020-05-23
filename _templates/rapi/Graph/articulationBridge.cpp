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

/** Bridge **/
/* complexity : O(|V| + |E| + |E| log |E|) */

#define MAXN 100100

int n, m, low[MAXN], num[MAXN], parent[MAXN], bridge[MAXN], counter;
vector<pii> adj[MAXN]; // adj[u].PB(MP(v, idx_of_edge));

void dfs(int u) {
	low[u] = num[u] = counter++;
	FORIT(it, adj[u]) {
		int v = it->A;
		if (num[v] == -1) {
			parent[v] = u;
			dfs(v);
			if (low[v] > num[u]) {
				// current edge is a bridge
				bridge[it->B] = 1;
			}
			MN(low[u], low[v]);
		}
		else if (v != parent[u]) {
			MN(low[u], num[v]);
		}
	}
}

int main() {
	// read the graph here. it should be 0-indexed
	// should not work if multiple edges exist
	// initialization
	counter = 0;
	REP(i, n) {
		num[i] = -1;
		low[i] = parent[i] = 0;
	}
	REP(i, m) {
		bridge[i] = 0;
	}
	// perform the dfs
	REP(i, n) {
		if (num[i] == -1) {
			dfs(i);
		}
	}
	// the bridges are stored in bridge[]

	return 0;
}
