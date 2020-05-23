/* DELAPAN.3gp */
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

#define MOD 1000000007LL
#define MAXN 10000005

int ntc, n, q;
int snow[MAXN];
int a, b, isSnow;

int main(){
    scanf("%d", &ntc);

    FOR(itc, 1, ntc) {
        fprintf(stderr, "TC %d\n", itc);
        scanf("%d%d", &n, &q);
        REP(i, n - 1) {
            int dummy;
            scanf("%d%d", &dummy, &dummy);
        }

        REP(i, n) {
            snow[i] = 0;
        }

        ll totalAns = 0;
        vector<int> anss;
        REP(iq, q) {
            int ans = 0;
            scanf("%d%d%d", &a, &b, &isSnow);
            int dir = a < b ? +1 : -1;
            for (int pos = a; pos != b; pos += dir) {
                int road = (dir > 0) ? pos : (pos - 1);
                ans += snow[road];
                snow[road] = 0;
                if (isSnow) {
                    for (int i = 1; i <= n; ++i) {
                        snow[i]++;
                    }
                }
            }
            // for (int i = 1; i < n; ++i) {
            //     printf("%d ", snow[i]);
            // }
            // putchar('\n');
            anss.PB(ans);
            totalAns += (ll)(iq + 1) * ans % MOD;
        }
        printf("%lld\n", totalAns);
        FORIT(it, anss) {
            printf("%d ", *it);
        }
        putchar('\n');
        fprintf(stderr, "TC %d DONE: %lld\n", itc, totalAns);
    }
    
    return 0;
}
