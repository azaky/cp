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
int bit[MAXN], n, k, p, ans[MAXN];

void update(int k, int v) {
	for (int x = k; x < MAXN; x += (x & -x)) {
		bit[x] += v;
	}
}
int query(int k) {
	int sum = 0;
	for (int x = k; x > 0; x -= (x & -x)) {
		sum += bit[x];
	}
	return sum;
}

int main(){
	scanf("%d%d%d", &n, &k, &p);
	
	REP(i, n-k) {
		ans[i] = 1;
	}
	int now = 2;
	update(1, n-k);
	REP(i, k) {
		// check if now is possible
		int lighter = query(now - 1);
		if (lighter * 100 >= p * (n-k+i)) {
			ans[n-k+i] = now;
		}
		else {
			ans[n-k+i] = ++now;
		}
		update(now, 1);
	}
	ll total = 0;
	REP(i, n) {
		total += (ll)ans[i];
	}
	cout << total << endl;
	REP(i, n) {
		printf("%d", ans[i]);
		if (i < n-1) {
			printf(" ");
		}
		else {
			printf("\n");
		}
	}
	
	return 0;
}
