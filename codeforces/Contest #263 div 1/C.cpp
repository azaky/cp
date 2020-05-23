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

int n, q, len;
int tree[8*MAXN];
vector<pii> lazy[8*MAXN];

void build(int v, int l, int r) {
	if (l == r) {
		tree[v] = 1;
	}
	else {
		int m = (l + r) >> 1;
		int vl = v << 1;
		int vr = vl | 1;
		build(vl, l, m);
		build(vr, m + 1, r);
		tree[v] = tree[vl] + tree[vr];
	}
}

int query(int v, int l, int r, int x, int y);

void propagate(int v, int l, int r) {
/*
	printf("propagate(%d, %d, %d)\n", v, l, r);
	FORIT(it, lazy[v]) {
		printf("(%d, %d) ", it->A, it->B);
	}
	printf("\n");
*/
	int m = (l + r) >> 1;
	int vl = v << 1;
	int vr = vl | 1;
	FORIT(it, lazy[v]) {
		if (it->A < it->B) {
			tree[v] += query(1, 1, n, it->A, it->B);
			lazy[vl].PB(MP(it->A, it->A + m - l));
			lazy[vr].PB(MP(it->A + m - l + 1, it->B));
		}
		else {
			tree[v] += query(1, 1, n, it->B, it->A);
			lazy[vl].PB(MP(it->A, it->A - m + l));
			lazy[vr].PB(MP(it->A - m + l - 1, it->B));
		}
	}
	lazy[v].clear();
}

int query(int v, int l, int r, int x, int y) {
	//printf("query(%d, %d, %d, %d, %d)\n", v, l, r, x, y);
	int m = (l + r) >> 1;
	int vl = v << 1;
	int vr = vl | 1;
	if (r < x || y < l) return 0;
	//printf("fromquery ");
	propagate(v, l, r);
	
	if (x <= l && r <= y) return tree[v];
	else {
		return query(vl, l, m, x, y) + query(vr, m+1, r, x, y);
	}
}

void fold(int v, int l, int r, int x, int y, int fx, int fy) {
	//printf("fold(%d, %d, %d, %d, %d, %d, %d)\n", v, l, r, x, y, fx, fy);
	int m = (l + r) >> 1;
	int vl = v << 1;
	int vr = vl | 1;
	//printf("fromfoldup ");
	propagate(v, l, r);
	
	if (r < x || y < l) return;
	if (x <= l && r <= y) {
		if (fx < fy) {
			lazy[v].PB(MP(fx + l - x, fx + r - x));
		}
		else {
			lazy[v].PB(MP(fx - l + x, fx - r + x));
		}
		//printf("fromfoldin ");
		propagate(v, l, r);
	}
	else {
		fold(vl, l, m, x, y, fx, fy);
		fold(vr, m+1, r, x, y, fx, fy);
		tree[v] = tree[vl] + tree[vr];
	}
}

int main(){
	scanf("%d%d", &n, &q);
	build(1, 1, n);
	int lp = 0, rp = n;
	bool flipped = false;
	REP(iq, q) {
		int task;
		scanf("%d", &task);
		if (task == 1) {
			int p;
			scanf("%d", &p);
			if (flipped) {
				p = (rp-lp)-p;
			}
			if (p < (rp-lp)-p) {
				fold(1, 1, n, lp + p+1, lp + p+p, lp + p, lp + 1);
				lp += p;
			}
			else {
				int pp = (rp-lp)-p;
				fold(1, 1, n, lp + p - pp + 1, lp + p, rp, lp + p + 1);
				flipped = !flipped;
				rp -= pp;
			}
		}
		else {
			int l, r, ans;
			scanf("%d%d", &l, &r);
			if (flipped) {
				l = (rp-lp) - l;
				r = (rp-lp) - r;
				swap(l, r);
			}
			ans = query(1, 1, n, lp + l + 1, lp + r);
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
