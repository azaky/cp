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

int n, _a[MAXN], _b[MAXN], _z[MAXN], k[MAXN];
int p[MAXN], size[MAXN];

map<int, int> d[MAXN], m[MAXN];

int find(int x) {
	if (p[x] == x) {
		return x;
	} else {
		return p[x] = find(p[x]);
	}
}

void init() {
	FOR(i, 1, n) {
		p[i] = i;
		size[i] = 1;
		d[i][i] = 0;
		m[i][0] = 1;
	}
}

int main() {
	scanf("%d", &n);
	FOR(i, 1, n - 1) {
		scanf("%d%d%d", &_a[i], &_b[i], &_z[i]);
	}
	REP(i, n - 1) {
		scanf("%d", &k[i]);
	}
	init();
	ll curans = 0;
	vector<ll> ans;
	ans.PB(0);
	REPD(ii, n - 1) {
		int a = _a[k[ii]];
		int b = _b[k[ii]];
		int z = _z[k[ii]];
		int roota = find(a);
		int rootb = find(b);
		if (size[roota] < size[rootb]) {
			swap(a, b);
			swap(roota, rootb);
		}
		// answer query first
		int add = z ^ d[rootb][b] ^ d[roota][a];
		FORIT(it, d[rootb]) {
			if (EXIST(it->B ^ add, m[roota])) {
				curans += m[roota][it->B ^ add];
			}
		}
		ans.PB(curans);
		// merge them
		p[rootb] = roota;
		size[roota] += size[rootb];
		FORIT(it, d[rootb]) {
			m[roota][it->B ^ add]++;
			d[roota][it->A] = it->B ^ add;
		}
	}
	REPD(i, n) {
		printf("%lld\n", ans[i]);
	}

	return 0;
}