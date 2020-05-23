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

#define MAXN 200200
#define OFFSET 45

int n, a[MAXN];
int dp[MAXN][100], len[MAXN][100];

int main(){
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d", &a[i]);
	}

	RESET(len, -1);

	FOR(i, 1, n) {
		dp[i][a[i] + OFFSET] = 0;
		len[i][a[i] + OFFSET] = 1;

		FOR(j, -40, a[i] - 1) {
			if (len[i - 1][j + OFFSET] == -1) continue;
			if (dp[i - 1][j + OFFSET] > dp[i][a[i] + OFFSET]) {
				dp[i][a[i] + OFFSET] = dp[i - 1][j + OFFSET];
				len[i][a[i] + OFFSET] = 1 + len[i - 1][j + OFFSET];
			} else if (dp[i - 1][j + OFFSET] == dp[i][a[i] + OFFSET]) {
				MN(len[i][a[i] + OFFSET], 1 + len[i - 1][j + OFFSET]);
			}
		}

		FOR(j, -40, 40) {
			if (len[i - 1][j + OFFSET] == -1) continue;
			int tmp = dp[i - 1][j + OFFSET] + a[i];
			if (len[i][j + OFFSET] == -1) {
				dp[i][j + OFFSET] = tmp;
				len[i][j + OFFSET] = len[i - 1][j + OFFSET] + 1;
			} else if (tmp > dp[i][j + OFFSET]) {
				dp[i][j + OFFSET] = tmp;
				len[i][j + OFFSET] = len[i - 1][j + OFFSET] + 1;
			} else if (tmp == dp[i][j + OFFSET] && len[i][j + OFFSET] > len[i - 1][j + OFFSET] + 1) {
				dp[i][j + OFFSET] = tmp;
				len[i][j + OFFSET] = len[i - 1][j + OFFSET] + 1;
			}
		}
	}

	int ans = -1, minlen = n, cot = 0;
	FOR(i, 1, n) FOR(j, -40, 40) {
		if (dp[i][j + OFFSET] > ans) {
			ans = dp[i][j + OFFSET];
			minlen = len[i][j + OFFSET];
			cot = 1;
		} else if (dp[i][j + OFFSET] == ans) {
			if (len[i][j + OFFSET] < minlen) {
				minlen = len[i][j + OFFSET];
				cot = 1;
			} else if (len[i][j + OFFSET] == minlen) {
				cot++;
			}
		}
	}

	printf("%d %d\n", ans, cot);
	
	return 0;
}