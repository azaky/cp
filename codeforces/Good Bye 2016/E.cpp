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

int n, q, a, b;
char s[MAXN], prevs[MAXN][10], nexts[MAXN][10], sum[MAXN];

int main(){
	scanf("%d%d", &n, &q);
	scanf("%s", s);
	REP(i, 10) {
		prevs[0][i] = -1;
		nexts[n + 1][i] = -1;
	}
	FOR(i, 1, n) {
		sum[i] = sum[i - 1];
		if (s[i - 1] == '6') {
			sum[i]++;
		}
		REP(j, 10) {
			prevs[i][j] = prevs[i - 1][j];
		}
		prevs[i][s[i - 1] - '0'] = i;
	}
	FORD(i, n, 1) {
		REP(j, 10) {
			nexts[i][j] = nexts[i + 1][j];
		}
		nexts[i][s[i - 1] - '0'] = i;
	}

	// FOR(i, 1, n) {
	// 	printf("%d %d\n", nexts[i][6], prevs[i][6]);
	// }

	REP(iq, q) {
		scanf("%d%d", &a, &b);
		int i2 = nexts[a][2];
		int i0 = i2 == -1 ? -1 : nexts[i2][0];
		int i7 = prevs[b][7];
		int i1 = i7 == -1 ? -1 : prevs[i7][1];
		// printf("%d %d %d %d\n", i2, i0, i1, i7);
		if (i2 == -1 || i0 == -1 || i1 == -1 || i7 == -1 || i0 > i1) {
			puts("-1");
			continue;
		} else {
			printf("%d\n", sum[b] - sum[i1]);
		}
	}
	
	return 0;
}