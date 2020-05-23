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

ll sum[100], even[100];

ll geteven(ll n) {
	if (n == 0) return 0;
	
	ll p = 1LL;
	int k = 0;
	while (p <= n) {
		p *= 5LL;
		k++;
	}
	p /= 5LL;
	k--;
	
	ll temp = geteven(n - p);
	if (sum[k] % 2LL == 1LL) {
		temp = n-p - temp;
	}
	
	//printf("geteven(%I64d) = %I64d\n", n, temp + even[k]);
	
	return temp + even[k];
}

ll getsum(ll n) {
	if (n == 0) return 0;
	return n + getsum(n / 5LL);
}

int main(){
	// precalc
	ll p = 1LL;
	int k = 1;
	even[0] = 0;
	sum[0] = 1;
	while (true) {
		sum[k] = 0;
		even[k] = 0;
		FOR(i, 1, 5) {
			if (sum[k] % 2LL == 0) {
				even[k] += even[k-1];
			}
			else {
				even[k] += p - even[k-1];
			}
			sum[k] += sum[k-1];
		}
		sum[k]++;
		if (sum[k] % 2LL == 0) {
			even[k]++;
		}
		else {
			even[k]--;
		}
		
		k++;
		p *= 5LL;
		if (p > 1000000000000000000LL) break;
	}
	
	ll n;
	while (true) {
		cin >> n;
		if (n == -1LL) break;
		
		ll ans = 0;
		ll low = n;
		while ((low + 1LL) % 5LL != 0) {
			ll temp = getsum(low / 5LL);
			if (temp % 2LL == 0) ans++;
			low--;
		}
		ans += 5LL * geteven(low / 5LL);
		if (low > 4LL) ans += 5LL;
		
		cout << ans << endl;
	}
	
	return 0;
}
