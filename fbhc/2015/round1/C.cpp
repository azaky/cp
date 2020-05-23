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
	freopen((s + ".txt").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 2200
#define MOD 1000000007
int ntc, a, b, _b, memo[MAXN][MAXN], dp[MAXN][MAXN];

int calcStressfree(int a, int b) {
	// printf("stressfree(%d, %d)\n", a, b);
	if (a == 0 && b == 0) return 1;
	if (a <= b || a < 0 || b < 0) return 0;
	if (memo[a][b]) return dp[a][b];
	memo[a][b] = 1;
	int ret = 0;
	// I score
	ret += calcStressfree(a-1, b);
	// Op score
	ret += calcStressfree(a, b-1);
	return dp[a][b] = ret % MOD;
}

int calcStressful(int a, int b) {
	// printf("stressful(%d, %d)\n", a, b);
	if (a > b && b != _b || a < 0 || b < 0) return 0;
	if (b == 0 && a == 0) return 1;
	if (memo[a][b]) return dp[a][b];
	memo[a][b] = 1;
	int ret = 0;
	// I score
	ret += calcStressful(a-1, b);
	// Op score
	ret += calcStressful(a, b-1);
	return dp[a][b] = ret % MOD;
}

int main() {
	OPEN("winning_at_sports");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d-%d", &a, &b);
		// printf("a = %d, b = %d\n", a, b);
		RESET(memo, 0);
		int ansStressfree = calcStressfree(a, b);
		RESET(memo, 0);
		_b = b;
		int ansStressful = calcStressful(a, b);
		printf("Case #%d: %d %d\n", itc, ansStressfree, ansStressful);
	}

	return 0;
}