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
#define INF 100100

int nrmq;
pii rmq[MAXN << 3];
int lazy[MAXN << 3];

int n, bessie[MAXN], elsie[MAXN], isbessie[MAXN], temp[MAXN];

void propagate(int v, int l, int r) {
	int vl = v << 1;
	int vr = vl | 1;
	lazy[vl] += lazy[v];
	lazy[vr] += lazy[v];
	rmq[v].B += lazy[v];
	lazy[v] = 0;
}

pii combine(const pii& a, const pii& b) {
	if (a.B < b.B) {
		return a;
	} else if (a.B > b.B) {
		return b;
	} else if (a.A > b.A) {
		return a;
	} else {
		return b;
	}
}

void build(int v, int l, int r) {
	lazy[v] = 0;
	if (l == r) {
		rmq[v] = MP(l, temp[l]);
	} else {
		int vl = v << 1;
		int vr = vl | 1;
		int m = (l + r) >> 1;
		build(vl, l, m);
		build(vr, m + 1, r);
		rmq[v] = combine(rmq[vl], rmq[vr]);
	}
}

pii rmqQuery(int v, int l, int r, int x, int y) {
	propagate(v, l, r);
	if (r < x || y < l) {
		return MP(-1, INF);
	} else if (x <= l && r <= y) {
		return rmq[v];
	} else {
		int vl = v << 1;
		int vr = vl | 1;
		int m = (l + r) >> 1;
		return combine(rmqQuery(vl, l, m, x, y), rmqQuery(vr, m + 1, r, x, y));
	}
}

void rmqUpdate(int v, int l, int r, int x, int y, ll value) {
	propagate(v, l, r);
	if (r < x || y < l) {
		return;
	} else if (x <= l && r <= y) {
		lazy[v] += value;
		propagate(v, l, r);
	} else {
		int vl = v << 1;
		int vr = vl | 1;
		int m = (l + r) >> 1;
		rmqUpdate(vl, l, m, x, y, value);
		rmqUpdate(vr, m + 1, r, x, y, value);
		rmq[v] = combine(rmq[vl], rmq[vr]);
	}
}

vector<int> calc() {
	vector<int> ret;
	ret.PB(0);
	int loss = 0;
	RESET(temp, 0);
	temp[2 * n + 1] = 0;
	FORD(i, 2 * n, 1) {
		temp[i] = temp[i + 1];
		if (isbessie[i]) {
			temp[i]++;
		}
	}
	// FOR(i, 1, 2 * n) {
	// 	printf("%3d", temp[i]);
	// }
	// printf("\n");
	build(1, 1, nrmq);
	REP(i, n) {
		// activate elsie
		// printf("activate %d\n", elsie[i]);
		rmqUpdate(1, 1, nrmq, 1, elsie[i], -1);
		// FOR(j, 1, 2 * n) {
		// 	printf("%3d", rmqQuery(1, 1, nrmq, j, j).B);
		// }
		// printf("\n");
		pii worst = rmqQuery(1, 1, nrmq, 1, 2 * n);
		while (worst.B < 0) {
			// printf("loss %d : %d\n", worst.A, worst.B);
			assert(worst.B == -1);
			rmqUpdate(1, 1, nrmq, 1, worst.A, +1);
			worst = rmqQuery(1, 1, nrmq, 1, 2 * n);
			loss++;
		}
		assert(i + 1 >= loss);
		ret.PB(i + 1 - loss);
	}
	return ret;
}

int main() {
	OPEN("cardgame");
	scanf("%d", &n);
	nrmq = 2 * n;
	REP(i, n) {
		scanf("%d", &elsie[i]);
		isbessie[elsie[i]] = 1;
	}
	int dummy = 0;
	FORD(i, 2*n, 1) {
		isbessie[i] = 1 - isbessie[i];
		if (isbessie[i]) {
			bessie[dummy++] = i;
		}
	}
	vector<int> mmax = calc();
	reverse(elsie, elsie + n);
	reverse(bessie, bessie + n);
	reverse(isbessie + 1, isbessie + 2 * n + 1);
	REP(i, n) {
		elsie[i] = 2 * n + 1 - elsie[i];
		bessie[i] = 2 * n + 1 - bessie[i];
		assert(isbessie[bessie[i]]);
		// printf("elsie[%d] = %d\n", i, elsie[i]);
		// printf("bessie[%d] = %d\n", i, bessie[i]);
	}
	vector<int> mmin = calc();
	int ans = 0;
	FOR(i, 0, n) {
		// printf("%3d%3d\n", mmax[i], mmin[n - i]);
		MX(ans, mmax[i] + mmin[n - i]);
	}
	printf("%d\n", ans);

	return 0;
}
