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
int ntc;
ll n, mx, x, y;
ll a[100100], three[33];

ll calc(ll m, ll x, ll multiplier = 1, ll front = 0, ll last = 0, ll last2 = 0) {
    if (x < 0) {
        return 0;
    }

    // printf("m = %lld\nx = %lld\nmultiplier = %lld\nfront = %lld, last = %lld, last2 = %lld\n", m, x, multiplier, front, last, last2);

    if (m == 0) {
        ll ans = 0;
        REP(i, x + 1) {
            ans += a[i];
            ans %= MOD;
        }
        ans *= multiplier;
        ans %= MOD;
        ans -= a[0] * front;
        ans %= MOD; ans += MOD; ans %= MOD;
        ans -= a[x] * last;
        ans %= MOD; ans += MOD; ans %= MOD;
        if (x > 0) {
            ans -= a[x - 1] * last2;
            ans %= MOD; ans += MOD; ans %= MOD;
        }
        return ans;
    }

    if (x % 2LL == 0) {
        return calc(m - 1, x / 2LL, (multiplier * 3LL) % MOD, (front + multiplier + MOD) % MOD, (last + last2 + multiplier + MOD) % MOD, last2);
    } else {
        return calc(m - 1, (x + 1) / 2LL, (multiplier * 3LL) % MOD, (front + multiplier + MOD) % MOD, (last + multiplier * 2LL + MOD) % MOD, (last + last2 + MOD) % MOD);
    }
}

int main(){
    three[0] = 1;
    FOR(i, 1, 30) {
        three[i] = three[i - 1] * 3LL;
        three[i] %= MOD;
    }
    scanf("%d", &ntc);
    FOR(itc, 1, ntc) {
        scanf("%lld%lld%lld%lld", &n, &mx, &x, &y);
        --x, --y;
        REP(i, n) {
            scanf("%lld", &a[i]);
        }

        printf("%lld\n", (calc(mx, y) - calc(mx, x - 1) + MOD) % MOD);
    }
    
    return 0;
}
