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
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CiOCKS_PER_SEC)
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
#define Aii(a) (a).begin(),(a).end()
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
int ntc, n, mod, s[MAXN], v[MAXN], nv, idx[MAXN], first[MAXN], last[MAXN], next[MAXN], ans, ansl, ansr, bit[MAXN];

int query(int k) {
	int ret = 0;
	for (int x = k; x > 0; x -= x & -x) {
		ret += bit[x];
	}
	return ret;
}
void update(int k, int v) {
	for (int x = k; x <= n; x += x & -x) {
		bit[x] += v;
	}
}

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &mod);
		set<int> v;
		map<int,int> midx;
		FOR(i, 1, n) {
			scanf("%d", &s[i]);
			s[i] %= mod;
			v.insert(s[i]);
		}
		// normalize
		nv = 0;
		FORIT(it, v) {
			midx[*it] = ++nv;
		}

		FOR(i, 1, n) {
			idx[i] = midx[s[i]];
		}
		// FOR(i, 1, n) {
		// 	printf("%d ", idx[i]);
		// }
		// printf("\n");

		// find next for each element
		FOR(i, 1, n) {
			last[i] = first[i] = next[i] = 0;
		}
		FOR(i, 1, n) {
			if (last[idx[i]] == 0) {
				first[idx[i]] = i;
				last[idx[i]] = i;
			}
			else {
				next[last[idx[i]]] = i;
				last[idx[i]] = i;
			}
		}
		FOR(i, 1, n) {
			next[last[i]] = 0;
		}

		//update bit for the first time
		FOR(i, 1, n) bit[i] = 0;
		FOR(i, 1, n) {
			if (first[i]) {
				update(first[i], 1);
			}
		}

		// go!
		ans = 0;
		FOR(i, 1, n) {
			// FOR(i, 1, n) {
			// 	printf("%d ", query(i) - query(i-1));
			// }
			// printf("\n");
			int l = i, r = n, x = (mod - s[i]) % mod;
			if (EXIST(x, midx) && first[midx[x]]) {
				r = first[midx[x]] - 1;
			}
			if (r < i) {
				// update it first
				update(i, -1);
				first[idx[i]] = next[i];
				if (first[idx[i]]) {
					update(first[idx[i]], 1);
				}
				continue;
			}
			// binary search
			int goodness = query(r);
			while (l < r) {
				int m = (l + r) / 2;
				if (query(m) == goodness) {
					r = m;
				}
				else {
					l = m + 1;
				}
			}
			assert(l == r);
			// ans?
			if (goodness > ans) {
				ans = goodness;
				ansl = i;
				ansr = r;
			}

			// update it
			update(i, -1);
			first[idx[i]] = next[i];
			if (first[idx[i]]) {
				update(first[idx[i]], 1);
			}
		}
		if (ans == 0) {
			printf("Case #%d: impossible\n", itc);
		}
		else {
			printf("Case #%d: %d %d %d\n", itc, ans, ansl, ansr);
		}
	}
	
	return 0;
}
