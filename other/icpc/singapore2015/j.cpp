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

int n, q, c[MAXN], p[MAXN];
vector<int> adj[MAXN];
pii range[MAXN];
ll bit[2][MAXN];

void _update(int i, int v, int k) {
	ll addum = 1LL << (ll)k;
	for (int x = v; x <= n; x += (x & -x)) {
		bit[i][x] ^= addum;
	}
}

void update(int x, int k) {
	if (k <= 50) {
		_update(0, x, k);
	} else if (k <= 100) {
		_update(1, x, k - 50);
	} else {
		exit(1);
	}
}

ll _query(int i, int v) {
	ll ret = 0;
	for (int x = v; x > 0; x -= (x & -x)) {
		ret ^= bit[i][x];
	}
	// printf("query(%d, %d) = %llx\n", i, v, ret);
	return ret;
}
	
int query(int x, int y) {
	int ret = 0;
	REP(i, 2) {
		ret += __builtin_popcountll(_query(i, x - 1) ^ _query(i, y));
	}
	return ret;
}

void preorder(int v) {
	static int counter = 0;
	range[v].A = ++counter;
	FORIT(it, adj[v]) {
		preorder(*it);
	}
	range[v].B = counter;
}

int main() {
	scanf("%d%d", &n, &q);
	FOR(i, 1, n) {
		scanf("%d", &c[i]);
	}
	FOR(i, 2, n) {
		scanf("%d", &p[i]);
		adj[p[i]].PB(i);
	}

	preorder(1);
	FOR(i, 1, n) {
		update(range[i].A, c[i]);
	}

	REP(iq, q) {
		int k, x;
		scanf("%d%d", &k, &x);
		if (k == 0) {
			printf("%d\n", query(range[x].A, range[x].B));
		} else {
			update(range[x].A, c[x]);
			update(range[x].A, k);
			c[x] = k;
		}
	}

	return 0;
}