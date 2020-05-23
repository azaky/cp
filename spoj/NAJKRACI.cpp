/* DELAPAN.3gp */
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

/* -------------- end of DELAPAN.3gp's template -------------- */

#define MOD 1000000007
#define INF MOD
#define MAXN 5500

int n, m, w[MAXN], ans[MAXN];
pii edges[MAXN];
vector<int> adj[MAXN], dag[MAXN];

int cost[MAXN], ways[MAXN], visited[MAXN], done[MAXN], dest[MAXN];

void dfs(int v) {
	if (visited[v]) return;
	visited[v] = 1;
	dest[v] = 1;
	FORIT(it, dag[v]) {
		// printf("\t\tin dfs(%d): %d\n", v, *it);
		int target = edges[*it].B;
		dfs(target);
		dest[v] += dest[target];
		dest[v] %= MOD;
	}
}

void huba(int v) {
	// printf("huba(%d)\n", v);
	// <-cost, edgeindex>
	priority_queue<pii> pq;
	FOR(i, 1, n) {
		cost[i] = INF;
		dag[i].clear();
		ways[i] = dest[i] = 0;
		visited[i] = done[i] = 0;
	}
	FORIT(it, adj[v]) {
		pq.push(MP(-w[*it], *it));
		MN(cost[edges[*it].B], w[*it]);
	}
	ways[v] = 1;
	cost[v] = 0;
	done[v] = 1;
	vector<int> usedEdges;
	while (!pq.empty()) {
		pii top = pq.top(); pq.pop();
		int idx = top.B;
		int from = edges[idx].A, to = edges[idx].B;
		int curw = -top.A;
		if (cost[to] == curw) {
			ways[to] += ways[from];
			ways[to] %= MOD;
			dag[from].PB(idx);
			usedEdges.PB(idx);
			if (done[to]) {
				continue;
			}
		} else {
			assert(cost[to] < curw);
			continue;
		}
		done[to] = 1;
		// printf("\t<%d, %d>\n", curw, idx);

		FORIT(it, adj[to]) {
			int x = edges[*it].B;
			int neww = curw + w[*it];
			if (neww <= cost[x]) {
				cost[x] = neww;
				pq.push(MP(-neww, *it));
			}
		}
	}

	dfs(v);
	// FOR(i, 1, n) {
	// 	printf("\tways[%d] = %d, dest[%d] = %d\n", i, ways[i], i, dest[i]);
	// }
	FORIT(it, usedEdges) {
		int addum = ((long long)ways[edges[*it].A] * dest[edges[*it].B]) % MOD;
		// printf("\tADD %d to %d\n", addum, *it);
		ans[*it] += addum;
		ans[*it] %= MOD;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	REP(i, m) {
		scanf("%d%d%d", &edges[i].A, &edges[i].B, &w[i]);
		adj[edges[i].A].PB(i);
	}

	FOR(i, 1, n) {
		huba(i);
	}

	REP(i, m) {
		printf("%d\n", ans[i]);
	}
	
	return 0;
}
