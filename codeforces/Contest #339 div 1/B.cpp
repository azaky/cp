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

int n;
pair<ll, int> a[MAXN];
ll AA, cf, cm, m, sum[MAXN], mmm[MAXN], realans[MAXN];

int main() {
	cin >> n >> AA >> cf >> cm >> m;
	// scanf("%d%lld%lld%lld%lld", &n, &AA, &cf, &cm, &m);
	FOR(i, 1, n) {
		cin >> a[i].A;
		// scanf("%lld", &a[i].A);
		a[i].B = i;
	}
	sort(a + 1, a + n + 1);
	sum[0] = 0;
	mmm[0] = 0;
	FOR(i, 1, n) {
		sum[i] = sum[i - 1] + a[i].A;
		mmm[i] = mmm[i - 1] + (a[i].A - a[i - 1].A) * (i - 1);
	}
	int p = n;
	ll ans = 0;
	int kans = 0;
	ll hans = 0;
	FOR(k, 0, n) {
		// max k of them
		ll maxneed = AA * k - (sum[n] - sum[n - k]);
		if (maxneed > m) continue;
		ll rest = m - maxneed;
		while (p > 0 && mmm[p] > rest) {
			p--;
		}
		if (p > n - k) {
			p = n - k;
		}
		ll h = p > 0 ? (a[p].A + (rest - mmm[p]) / p) : 0;
		MN(h, AA);
		if (k == n) {
			h = AA;
		}
		ll score = cf * k + cm * h;
		if (score > ans) {
			kans = k;
			hans = h;
			ans = score;
		}
	}
	// printf("k = %d\nh = %lld\n", kans, hans);
	printf("%lld\n", ans);
	FOR(i, 1, n - kans) {
		ll add = max(hans - a[i].A, 0LL);
		// printf("i = %d, add = %lld\n", i, add);
		m -= add;
		a[i].A += add;
	}
	FOR(i, 1, kans) {
		ll add = AA - a[n + 1 - i].A;
		// printf("i = %d, add = %lld\n", i, add);
		m -= add;
		a[n + 1 - i].A += add;
	}
	assert(m >= 0);
	FOR(i, 1, n) {
		ll add = min(m, AA - a[i].A);
		// printf("i = %d, add = %lld\n", i, add);
		m -= add;
		a[i].A += add;
		realans[a[i].B] = a[i].A;
	}
	FOR(i, 1, n) {
		// printf("%lld", realans[i]);
		cout << realans[i];
		if (i < n) {
			putchar(' ');
		} else {
			puts("");
		}
	}

	return 0;
}