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
#define PLUSMOD(a, addum, mod) a = (((a) + (addum)) % (mod))

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define sejuta 1048576
#define MOD 1000000007LL

int ntc, nq;
ll tree[4][(sejuta + 5) << 1], lazy[4][(sejuta + 5) << 1], sum[4][sejuta + 5];

void update(int idx, int v, int l, int r, int x, int y, int value) {
	int vl = v << 1;
	int vr = vl | 1;
	if (lazy[idx][v]) {
		tree[idx][v] += (sum[idx][r] - sum[idx][l - 1] + MOD) * lazy[idx][v];
		tree[idx][v] %= MOD;
		if (l < r) {
			lazy[idx][vl] += lazy[idx][v];
			lazy[idx][vl] %= MOD;
			lazy[idx][vr] += lazy[idx][v];
			lazy[idx][vr] %= MOD;
		}
		lazy[idx][v] = 0;
	}
	if (x <= l && r <= y) {
		tree[idx][v] += (sum[idx][r] - sum[idx][l - 1] + MOD) * value;
		tree[idx][v] %= MOD;
		if (l < r) {
			lazy[idx][vl] += value;
			lazy[idx][vl] %= MOD;
			lazy[idx][vr] += value;
			lazy[idx][vr] %= MOD;
		}
	} else if (r < x || y < l) {
		// do nothing
	} else {
		int m = (l + r) >> 1;
		update(idx, vl, l, m, x, y, value);
		update(idx, vr, m + 1, r, x, y, value);
		tree[idx][v] = (tree[idx][vl] + tree[idx][vr]) % MOD;
	}
}

ll query(int idx, int v, int l, int r, int x, int y) {
	int vl = v << 1;
	int vr = vl | 1;
	if (lazy[idx][v]) {
		tree[idx][v] += (sum[idx][r] - sum[idx][l - 1] + MOD) * lazy[idx][v];
		tree[idx][v] %= MOD;
		if (l < r) {
			lazy[idx][vl] += lazy[idx][v];
			lazy[idx][vl] %= MOD;
			lazy[idx][vr] += lazy[idx][v];
			lazy[idx][vr] %= MOD;
		}
		lazy[idx][v] = 0;
	}
	if (x <= l && r <= y) {
		// if (idx == 0) {
		// 	printf("query(%d, [%d..%d], [%d..%d]) = %d\n", idx, l, r, x, y, (int)tree[idx][v]);
		// }
		return tree[idx][v];
	} else if (r < x || y < l) {
		return 0;
	} else {
		int m = (l + r) >> 1;
		ll ret = (query(idx, vl, l, m, x, y) + query(idx, vr, m + 1, r, x, y)) % MOD;
		return ret;
	}
}

int main() {
	REP(i, 4) {
		sum[i][0] = 0;
	}
	FOR(i, 1, sejuta) {
		ll x = 1;
		REP(j, 4) {
			sum[j][i] = (sum[j][i - 1] + x) % MOD;
			x = (x * i) % MOD;
		}
	}

	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		RESET(tree, 0);
		RESET(lazy, 0);

		printf("Case #%d:\n", itc);
		scanf("%d", &nq);

		ll nol = 0;
		REP(iq, nq) {
			int a[4], x1, x2;
			char task[10];
			scanf("%s%d%d%d%d%d%d", task, &x1, &x2, &a[3], &a[2], &a[1], &a[0]);
			REP(i, 4) {
				a[i] = ((a[i] % MOD) + MOD) % MOD;
			}
			if (task[0] == 't') {
				ll e = 0;
				if (x2 > 0) {
					REP(i, 4) {
						e += query(i, 1, 1, sejuta, max(x1, 1), max(x2, 1));
						e %= MOD;
					}
				}
				if (x1 == 0) {
					e += nol;
					e %= MOD;
				}
				printf("%d\n", (int)e);
				int r1 = ((e * x1) % 1000000LL);
				int r2 = ((e * x2) % 1000000LL);
				x1 = min(r1, r2);
				x2 = max(r1, r2);
				// printf("UPDATE BARU DI (%d, %d)\n", x1, 2);
			}
			if (x2 > 0) {
				REP(i, 4) {
					update(i, 1, 1, sejuta, max(x1, 1), max(x2, 1), a[i]);
				}
			}
			if (x1 == 0) {
				nol += a[0];
			}
		}

	}

	return 0;
}