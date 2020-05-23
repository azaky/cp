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
	#define debug(...) fprintf(stderr, __VA_ARGS__)
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
#define INF 0x3FFFFFFF

char s[MAXN];
int ntc, n, a[MAXN], b[MAXN], total, tree[8 * MAXN], add[8 * MAXN];

void build(int v, int l, int r) {
	add[v] = 0;
	if (l == r) {
		tree[v] = b[l];
	}
	else {
		int m = (l+r)>>1;
		int vl = v<<1;
		int vr = vl|1;
		build(vl, l, m);
		build(vr, m+1, r);
		tree[v] = min(tree[vl], tree[vr]);
	}
}

void update(int v, int l, int r, int x, int y, int addum) {
	int vl = v<<1;
	int vr = vl|1;
	// do homework, you lazy boy
	tree[v] += add[v];
	// homework done! or not... do the rest later, I'm too lazy
	add[vl] += add[v];
	add[vr] += add[v];
	add[v] = 0;
	
	if (r < x || y < l) return;
	if (x <= l && r <= y) {
		tree[v] += addum;
		add[vl] += addum;
		add[vr] += addum;
		return;
	}
	else {
		int m = (l+r)>>1;
		update(vl, l, m, x, y, addum);
		update(vr, m+1, r, x, y, addum);
		tree[v] = min(tree[vl], tree[vr]);
	}
}

int query(int v, int l, int r, int x, int y) {
	int vl = v<<1;
	int vr = vl|1;
	// do homework, you lazy boy
	tree[v] += add[v];
	// homework done! or not... do the rest later, I'm too lazy
	add[vl] += add[v];
	add[vr] += add[v];
	add[v] = 0;
	
	if (r < x || y < l) return INF;
	if (x <= l && r <= y) {
		return tree[v];
	}
	else {
		int m = (l+r)>>1;
		return min(query(vl, l, m, x, y), query(vr, m+1, r, x, y));
	}
}

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%s", s);
		n = strlen(s);
		total = 0;
		FOR(i, 1, n) {
			a[i] = s[i-1] == '(' ? 1 : -1;
			total += a[i];
			b[i] = total;
			//update(1, 1, n, i, i, total);
		}
		build(1, 1, n);
		while (true) {
			int task;
			scanf("%d", &task);
			if (task == -1) break;
			if (task == 0) {
				if (query(1, 1, n, 1, n) == 0 && total == 0) {
					printf("Y");
				}
				else {
					printf("T");
				}
			}
			else {
				int pos;
				scanf("%d", &pos);
				pos++;
				int v = a[pos] == -1 ? 2 : -2;
				total += v;
				a[pos] += v;
				update(1, 1, n, pos, n, v);
			}
			/*
			FOR(i, 1, n) {
				printf("%d ", query(1, 1, n, i, i));
			}
			printf("\n");
			printf("total = %d\n", total);
			*/
		}
		printf("\n");
	}

	return 0;
}
