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

/** Extended Euclid | returns <x,y> where ax + by = gcd(a,b) **/
/* complexity: O(min(log(a),log(b))) */
pair<int,int> extendedEuclid(int a, int b){
	int x = 0, y = 1, lastx = 1, lasty = 0;
	// maintain two equations:
	// a_i = a * lastx + b * lasty
	// b_i = a * x     + b * y
	while (b != 0){
		int quotient = a / b;
		/* (a, b) = (b, a mod b) */
		int temp = a;
		a = b;
		b = temp % b;
		/* (x, lastx) = (lastx - quotient*x, x) */
		temp = x;
		x = lastx - quotient * x;
		lastx = temp;
		/* (y, lasty) = (lasty - quotient*y, y) */
		temp = y;
		y = lasty - quotient * y;
		lasty = temp;
	}
	return make_pair(lastx, lasty);
}

/** Multiplicative Inverse | returns a^-1 mod m **/
int multiplicativeInverse (int a, int m){
	/* if m is prime, return power(a,m-2,m); */
	pair<int,int> xy = extendedEuclid(a, m);
	return ((xy.first % m) + m) % m;
}

#define MAXW 1100
#define MAXN 111
#define MOD 10007
int ntc, n, w, c[MAXN], a[MAXN], nn, dp[MAXW][MAXN][MAXN], dpp[MAXW][MAXN][MAXN], odp[MAXW][MAXN][MAXN], odpp[MAXW][MAXN][MAXN];
int f[MAXN], finv[MAXN];

int main(){
	f[0] = finv[0] = 1;
	FOR(i, 1, 100) {
		f[i] = (f[i-1] * i) % MOD;
		finv[i] = multiplicativeInverse(f[i], MOD);
	}
	
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &w);
		FOR(i, 1, w) {
			c[i] = 0;
		}
		REP(i, n) {
			scanf("%d", &a[i]);
			c[a[i]]++;
		}
		sort(a, a+n);
		nn = unique(a, a+n) - a;
		reverse(a, a+nn);
		
		REP(i, nn) {
			printf("%d ", a[i]);
		} printf("\n");
		
		RESET(dp, 0);
		RESET(dpp, 0);
		dp[0][0][0] = dpp[0][0][0] = 1;
		
		FOR(ww, 1, w) FOR(i, 1, nn) {
			int neww = c[a[i]]*a[i];
			FORD(j, c[a[i]], 0) {
				if (ww >= neww) {
					FOR(k, j, n) FOR(l, 1, i-1) {
						if (dpp[ww-neww][k-j][l]) {
							if (j == c[a[i]]) {
								dpp[ww][k][l] = 1;
								dp[ww][k][l] += finv[j]*dp[ww-neww][k-j][l];
								dp[ww][k][l] %= MOD;
							}
							else {
								dpp[ww][k][i] = 1;
								dp[ww][k][i] += finv[j]*dp[ww-neww][k-j][l];
								dp[ww][k][i] %= MOD;
							}
						}
					}
				}
				neww -= a[i];
			}
		}
		int ans = 0;
		FOR(ww, 1, w) FOR(k, 1, n) FOR(l, 0, nn) {
			// kalo masih muat
			if (l && w-ww <= a[l]) continue;
			
			printf("ww = %d, k = %d, l = %d\nans = %d\n", ww, k, l, (f[k] * dp[ww][k][l]) % MOD);
			
			ans += (f[k] * dp[ww][k][l]) % MOD;
			ans %= MOD;
		}
		printf("Case %d: %d\n", itc, ans);
	}
	
	return 0;
}
