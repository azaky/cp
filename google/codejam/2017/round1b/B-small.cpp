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

int ntc, n, r, o, y, g, b, v;
char ans[1111];

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d%d%d%d%d", &n, &r, &o, &y, &g, &b, &v);
		if (r * 2 > n || y * 2 > n || b * 2 > n) {
			printf("Case #%d: IMPOSSIBLE\n", itc);
			continue;
		}

		vector<pair<int, char> > a;
		a.PB(MP(r, 'R'));
		a.PB(MP(y, 'Y'));
		a.PB(MP(b, 'B'));
		sort(ALL(a));
		reverse(ALL(a));

		int p = 0;
		RESET(ans, 0);
		FOR(i, 1, a[0].A) {
			ans[p] = a[0].B;
			p += 2;
			p %= n;
		}
		FOR(i, 1, a[1].A) {
			if (ans[p]) {
				p++;
				p %= n;
			}
			ans[p] = a[1].B;
			p += 2;
			p %= n;
		}
		REP(i, n) {
			if (!ans[i]) {
				ans[i] = a[2].B;
			}
		}
		printf("Case #%d: %s\n", itc, ans);
	}
	
	return 0;
}