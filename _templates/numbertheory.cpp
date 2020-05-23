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
	// maintain two equations:
	// a_i = a * lastx + b * lasty
	// b_i = a * x     + b * y
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
class lagrangeInterpolation {
public:
	lagrangeInterpolation () : x_(0), y_(0) {}
	
	void addCoef (db x, db y){
		x_.push_back(x);
		y_.push_back(y);
	}
	
	db interpolate (db x){
		db value = 0;
		for (int i = 0; i < (int)x_.size(); ++i){
			db addum = y_[i];
			for (int j = 0; j < (int)x_.size(); ++j) if (i != j){
				addum *= (x - x_[j]);
				addum /= (x_[i] - x_[j]);
			}
			value += addum;
		}
		return value;
	}

	vector<db> x_, y_;
};

class modularInterpolation {
public:
	modularInterpolation (const ll &modu) : modu_(modu), x_(0), y_(0) {}
	
	void addCoef (ll x, ll y){
		x %= modu_;
		if (x < 0LL) x += modu_;
		x_.push_back(x);
		
		y %= modu_;
		if (y < 0LL) y += modu_;
		y_.push_back(y);
	}
	
	ll interpolate (ll x){
		x %= modu_;
		if (x < 0LL) x += modu_;
		
		for (int i = 0; i < (int)x_.size(); ++i) if (x_[i] == x) return y_[i];
		
		ll value = 0LL;
		for (int i = 0; i < (int)x_.size(); ++i){
			ll addum = y_[i];
			for (int j = 0; j < (int)x_.size(); ++j) if (j != i){
				ll delta1 = (x - x_[j] + modu_) % modu_;
				ll delta2 = (x_[i] - x_[j] + modu_) % modu_;
				addum = (addum * delta1) % modu_;
				addum = (addum * multiplicativeInverse(delta2, modu_)) % modu_;
			}
			value += addum;
			value %= modu_;
		}
		
		return value;
	}
	const ll modu_;
	vector<ll> x_, y_;
};

/* WARNING: no two x_[i] are the same */

/** Fast Fourier Transform **/
/* complexity: O(N log N) */
vector< complex<db> > iterativeDFT (const vector< complex<db> > &seq, int direction) {
	int n = SZ(seq);
	int bits = 0;
	int tmp_n = n;
	complex<db> *placeholder = new complex<db>[n];
	complex<db> *tmp = new complex<db>[n];
	
	while (tmp_n > 1){
		++bits;
		tmp_n /= 2;
	}
	
	REP(i,n){
		int res = 0;
		int tmp_i = i;
		REP(j,bits){
			if (tmp_i % 2) res += (1 << (bits-j-1));
			tmp_i /= 2;
		}
		placeholder[i] = seq[res];
	}
	
	for (int comp_size = 2; comp_size <= n; comp_size *= 2){
		for (int j = 0; j < n; j += comp_size){
			int n_mem = comp_size / 2;
			db w_mult_exp_i = 2. * acos(-1.) / (db)comp_size;
			if (!direction) w_mult_exp_i *= -1.;
			complex<db> w_mult (cos(w_mult_exp_i),sin(w_mult_exp_i));
			complex<db> w (1., 0.);
			for (int k = 0; k < comp_size; ++k){
				int idx = k % n_mem;
				tmp[k] = placeholder[j+idx] + w * placeholder[j+n_mem+idx];
				w = w * w_mult;
			}
			for (int k = 0; k < comp_size; ++k){
				placeholder[j+k] = tmp[k];
			}
		}
	}
	
	vector< complex<db> > result;
	for (int i = 0; i < n; ++i) result.PB(placeholder[i]);
	
	delete[] placeholder;
	delete[] tmp;
	return result;
}
vector<db> FFT(vector<db> a, vector<db> b) {
	if (SZ(a) == 0) a.PB(0.);
	if (SZ(b) == 0) b.PB(0.);
	int n_final_elements = SZ(a) + SZ(b) - 1;
	
	int actual_size = 1;
	while (actual_size < max(SZ(a), SZ(b))){
		actual_size *= 2;
	}
	actual_size *= 2;
	while (SZ(a) < actual_size) a.PB(0.);
	while (SZ(b) < actual_size) b.PB(0.);
	
	vector< complex<db> > dft_input_a, dft_input_b;
	REP(i,actual_size) {
		dft_input_a.PB(complex<db> (a[i], 0.));
		dft_input_b.PB(complex<db> (b[i], 0.));
	}
	
	dft_input_a = iterativeDFT (dft_input_a, 1);
	dft_input_b = iterativeDFT (dft_input_b, 1);
	REP(i,actual_size) {
		dft_input_a[i] = dft_input_a[i] * dft_input_b[i];
	}
	dft_input_a = iterativeDFT (dft_input_a, 0);
	
	vector<db> res;
	REP(i,n_final_elements) {
		res.PB(dft_input_a[i].real() / (db) actual_size);
	}
	return res;
}


int main(){
	int n; db x;
	vector<db> a, b;
	scanf("%d",&n);
	REP(i,n){
		scanf("%lf",&x);
		a.PB(x);
	}
	scanf("%d",&n);
	REP(i,n){
		scanf("%lf",&x);
		b.PB(x);
	}
	vector<db> res = FFT(a, b);
	REP(i,SZ(res)) printf("%g ",res[i]); puts("");
	
	return 0;
}
