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

#define MAXN 200200
#define INF 1000000000000000LL

const pair<ll,ll> inf = MP(0, INF);

int n, q, nrmq;
pair<ll,ll> rmq[MAXN << 3];
ll lazy[MAXN << 3], a[MAXN];

void propagate(int v, int l, int r) {
	int vl = v << 1;
	int vr = vl | 1;
	lazy[vl] += lazy[v];
	lazy[vr] += lazy[v];
	rmq[v].A += lazy[v] * (r - l + 1);
	rmq[v].B += lazy[v];
	lazy[v] = 0;
}

pair<ll,ll> combine(const pair<ll,ll>& a, const pair<ll,ll>& b) {
	return MP(a.A + b.A, min(a.B, b.B));
}

void build(int v, int l, int r) {
	if (l == r) {
		rmq[v] = MP(a[l], a[l]);
	} else {
		int vl = v << 1;
		int vr = vl | 1;
		int m = (l + r) >> 1;
		build(vl, l, m);
		build(vr, m + 1, r);
		rmq[v] = combine(rmq[vl], rmq[vr]);
	}
}

pair<ll,ll> rmqQuery(int v, int l, int r, int x, int y) {
	propagate(v, l, r);
	if (r < x || y < l) {
		return inf;
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

void updateAll(int l, int r, ll value) {
	rmqUpdate(1, 1, nrmq, l, r, value);
}

int main() {
	OPEN("haybales");
	scanf("%d%d", &n, &q);
	nrmq = n;
	FOR(i, 1, n) {
		scanf("%lld", &a[i]);
	}
	build(1, 1, nrmq);
	REP(iq, q) {
		char task[10];
		int l, r;
		scanf("%s%d%d", task, &l, &r);
		if (task[0] == 'M') {
			printf("%lld\n", rmqQuery(1, 1, nrmq, l, r).B);
		} else if (task[0] == 'S') {
			printf("%lld\n", rmqQuery(1, 1, nrmq, l, r).A);
		} else {
			ll value;
			scanf("%lld", &value);
			updateAll(l, r, value);
		}
	}

	return 0;
}