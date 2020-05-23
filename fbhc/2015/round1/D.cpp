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

#define MAXN 200200
#define MAXK 20
#define INF 0x3FFFFFFF

int ntc, n, p[MAXN], dp[MAXN][MAXK+1], maxk, memo[MAXN][MAXK+1];
vector<int> child[MAXN];

int calc(int v, int k) {
	if (memo[v][k]) return dp[v][k];
	memo[v][k] = 1;
	dp[v][k] = k;
	FORIT(it, child[v]) {
		int temp = INF;
		FOR(kk, 1, maxk) {
			if (kk == k) continue;
			MN(temp, calc(*it, kk));
		}
		dp[v][k] += temp;
	}
	return dp[v][k];
}

int main() {
	OPEN("corporate_gifting_sample");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		fprintf(stderr, "halo %d\n", itc);
		scanf("%d", &n);
		FOR(i, 1, n) {
			child[i].clear();
		}
		FOR(i, 1, n) {
			scanf("%d", &p[i]);
			child[p[i]].PB(i);
		}
		// fprintf(stderr, "halo");
		int ans = INF;
		for (maxk = 3; maxk < MAXK; ++maxk) {
		// fprintf(stderr, "halo");
			RESET(memo, 0);
			int temp = INF;
			FOR(i, 1, maxk) {
				MN(temp, calc(1, i));
			}
			if (maxk > 3 && ans > temp) {
				fprintf(stderr, "case %d, maxk = %d\n", itc, maxk);
			}
			// if (maxk > 3) assert(ans == temp);
			MN(ans, temp);
		}
		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}