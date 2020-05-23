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

#define MAXN 1010
#define MAXK 111
#define MAXX 100100

int n, k[MAXN], a[MAXN][MAXK], bit[MAXX], _idx;

int query(int k) {
	int ret = 0;
	for (int x = k; x > 0; x -= (x & -x)) {
		MX(ret, bit[x]);
	}
	return ret;
}
void update(int k, int v) {
	for (int x = k; x <= _idx; x += (x & -x)) {
		MX(bit[x], v);
	}
}

int main(){
	scanf("%d", &n);
	set<int> val;
	REP(i, n) {
		scanf("%d", &k[i]);
		REP(j, k[i]) {
			scanf("%d", &a[i][j]);
			if (!EXIST(a[i][j], val)) {
				val.insert(a[i][j]);
			}
		}
		sort(a[i], a[i] + k[i]);
	}
	map<int, int> idx;
	_idx = 0;
	FORIT(it, val) {
		idx[*it] = ++_idx;
	}
	REP(i, n) {
		REP(j, k[i]) {
			int id = idx[a[i][j]];
			int hu = query(id - 1);
			update(id, hu + 1);
		}
	}
	printf("%d\n", query(_idx));
	
	return 0;
}
