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

/** Lowest Common Ancestor **/
/* complexity : LCApre : O(N log N), LCAquery : O(log N) */
/* legend:
 * N : number of vertices. WARNING: zero based
 * T : direct parent. T[v] is parent of v
 * L : L[v] is the level of v. zero/one based is okay
 * P : dp table of size [MAXN][LOGMAXN]. P[v][i] is the 2^i-th parent of v
 */

#define MAXN 100100
#define LOGMAXN 18

int L[MAXN], P[MAXN][LOGMAXN], T[MAXN], N;

void pre(){
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
int query(int p, int q){
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

//////////////////////////// END OF LCA /////////////////////////////

vector<pii> adj[MAXN];
int n, d[MAXN], idx[MAXN], t, k;

struct data {
	ll nNodes;
	ll totalDist;
	ll totalAns;

	data(ll nNodes, ll totalDist, ll totalAns) {
		this->nNodes = nNodes;
		this->totalDist = totalDist;
		this->totalAns = totalAns;
	}

	data(int v) {
		this->nNodes = 1;
		this->totalDist = d[v];
		this->totalAns = 0;
	}
};

data combine(data d1, data d2, int lca) {
	ll distLca = d[lca];
	ll addLeft = (d1.totalDist - d1.nNodes * distLca) * d2.nNodes;
	ll addRight = (d2.totalDist - d2.nNodes * distLca) * d1.nNodes;
	return data(
		d1.nNodes + d2.nNodes,
		d1.totalDist + d2.totalDist,
		d1.totalAns + d2.totalAns + addLeft + addRight);
}

int counter;

void dfs(int v, int parent, int level, int distance) {
	idx[v] = counter++;
	d[v] = distance;
	L[v] = level;
	T[v] = parent;

	FORIT(it, adj[v]) {
		int child = it->first;
		if (child != parent) {
			dfs(child, v, level + 1, distance + it->second);
		}
	}
}

bool compare(int x, int y) {
	return idx[x] < idx[y];
}

int main() {
	scanf("%d%d", &n, &t);
	REP(i, n - 1) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--; b--;
		adj[a].PB(MP(b, c));
		adj[b].PB(MP(a, c));
	}

	counter = 0;
	dfs(0, -1, 0, 0);

	N = n;
	pre();

	REP(itc, t) {
		scanf("%d", &k);
		vector<int> x;
		REP(i, k) {
			int xx;
			scanf("%d", &xx);
			x.PB(--xx);
		}

		if (k <= 1) {
			puts("0");
			continue;
		}

		sort(ALL(x), compare);

		// printf("initial condition:\n");
		// for (int i = 0; i < k; ++i) {
		// 	printf("%d ", x[i]);
		// }
		// printf("\n");

		vector<pair<int, data> > s;
		s.PB(MP(x[0], data(x[0])));
		s.PB(MP(x[1], data(x[1])));
		int next = 2;
		while (SZ(s) > 1) {

			// printf("in queue:\n");
			// for (int i = 0; i < SZ(s); ++i) {
			// 	printf("%d: nNodes = %lld, totalDist = %lld, totalAns = %lld\n", s[i].A, s[i].B.nNodes, s[i].B.totalDist, s[i].B.totalAns);
			// }
			// printf("\n");

			int curSize = SZ(s);
			int u = s[curSize - 1].A;
			int v = s[curSize - 2].A;
			int lcaUV = query(u, v);

			if (next < k) {
				// peek next
				int w = x[next];
				int lcaVW = query(v, w);
				if (L[lcaUV] > L[lcaVW]) {
					data combined = combine(
						s[curSize - 1].B,
						s[curSize - 2].B,
						lcaUV);
					s.pop_back();
					s.pop_back();
					s.push_back(MP(lcaUV, combined));
					if (SZ(s) == 1) {
						s.PB(MP(w, data(w)));
						next++;
					}
				} else {
					s.PB(MP(w, data(w)));
					next++;
				}
			} else {
				data combined = combine(
					s[curSize - 1].B,
					s[curSize - 2].B,
					lcaUV);
				s.pop_back();
				s.pop_back();
				s.push_back(MP(lcaUV, combined));
			}
		}
		printf("%lld\n", s[0].B.totalAns);
	}

	return 0;
}