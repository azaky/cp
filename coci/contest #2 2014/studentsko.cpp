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

#define MAXN 5100
int n, k, a[MAXN], v[MAXN], dp[MAXN], bit[MAXN], ans;

void update(int k, int v) {
	for (int x = k; x <= n; x += x & -x) {
		MX(bit[x], v);
	}
}
int query(int k) {
	int ret = 0;
	for (int x = k; x > 0; x -= x & -x) {
		MX(ret, bit[x]);
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &k);
	FOR(i, 1, n) {
		scanf("%d", &a[i]);
		v[i] = a[i];
	}
	sort(v+1, v+n+1);
	FOR(i, 1, n) {
		a[i] = lower_bound(v+1, v+n+1, a[i]) - v;
		a[i] = (a[i] + k-1) / k;
	}
	ans = 0;
	FOR(i, 1, n) {
		int temp = query(a[i]) + 1;
		update(a[i], temp);
		MX(ans, temp);
	}
	printf("%d\n", n - ans);
	
	return 0;
}
