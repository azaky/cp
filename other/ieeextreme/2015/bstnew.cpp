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

#define MAXN 500500
#define MAXS 500500

char bufferl[MAXS], bufferr[MAXS];

map<string, int> idx;
set<string> val;
pair<string, string> s[MAXN];
pii a[MAXN];
int n;

vector<int> adj[MAXN];
bool visited[MAXN];
bool valid;

void dfs(int v, int p, int l, int r) {
	if (visited[v] || !valid) {
		valid = false;
		return;
	}
	visited[v] = true;
	vector<int> sm, lg;
	FORIT(it, adj[v]) {
		if (*it == p) continue;
		if (*it < v) {
			if (*it <= l) {
				valid = false;
				return;
			}
			sm.PB(*it);
		} else if (*it > v) {
			if (*it >= r) {
				valid = false;
				return;
			}
			lg.PB(*it);
		} else {
			valid = false;
			return;
		}
	}
	sort(ALL(sm)); sort(ALL(lg));
	if (SZ(sm) == 2) {
		if (sm[0] == sm[1]) {
			valid = false;
			return;
		}
		dfs(sm[0], v, l, sm[1]);
		dfs(sm[1], v, sm[0], v);
	} else if (SZ(sm) == 1) {
		dfs(sm[0], v, l, v);
	}
	if (SZ(lg) == 2) {
		if (lg[0] == lg[1]) {
			valid = false;
			return;
		}
		dfs(lg[0], v, v, lg[1]);
		dfs(lg[1], v, lg[0], r);
	} else if (SZ(lg) == 1) {
		dfs(lg[0], v, v, r);
	}
}

int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		idx.clear();
		val.clear();
		REP(i, n) {
			scanf("%s%s", bufferl, bufferr);
			s[i] = make_pair(bufferl, bufferr);
			val.insert(bufferl);
			val.insert(bufferr);
		}
		int idxn = 0;
		FORIT(it, val) {
			idx[*it] = idxn++;
		}
		REP(i, n) {
			a[i] = MP(idx[s[i].A], idx[s[i].B]);
		}
		bool isSorted = true;
		REP(i, n) {
			if (a[i].A >= a[i].B) {
				isSorted = false;
				break;
			}
		}
		if (!isSorted) {
			puts("!BST");
			continue;
		}
		// absolute bst
		bool absoluteBst = true;
		REP(i, n) {
			a[i].B *= -1;
		}
		sort(a, a + n);
		REP(i, n) {
			a[i].B *= -1;
		}
		for (int i = 0; i + 1 < n; ++i) {
			if (a[i].B != a[i + 1].A) {
				absoluteBst = false;
				break;
			}
		}
		if (absoluteBst) {
			puts("BST!");
			continue;
		}
		// probably bst
		// build graph
		int m = SZ(val);
		REP(i, m) {
			adj[i].clear();
		}
		valid = n == m - 1;
		REP(i, n) {
			if (i) {
				if (a[i] == a[i - 1]) {
					valid = false;
					break;
				}
			}
			adj[a[i].A].PB(a[i].B);
			adj[a[i].B].PB(a[i].A);
		}
		REP(i, m) {
			int sm = 0, lg = 0;
			FORIT(it, adj[i]) {
				if (*it < i) {
					sm++;
				} else {
					lg++;
				}
			}
			if (sm + lg > 3) {
				valid = false;
				break;
			} else if (sm > 2 || lg > 2) {
				valid = false;
				break;
			}
		}
		if (valid) {
			REP(i, m) {
				adj[i].clear();
			}
			REP(i, n) {
				adj[a[i].A].PB(a[i].B);
			}
			vector<int> cover;
			REP(i, m) {
				if (!valid) {
					break;
				}
				// remove cover
				while (SZ(cover) > 0 && cover.back() == i) {
					cover.pop_back();
				}
				int up = m;
				if (SZ(cover) > 0) {
					up = cover.back();
				}
				FORIT(it, adj[i]) {
					if (*it > up) {
						valid = false;
						break;
					}
					cover.PB(*it);
				}
			}
			// REP(i, m) {
			// 	visited[i] = false;
			// }
			// dfs(0, -1, 0, m);
			// REP(i, m) {
			// 	if (!visited[i]) {
			// 		valid = false;
			// 		break;
			// 	}
			// }
		}

		if (valid) {
			puts("BST?");
		} else {
			puts("!BST");
		}
	}

	return 0;
}