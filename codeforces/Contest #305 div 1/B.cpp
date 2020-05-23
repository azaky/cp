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

int n, a[MAXN], pl[MAXN], pr[MAXN], ans[MAXN], v[MAXN];

vector<pii> all;

int findL(int x) {
	if (pl[x] == x) {
		return x;
	} else {
		return pl[x] = findL(pl[x]);
	}
}
int findR(int x) {
	if (pr[x] == x) {
		return x;
	} else {
		return pr[x] = findR(pr[x]);
	}
}
void join(int a, int b) {
	pl[b] = pl[a];
	pr[a] = pr[b];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		all.PB(MP(a[i], i));
	}

	for (int i = 0; i < n; ++i) {
		pl[i] = pr[i] = i;
	}

	sort(ALL(all));
	reverse(ALL(all));

	int now = 0;
	FORIT(it, all) {
		int x = it->A;
		int p = it->B;

		v[p] = 1;
		if (p > 0 && v[p - 1]) {
			join(p - 1, p);
		}
		if (p < n - 1 && v[p + 1]) {
			join(p, p + 1);
		}
		int l = findL(p);
		int r = findR(p);
		int s = r - l + 1;
		for (int i = now + 1; i <= s; ++i) {
			ans[i] = x;
		}
		now = max(now, s);
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");

	return 0;
}