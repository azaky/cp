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

#ifdef __WIN32 
    #define gc getchar
    #define pc putchar
#else
    #define gc getchar_unlocked
    #define pc putchar_unlocked
#endif
#define MAX_DIGIT_int 10
#define MAX_DIGIT_ll 19
#define FS_INT_TYPE(type) \
    void fsi(type &inp) { \
        register char c = gc(), prev = '+'; \
        for (; !isdigit(c); c = gc()) prev = c; \
        inp = 0; \
        for (; isdigit(c); c = gc()) { \
            inp = (inp << 3) + (inp << 1) + (c - '0'); \
        } \
        if (prev == '-') \
            inp = -inp; \
    } \
    void fso(type val) { \
        if (!val) { \
            pc('0'); \
            return; \
        } \
        char buff[MAX_DIGIT_ ##type]; \
        if (val < 0) { \
            pc('-'); \
            val = -val; \
        } \
        register int i; \
        for (i = 0; val; ++i, val /= 10) { \
            buff[i] = (val % 10) + '0'; \
        } \
        while (i--) { \
            pc(buff[i]); \
        } \
    }
FS_INT_TYPE(int)
FS_INT_TYPE(ll)

void fsi(char *str) {
    register char c = gc();
    for (; c <= 32; c = gc());
    register int idx = 0;
    for (; c > 32; c = gc()) {
        str[idx++] = c;
    }
    str[idx] = 0;
}

/* -------------- end of fastio's template -------------- */

// #define MAX 0
// #define MIN 1

#define MAXN 2200

int ntc, n, a[MAXN];
// int dpaggl[MAXN][2], dpaggr[MAXN][2], dpmax, dpmin;
int dpagglmin[MAXN], dpaggrmin[MAXN], dpagglmax[MAXN], dpaggrmax[MAXN], dpmax, dpmin;

int main(){
	fsi(ntc);
	// scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		// scanf("%d", &n);
		// FOR(i, 1, n) scanf("%d", &a[i]);
		fsi(n);
		FOR(i, 1, n) fsi(a[i]);

		FOR(i, 1, n) {
			dpagglmax[i] = dpaggrmax[i] = dpagglmin[i] = dpaggrmin[i] = a[i];
		}
		int ans = a[1];
		FOR(len, 2, n) {
			for (int l = 1, r = len; r <= n; ++l, ++r) {
				dpmax = max(dpagglmin[l], dpaggrmin[r]);
				dpmin = min(dpagglmax[l], dpaggrmax[r]);
				if (dpagglmin[l] < dpmin) {
					dpagglmin[l] = dpmin;
				}
				if (dpaggrmin[r] < dpmin) {
					dpaggrmin[r] = dpmin;
				}
				if (dpagglmax[l] > dpmax) {
					dpagglmax[l] = dpmax;
				}
				if (dpaggrmax[r] > dpmax) {
					dpaggrmax[r] = dpmax;
				}
				// printf("dp[%d][%d][MAX] = %d\n", l, r, dpmax);
				// printf("dp[%d][%d][MIN] = %d\n", l, r, dpmin);
				if (len == n) {
					ans = dpmin;
				}
			}
			// FOR(i, 1, n - len + 1) {
			// 	dp[i][i + len - 1][MAX] = max(dpaggl[i][MIN], dpaggr[i + len - 1][MIN]);
			// 	dp[i][i + len - 1][MIN] = min(dpaggl[i][MAX], dpaggr[i + len - 1][MAX]);
			// }
			// FOR(i, 1, n - len + 1) {
			// 	MX(dpaggl[i][MIN], dp[i][i + len - 1][MIN]);
			// 	MX(dpaggr[i + len - 1][MIN], dp[i][i + len - 1][MIN]);
			// 	MN(dpaggl[i][MAX], dp[i][i + len - 1][MAX]);
			// 	MN(dpaggr[i + len - 1][MAX], dp[i][i + len - 1][MAX]);
			// }
			// FOR(i, 1, n - len + 1) {
			// 	printf("dp[%d][%d][MAX] = %d\n", i, i + len - 1, dp[i][i + len - 1][MAX]);
			// 	printf("dp[%d][%d][MIN] = %d\n", i, i + len - 1, dp[i][i + len - 1][MIN]);
			// }
		}
		printf("Case #%d: %d\n", itc, ans);
	}
	
	return 0;
}