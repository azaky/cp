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

#define MAXN 1100100

int ntc, n, costl[MAXN], costr[MAXN];;
bool x[MAXN];
char sa[MAXN], sb[MAXN];

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		scanf("%s%s", sa, sb);
		int m = 0;
		int last = -1;
		REP(i, n) {
			if (i == n - 1 || sb[i] != sb[i + 1]) {
				bool match = true;
				FOR(j, last + 1, i) {
					if (sa[j] != sb[j]) {
						match = false;
						break;
					}
				}
				last = i;
				x[++m] = match;
			}
		}
		costl[0] = 0;
		FOR(i, 1, m) {
			if (x[i]) {
				costl[i] = costl[i - 1];
			} else {
				costl[i] = i;
			}
		}
		costr[m + 1] = 0;
		FORD(i, m, 1) {
			if (x[i]) {
				costr[i] = costr[i + 1];
			} else {
				costr[i] = m - i + 1;
			}
		}
		int ans = m;
		FOR(i, 0, m) {
			MN(ans, max(costl[i], costr[i + 1]));
		}
		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}