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
#define MAXP 100100
int ntc, n, m, np, c[MAXN][MAXP], a[MAXN], s[MAXN];
int p[MAXP], ip[MAXP];

int main(){
	FOR(i, 1, 100000) {
		p[i] = i;
	}
	for (int i = 2; i * i <= 100000; i++) {
		if (p[i] == i) {
			for (int j = i * i; j <= 100000; j += i) {
				p[j] = i;
			}
		}
	}
	FOR(i, 2, 100000) {
		if (p[i] == i) {
			ip[i] = ++np;
		}
	}
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &m);
		FOR(i, 1, n) {
			FOR(j, 1, np) {
				c[i][j] = 0;
			}
			FOR(j, 1, m) {
				int x;
				scanf("%d", &x);
				while (x > 1) {
					c[i][ip[p[x]]]++;
					x /= p[x];
				}
			}
			// printf("i = %d:", i);
			// FOR(j, 1, 5) {
			// 	printf(" %d", c[i][j]);
			// }
			// printf("\n");
		}
		int ans1 = 0, ans2 = 0;
		FOR(iip, 1, np) {
			FOR(i, 1, n) {
				a[i] = c[i][iip];
			}
			sort(a+1, a+n+1);
			FOR(i, 1, n) {
				s[i] = s[i-1] + a[i];
			}
			// max
			if (a[n] > s[n-1]) {
				ans2 += s[n-1];
			}
			else {
				ans2 += s[n] / 2;
			}
			// min
			if (n == 1) {
				// + 0
			}
			else if (n == 2) {
				ans1 += a[1];
			}
			else {
				if (a[n-1] > s[n-2]) {
					ans1 += a[n-1];
				}
				else {
					ans1 += (s[n-1]+1) / 2;
				}
			}
			// if (iip <= 5) {
			// 	printf(" %d: %d %d\n", iip, ans1, ans2);
			// }
		}
		printf("Case #%d: %d %d\n", itc, ans1, ans2);
	}
	
	return 0;
}
