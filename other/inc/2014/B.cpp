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

#define MAXN 111
#define INF 1100100
int ntc, n, m, q, c[MAXN][MAXN];

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &m);
		FOR(i, 1, n) {
			c[i][i] = 0;
			FOR(j, 1, n) {
				c[i][j] = INF;
			}
		}
		REP(i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			MN(c[x][y], 0);
			MN(c[y][x], 1);
		}
		FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) {
			MN(c[i][j], c[i][k] + c[k][j]);
		}
		printf("Case #%d:\n", itc);
		scanf("%d", &q);
		REP(i, q) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (c[x][y] == INF) {
				puts("-1");
			}
			else {
				printf("%d\n", c[x][y]);
			}
		}
	}
	
	return 0;
}
