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

typedef pair<ll,ll> pll;

#define MAXN 100100
#define MOD 1000000007LL

int n, p[MAXN], c[MAXN];
vector<int> child[MAXN];

ll power(ll a, ll b) {
	if (b == 0) return 1;
	ll temp = power(a, b / 2LL);
	temp *= temp;
	temp %= MOD;
	if (b & 1) {
		temp *= a;
		temp %= MOD;
	}
	return temp;
}

ll inv(ll x) {
	return power(x, MOD-2LL);
}

pll dfs(int v) {
	vector<pll> t;
	int czero = 0;
	FORIT(it, child[v]) {
		pll temp = dfs(*it);
		if (temp.A != 0 || temp.B != 0) {
			t.PB(temp);
			if ((temp.A + temp.B) % MOD == 0) czero++;
		}
	}
	if (t.empty()) {
		if (c[v] == 1) {
			return MP(0, 1);
		}
		else {
			return MP(0, 0);
		}
	}
	ll x = 1;
	ll xzero = 1;
	FORIT(it, t) {
		x *= (it->A + it->B);
		x %= MOD;
		if ((it->A + it->B) % MOD != 0) {
			xzero *= (it->A + it->B);
			xzero %= MOD;
		}
	}
	
	ll y = 0;
	FORIT(it, t) {
		ll ty = it->B;
		if (czero == 0) {
			ty *= x;
			ty %= MOD;
			ty *= inv(it->A + it->B);
			ty %= MOD;
		}
		else if (czero == 1) {
			if ((it->A + it->B) % MOD == 0) {
				ty *= xzero;
				ty %= MOD;
			}
			else {
				ty = 0;
			}
		}
		else {
			ty = 0;
		}
		y += ty;
		y %= MOD;
	}
	if (c[v] == 1) {
		y = x;
		x = 0;
	}
	return MP(x, y);
}

int main(){
	scanf("%d", &n);
	REP(i, n-1) {
		scanf("%d", &p[i+1]);
		child[p[i+1]].PB(i+1);
	}
	REP(i, n) {
		scanf("%d", &c[i]);
	}
	pll ans = dfs(0);
	cout << ans.B << endl;
	
	return 0;
}
