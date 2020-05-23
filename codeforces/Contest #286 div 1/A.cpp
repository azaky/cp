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

#define MAXN 30300
int n, d, gem[MAXN];
map<int,int> dp[MAXN];
int hit = 0;

int calc(int p, int d) {
	// hit++;
	// if (hit % 10000 == 0) printf("hit = %d\n", hit);
	if (p > 30000 || d <= 0) return 0;
	if (dp[p].find(d) != dp[p].end()) return dp[p][d];
	int ret = gem[p];
	if (d == 4) {
		ret += max(calc(p + 3, 3), calc(p + 4, 4));
	}
	else if (d == 3) {
		ret += calc(p + 2, 2);
	}
	else if (d <= 2) {
		ret += calc(p + 1, 1);
	}
	else {
		ret += max(max(calc(p + d-1, d-1), calc(p + d, d)), calc(p + d+1, d+1));
	}
	return dp[p][d] = ret;
}

int main() {
	scanf("%d%d", &n, &d);
	REP(i, n) {
		int x;
		scanf("%d", &x);
		gem[x]++;
	}
	printf("%d\n", calc(d, d));

	return 0;
}