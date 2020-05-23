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

/** Binary Indexed Tree
 * usage:
 * BIT bit(n); 							// initialization. one-based, from 1 to n
 * bit.init(n);							// another way to init. All values will be reset to zero
 * bit.update(pos, value); 				// add value to pos
 * int sum = bit.query(left, right); 	// find the sum from left to right
 * int sum = bit.query(pos);			// find the sum from 1 to pos
 */
struct BIT {
	BIT() {
		this->n = 0;
	}
	BIT(int n) {
		this->n = n;
		bit.resize(n+1);
	}
	void init(int n) {
		this->n = n;
		bit.resize(n+1);
		for (int i = 0; i <= n; ++i) {
			bit[i] = 0;
		}
	}
	void update(int pos, int value) {
		for (int x = pos; x <= n; x += (x & -x)) {
			bit[x] += value;
		}
	}
	int query(int left, int right) {
		if (left > right) {
			return 0;
			// return query(right, left)
		}
		else {
			return query(right) - query(left - 1);
		}
	}
	int query(int pos) {
		int ret = 0;
		for (int x = pos; x > 0; x -= (x & -x)) {
			ret += bit[x];
		}
		return ret;
	}

	int n;
	vector<int> bit;
};

#define MAXN 100100
int n, a[MAXN], occ[MAXN], occl[MAXN], occr[MAXN];

int main() {
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d", &a[i]);
		occ[a[i]]++;
	}
	int odd = 0;
	FOR(i, 1, n) {
		if (occ[i] % 2) odd++;
	}
	if (odd > 1) {
		puts("0");
		return 0;
	}
	odd = 0;
	FOR(i, 1, n) {
		if (occ[i] % 2) odd = i;
	}

	int m = (n + 1) >> 1;
	int l = 1;
	while (l <= m && a[l] == a[n + 1 - l]) l++;

	if (l > m) {
		// all works
		ll ans = (ll) n * (ll) (n+1) / 2LL;
		cout << ans << endl;
		return 0;
	}
	else {
		// printf("[%d]\n", l);
		// reset occ
		FOR(i, 1, n) occ[i] = 0;
		FOR(i, l, n + 1 - l) {
			occ[a[i]]++;
		}
		// huba huba from left
		int kl = l;
		while (true) {
			int x = a[kl];
			occl[x]++;
			if (occl[x] > occ[x] / 2) {
				break;
			}
			else {
				kl++;
			}
		}
		// huba huba from right
		int kr = n + 1 - l;
		while (true) {
			int x = a[kr];
			occr[x]++;
			if (occr[x] > occ[x] / 2) {
				break;
			}
			else {
				kr--;
			}
		}
		// printf("kl = %d, kr = %d\n", kl, kr);
		if (kl > (n >> 1) && (!odd || a[kl] == odd)) {
			while (a[kl] == a[n + 1 - kl]) kl++;
		}
		if (kr <= ((n + 1) >> 1) && (!odd || a[kr] == odd)) {
			while (a[kr] == a[n + 1 - kr]) kr--;
		}
		// printf("kl = %d, kr = %d\n", kl, kr);

		// huba huba everything
		ll ans = (ll)(n - kr + 1 + kl - l) * (ll)l ;
		cout << ans << endl;
	}

	return 0;
}