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
#include <complex>
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

/* -------------- end of DELAPAN.3gp's template -------------- */

/** computes a**b % mod **/
/* complexity: O(log(b)) */
ll power(ll a, ll b, ll mod){
	ll ret = 1;
	for (; b > 0; b >>= 1LL){
		if (b & 1LL) ret = (ret * a) % mod;
		a = (a * a) % mod;
	}
	return ret;
}

/** Sieve Eratosthenes | computes primes up to n **/
/* complexity: O(n log(log(n))) */
vector<int> primeTable(int n){
	int p[n+5];
	for (int i = 2; i <= n; ++i) p[i] = 1;
	for (int i = 2; i*i <= n; ++i){
		if (p[i]){
			for (int j = i*i; j <= n; j += i){
				p[j] = 0;
			}
		}
	}
	vector<int> ret;
	for (int i = 2; i <= n; ++i){
		if (p[i]) ret.push_back(i);
	}
	return ret;
}

/** Extended Euclid | returns <x,y> where ax + by = gcd(a,b) **/
/* complexity: O(min(log(a),log(b))) */
pair<ll,ll> extendedEuclid(ll a, ll b){
	ll x = 0, y = 1, lastx = 1, lasty = 0;
	while (b != 0){
		ll quotient = a / b;
		/* (a, b) = (b, a mod b) */
		ll temp = a;
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
ll multiplicativeInverse (ll a, ll m){
	/* if m is prime, return power(a,m-2,m); */
	pair<ll,ll> xy = extendedEuclid(a, m);
	return ((xy.first % m) + m) % m;
}

/** Lagrange Polynomial Interpolation **/
/* complexity: O(n^2) */

ll n, ca, a, cb, b, d, x, y, k;

int main(){
	while (cin >> n && n){
		cin >> ca >> a >> cb >> b;
		d = __gcd(a,b);
		if (n % d != 0){
			puts("failed");
			continue;
		}
		pair<ll,ll> xy = extendedEuclid(a,b);
		x = xy.A, y = xy.B;
		x *= n / d, y *= n / d;
		/* x + k* (b/d), y - k* (a/d) */
		if (x < 0) {
			k = (-x + (b/d) - 1) / (b/d);
			x += k * (b/d);
			y -= k * (a/d);
		}
		else if (y < 0) {
			k = (-y + (a/d) - 1) / (a/d);
			x -= k * (b/d);
			y += k * (a/d);
		}
		if (x < 0 || y < 0){
			puts("failed");
			continue;
		}
		k = x / (b/d);
		x -= k * (b/d);
		y += k * (a/d);
		pair<ll,ll> ans = MP(x,y);
		k = y / (a/d);
		x += k * (b/d);
		y -= k * (a/d);
		if (ca * x + cb * y < ca * ans.A + cb * ans.B) ans = MP(x,y);
		cout << ans.A << " " << ans.B << endl;
	}
	
	return 0;
}
