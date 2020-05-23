/* DELAPAN.3gp */
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
typedef vector<int> vlnt;

//abbrevlations
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

/* -------------- end of DELAPAN.3gp's template -------------- */

/** MATRIX TEMPLATE **/
typedef vector<long long> vl;
typedef vector<vl> vvl;
#define MOD 1000000007LL

vvl matrixUnit(int n) {
    vvl res(n, vl(n));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}
vvl matrixAdd(const vvl &a, const vvl &b) {
    int n = a.size();
    int m = a[0].size();
    vvl res(n, vl(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = (a[i][j] + b[i][j]) % MOD;
    return res;
}
vvl matrixMul(const vvl &a, const vvl &b) {
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    vvl res(n, vl(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            for (int p = 0; p < m; p++)
                res[i][j] = (res[i][j] + a[i][p] * b[p][j]) % MOD;
    return res;
}
vvl matrixPow(const vvl &a, long long p) {
    if (p == 0)
        return matrixUnit(a.size());
    if (p & 1)
        return matrixMul(a, matrixPow(a, p - 1));
    return matrixPow(matrixMul(a, a), p / 2);
}
vvl matrixPowSum(const vvl &a, long long p) {
    int n = a.size();
    if (p == 0)
        return vvl(n, vl(n));
    if (p % 2 == 0)
        return matrixMul(matrixPowSum(a, p / 2), matrixAdd(matrixUnit(n), matrixPow(a, p / 2)));
    return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a));
}

void print(const vvl &a) {
	REP(i, a.size()) {
		REP(j, a[i].size()) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int n;
ll k, a[111];

int main() {
	cin >> n >> k;
	REP(i, n) {
		cin >> a[i];
	}

	vvl m(n, vl(n));
	REP(i, n) REP(j, n) {
		m[i][j] = __builtin_popcountll(a[i] ^ a[j]) % 3 == 0;
	}

	m = matrixPow(m, k - 1);
	ll ans = 0;
	REP(i, n) REP(j, n) {
		ans += m[i][j];
		ans %= MOD;
	}

	cout << ans << endl;
	
	return 0;
}
