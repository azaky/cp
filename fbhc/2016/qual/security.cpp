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

#define MAXN 1100

int ntc, n;
char s[2][MAXN], visited[2][MAXN];

void fill(int i, int j) {
	if (j < 0 || j >= n || visited[i][j] || s[i][j] == 'X') return;
	visited[i][j] = 1;
	fill(i, j - 1);
	fill(i, j + 1);
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		scanf("%s%s", s[0], s[1]);

		RESET(visited, 0);
		int ans = 0;

		// first phase: singletons
		REP(i, 2) REP(j, n) {
			if (!visited[i][j] && s[i][j] == '.' && (j == 0 || s[i][j - 1] == 'X') && (j == n - 1 || s[i][j + 1] == 'X')) {
				ans++;
				fill(i, j);
				fill(1 - i, j);
			}
		}
		// second phase: fill the rest
		REP(i, 2) REP(j, n) {
			if (!visited[i][j] && s[i][j] == '.') {
				ans++;
				fill(i, j);
			}
		}
		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}