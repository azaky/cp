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

int lca(vector<int> &match, vector<int> &base, vector<int> &p, int a, int b) {
	vector<bool> used(SZ(match));
	while (true) {
		a = base[a];
		used[a] = true;
		if (match[a] == -1) {
			break;
		}
		a = p[match[a]];
	}
	while (true) {
		b = base[b];
		if (used[b]) {
			return b;
		}
		b = p[match[b]];
	}
	return -1;
}

void markPath(vector<int> &match, vector<int> &base, vector<bool> &blossom, vector<int> &p, int v, int b, int children) {
	for (; base[v] != b; v = p[match[v]]) {
		blossom[base[v]] = blossom[base[match[v]]] = true;
		p[v] = children;
		children = match[v];
	}
}

int findPath(vector<vector<int> > &graph, vector<int> &match, vector<int> &p, int root) {
	int n = SZ(graph);
	vector<bool> used(n);
	FORIT(it, p) {
		*it = -1;
	}
	vector<int> base(n);
	for (int i = 0; i < n; ++i) {
		base[i] = i;
	}

	used[root] = true;
	int qh = 0;
	int qt = 0;
	vector<int> q(n);
	q[qt++] = root;
	while (qh < qt) {
		int v = q[qh++];

		FORIT(it, graph[v]) {
			int to = *it;
			if (base[v] == base[to] || match[v] == to) {
				continue;
			}
			if (to == root || match[to] != -1 && p[match[to]] != -1) {
				int curbase = lca(match, base, p, v, to);
				vector<bool> blossom(n);
				markPath(match, base, blossom, p, v, curbase, to);
				markPath(match, base, blossom, p, to, curbase, v);
				for (int i = 0; i < n; ++i) {
					if (blossom[base[i]]) {
						base[i] = curbase;
						if (!used[i]) {
							used[i] = true;
							q[qt++] = i;
						}
					}
				}
			} else if (p[to] == -1) {
				p[to] = v;
				if (match[to] == -1) {
					return to;
				}
				to = match[to];
				used[to] = true;
				q[qt++] = to;
			}
		}
	}
	return -1;
}

int maxMatching(vector<vector<int> > graph) {
	int n = SZ(graph);
	vector<int> match(n, -1);
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		if (match[i] == -1) {
			int v = findPath(graph, match, p, i);
			while (v != -1) {
				int pv = p[v];
				int ppv = match[pv];
				match[v] = pv;
				match[pv] = v;
				v = ppv;
			}
		}
	}

	int matches = 0;
	for (int i = 0; i < n; ++i) {
		if (match[i] != -1) {
			++matches;
		}
	}
	return matches / 2;
}

#define MAXN 333

vector<int> adj[MAXN];
int ntc, n, m;

void dfs(int v, vector<int> &used, vector<int> &vertex) {
	if (used[v]) return;
	used[v] = 1;
	vertex.PB(v);
	FORIT(it, adj[v]) {
		if (!used[*it]) {
			dfs(*it, used, vertex);
		}
	}
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &m);
		REP(i, n) {
			adj[i].clear();
		}
		vector<int> deg(n, 0);
		REP(i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			adj[x].PB(y);
			adj[y].PB(x);
			deg[x]++;
			deg[y]++;
		}
		vector<int> used(n);
		vector<int> p(n);
		vector<pii> ans;
		bool ngepas = true;
		// flood fill
		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				continue;
			}
			vector<int> vertex;
			dfs(i, used, vertex);

			int size = SZ(vertex);
			int totaldeg = 0;
			FORIT(it, vertex) {
				totaldeg += deg[*it];
			}
			totaldeg /= 2;
			int maxans = totaldeg;
			while (true) {
				// pick v with min edges
				int minv = -1;
				FORIT(it, vertex) {
					if (p[*it]) {
						continue;
					}
					if (minv == -1 || deg[*it] < deg[minv]) {
						minv = *it;
					}
				}
				// printf("minv = %d\n", minv + 1);
				if (minv == -1) {
					assert(false);
				}
				p[minv] = 1;
				totaldeg -= deg[minv];
				if (totaldeg <= size - 1) {
					break;
				} else {
					FORIT(it, adj[minv]) {
						deg[*it]--;
					}
					size--;
				}
			}
			int temp = min(maxans, size);
			ans.PB(MP(temp, temp == maxans));
		}

		bool adayangnggakpas = false;
		FORIT(it, ans) {
			if (!it->B) {
				adayangnggakpas = true;
			}
		}
		int realans = 0;
		if (adayangnggakpas) {
			realans = 500;
			FORIT(it, ans) {
				if (!it->B) {
					MN(realans, it->A);
				}
			}
		} else {
			FORIT(it, ans) {
				realans += it->A;
			}
		}

		printf("%d\n", realans);
	}

	return 0;
}
