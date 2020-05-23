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
int na, nb, a[MAXN], b[MAXN];
ll sa[MAXN], sb[MAXN];

int main(){
	scanf("%d%d", &na, &nb);
	sa[0] = sb[0] = 0;
	set<int> values;
	FOR(i, 1, na) {
		scanf("%d", &a[i]);
		values.insert(a[i]);
	}
	FOR(i, 1, nb) {
		scanf("%d", &b[i]);
		values.insert(b[i]);
	}
	sort(a + 1, a + na + 1);
	sort(b + 1, b + nb + 1);
	FOR(i, 1, na) {
		sa[i] = sa[i-1] + (ll)a[i];
	}
	FOR(i, 1, nb) {
		sb[i] = sb[i-1] + (ll)b[i];
	}
	a[0] = b[0] = -1;
	a[na+1] = b[nb+1] = 0x3FFFFFFF;
	ll ans = 1000000000000000LL;
	int ia = 0, ib = 0;
	FORIT(it, values) {
		int v = *it;
		while (a[ia] < v && ia <= na) ia++;
		ia--;
		while (b[ib] < v) ib++;
		
		ll xa = ia < 1 ? 0 : (ll)v * (ll)ia - sa[ia];
		ll xb = ib > nb ? 0 : sb[nb] - sb[ib-1] - (ll)v * (ll)(nb - ib + 1);
		if (xa + xb < ans) {
			ans = xa + xb;
		}

		//printf("V = %d, %d %d %I64d\n", v, ia, ib, xa + xb);
	}
	cout << ans << endl;
	
	return 0;
}
