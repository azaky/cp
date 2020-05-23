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

struct info {
	int mod;
	ll pre[3], suf[3];
	ll three;
} empty;

info combine(info l, info r) {
	info ret;
	REP(i, 3) {
		ret.pre[i] = l.pre[i] + r.pre[(i + 3 - l.mod) % 3];
		ret.suf[i] = r.suf[i] + l.suf[(i + 3 - r.mod) % 3];
	}
	ret.mod = (l.mod + r.mod) % 3;
	ret.three = l.three + r.three + l.suf[0] * r.pre[0] + l.suf[1] * r.pre[2] + l.suf[2] * r.pre[1];
	return ret;
}

#define MAXN 100100
int n, q, a[MAXN];
info node[MAXN << 2];
char s[MAXN];

void build(int v, int l, int r) {
	if (l+1 == r) {
		int mod = a[l] % 3;
		node[v].mod = mod;
		RESET(node[v].pre, 0);
		RESET(node[v].suf, 0);
		node[v].pre[mod] = node[v].suf[mod] = 1;
		node[v].three = mod ? 0 : 1;
	}
	else {
		int vl = v << 1;
		int vr = vl | 1;
		int m = (l + r) >> 1;
		build(vl, l, m);
		build(vr, m, r);
		node[v] = combine(node[vl], node[vr]);
	}
}
void update(int v, int l, int r, int x) {
	if (r <= x || x < l) return;
	if (l+1 == r) {
		int mod = a[l] % 3;
		node[v].mod = mod;
		RESET(node[v].pre, 0);
		RESET(node[v].suf, 0);
		node[v].pre[mod] = node[v].suf[mod] = 1;
		node[v].three = mod ? 0 : 1;
	}
	else {
		int vl = v << 1;
		int vr = vl | 1;
		int m = (l + r) >> 1;
		update(vl, l, m, x);
		update(vr, m, r, x);
		node[v] = combine(node[vl], node[vr]);
	}
}
info query(int v, int l, int r, int x, int y) {
	if (r <= x || y <= l) return empty;
	if (x <= l && r <= y) {
		return node[v];
	}
	else {
		int vl = v << 1;
		int vr = vl | 1;
		int m = (l + r) >> 1;
		return combine(query(vl, l, m, x, y), query(vr, m, r, x, y));
	}
}


int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", s);
	REP(i, n) {
		a[i] = s[i] - '0';
	}
	empty.mod = 0;
	RESET(empty.pre, 0);
	RESET(empty.suf, 0);
	empty.three = 0;
	build(1, 0, n);

	REP(iq, q) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		x--;
		if (t == 1) {
			a[x] = y;
			update(1, 0, n, x);
		}
		else {
			printf("%lld\n", query(1, 0, n, x, y).three);
		}
	}

	return 0;
}