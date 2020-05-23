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

#define MAXN 100100

int n, m, d[MAXN], a[MAXN], mark[MAXN], last[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) scanf("%d", &d[i]);
	FOR(i, 1, m) scanf("%d", &a[i]);

	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (l + r) / 2;
		bool possible = true;
		RESET(last, -1);
		RESET(mark, 0);
		FOR(i, 1, mid) {
			if (d[i]) last[d[i]] = i;
		}
		int x = 0;
		FOR(i, 1, m) {
			if (last[i] == -1) {
				possible = false;
				goto fail;
			}
			mark[last[i]] = 1;
		}
		FOR(i, 1, mid) {
			if (!mark[i]) continue;
			x++;
			if (i - x < a[d[i]]) {
				possible = false;
				goto fail;
			} else {
				x += a[d[i]];
			}
		}
fail:
		if (possible) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if (l > n) {
		puts("-1");
	} else {
		printf("%d\n", l);
	}
	
	return 0;
}