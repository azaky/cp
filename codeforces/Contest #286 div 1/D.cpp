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

struct DSU {
	DSU() {}
	void init(int n) {
		this->n = n;
		p.resize(n);
		REP(i, n) p[i] = i;
	}
	int findSet(int v) {
		if (p[v] == v) return v;
		return p[v] = findSet(p[v]);
	}
	void merge(int u, int v) {
		p[v] = findSet(p[u]);
	}

	int n;
	vector<int> p;
};

int main() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, m) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		nodeset[c[i]].insert(a[i]);
		nodeset[c[i]].insert(b[i]);
		edges[c[i]].PB(i);
	}

	// init m DSUs
	FOR(i, 1, m) {
		FORIT(it, nodeset[i]) {
			idxnode[i][*it] = SZ(nodes[i]);
			nodes[i].PB(*it);
		}
		dsu[i].init(SZ(nodes[i]));
		FORIT(it, edges[i]) {
			dsu[i].merge(idxnode[i][a[*it]], idxnode[i][b[*it]]);
		}
	}

	// reading queries
	scanf("%d", &nq);
	FOR(i, 1, nq) {
		scanf("%d%d", &qa[i], &qb[i]);
		
	}

	return 0;
}