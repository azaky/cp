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

#define MAXN 200000
#define MAXV 10000000

int vis[MAXN], memo[MAXN];
int meml[MAXN], memr[MAXN];

int solve(int n, int a, int b, int c) {
	int ret = MAXV;
	int l, r;
	if (n == 1) return 0;
	if (vis[n]) return memo[n];
	for (int i = 0; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			int tmp = 0;
			if ((i > 0) && (i < n))
				MX(tmp, a + solve(i, a, b, c));
			if ((j-i > 0) && (j-i < n))
				MX(tmp, b + solve(j-i, a, b, c));
			if ((n-j > 0) && (n-j < n))
				MX(tmp, c + solve(n-j, a, b, c));
			if (tmp > 0) {
				if (ret >= tmp) {
					MN(ret, tmp);
					l = i;
					r = j;
				}
			}
		}
	}
	vis[n] = 1; memo[n] = ret;
	meml[n] = l;
	memr[n] = r;
	return ret;
}

#define MAXPRICE 1100100100
int ntc;
int a[3];
ll n;

int main() {
    scanf("%d", &ntc);
    
    REP(itc, ntc) {
        scanf("%lld%d%d%d", &n, &a[0], &a[1], &a[2]);
        sort(a, a + 3);

        if (n < 200) {
			RESET(vis, 0);
			printf("%d\n", solve(n, a[0], a[1], a[2]));
			continue;
        }
        
        vector<pair<int, pair<ll, ll> > > ranges;
        ranges.PB(MP(0, MP(0, 0)));
        ranges.PB(MP(0, MP(1, 1)));
        ranges.PB(MP(a[1], MP(2, 2)));

        ll last = 3;
        ll p[3];
        p[0] = 1;
        p[1] = 1;
        p[2] = 0;
        while (last < n) {
        	// printf("last = %d\n", last);
        	// huba huba humbala
        	int best = MAXPRICE;
        	int iBest = -1;
        	for (int i = 0; i < 3; ++i) {
        		if (p[i] + 1 < SZ(ranges)) {
        			p[i]++;
        			int maxPrice = 0;
        			for (int j = 0; j < 3; ++j) {
        				if (p[j] > 0) {
	        				MX(maxPrice, a[j] + ranges[p[j]].A);
        				}
        			}
        			if (maxPrice < best && p[1] > 0) {
        				best = maxPrice;
        				iBest = i;
        			}
        			p[i]--;
        		}
        	}
        	p[iBest]++;
        	int maxPrice = 0;
        	ll end = 0;
			for (int j = 0; j < 3; ++j) {
				if (p[j] > 0) {
					MX(maxPrice, a[j] + ranges[p[j]].A);
					end += ranges[p[j]].B.B;
				}
			}
			// printf("iBest = %d\n", iBest);
			// printf("maxPrice = %d, end = %lld\n", maxPrice, end);
			// for (int i = 0; i < 3; ++i) {
			// 	printf("%lld ", p[i]);
			// } puts("");
        	if (maxPrice == ranges.back().A) {
        		ranges.back().B.B = end;
        	} else {
        		ranges.PB(MP(maxPrice, MP(last + 1, end)));
        	}
        	last = end;
        }
        printf("%d\n", ranges.back().A);
    }

	return 0;
}
