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

typedef vector<ll> vi;
typedef vector<vi> vvi;
#define MOD 1000000007LL

vvi matrixUnit(int n) {
    vvi res(n, vi(n));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}
vvi matrixAdd(const vvi &a, const vvi &b) {
    int n = a.size();
    int m = a[0].size();
    vvi res(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = (a[i][j] + b[i][j]) % MOD;
    return res;
}
vvi matrixMul(const vvi &a, const vvi &b) {
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    vvi res(n, vi(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            for (int p = 0; p < m; p++)
                res[i][j] = (res[i][j] + a[i][p] * b[p][j]) % MOD;
    return res;
}
vvi matrixPow(const vvi &a, ll p) {
    if (p == 0)
        return matrixUnit(a.size());
    if (p & 1)
        return matrixMul(a, matrixPow(a, p - 1));
    return matrixPow(matrixMul(a, a), p / 2);
}

#define MAXN 111
ll k;
int n;
pair<ll, int> cow[MAXN];

int main() {
	vvi init(4, vi(4));
	init[0][0] = init[0][1] = init[1][0] = init[1][1] = init[1][2] = init[2][1] = init[2][2] = init[2][3] = init[3][2] = init[3][3] = 1;

	cin >> k >> n;
	REP(i, n) {
		cin >> cow[i].B >> cow[i].A;
	}
	sort(cow, cow + n);
	ll cur = 1;
	vi ans(4);
	ans[0] = 1;
	int ik = 0;
	while (ik < n) {
		vector<int> r(4);
		ll inow = cow[ik].A;
		while (ik < n && cow[ik].A == inow) {
			r[cow[ik].B - 1] = 1;
			ik++;
		}
		vi ways(4);
		vvi mat = matrixPow(init, inow - cur - 1);
		for (int i = 0; i < 4; ++i) {
			ways[i] = 0;
			for (int j = 0; j < 4; ++j) {
				ways[i] += mat[i][j] * ans[j];
				ways[i] %= MOD;
			}
		}

		for (int i = 0; i < 4; ++i) {
			ans[i] = 0;
			if (r[i]) {
				// do nothing
			} else {
				for (int j = max(0, i - 1); j <= min(3, i + 1); ++j) {
					ans[i] = (ans[i] + ways[j]) % MOD;
				}
			}
		}
		cur = inow;

		// printf("cur = %lld\n", cur);
		// for (int i = 0; i < 4; ++i) {
		// 	printf("%lld ", ans[i]);
		// }
		// printf("\n");
	}
	vvi mat = matrixPow(init, k - cur);
	vi ways(4);
	for (int i = 0; i < 4; ++i) {
		ways[i] = 0;
		for (int j = 0; j < 4; ++j) {
			ways[i] += mat[i][j] * ans[j];
			ways[i] %= MOD;
		}
	}
	printf("%lld\n", ways[0]);

	return 0;
}