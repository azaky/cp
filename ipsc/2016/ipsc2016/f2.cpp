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

#define MAXN 200100

int ntc, k;
ll n, pos[MAXN];

char ans[MAXN << 4];
int nans;

int main(){
    scanf("%d", &ntc);

    FOR(itc, 1, ntc) {
        fprintf(stderr, "tc %d\n", itc);
        scanf("%lld%lld%d", &n, &pos[0], &k);
        ll n2 = n + n;
        REP(i, k) {
            scanf("%lld", &pos[i + 1]);
        }
        nans = 0;
        REP(i, k) {
            ll now = pos[i], target = pos[i + 1];
            if (now == target) {
                continue;
            }

            ll uncertainty = 0;
            int length = 0;
            while (++length) {
                now += now;
                now %= n2;
                ll distance = now - target;
                while (distance < 0) {
                    distance += n2;
                }
                uncertainty *= 2;
                uncertainty += 1;
                if (distance <= uncertainty) {
                    now = pos[i];
                    // fprintf(stderr, "walking (%lld .. %lld)\n", pos[i], pos[i + 1]);
                    REPD(j, length) {
                        bool top = ((1LL << (ll)j) & distance) > 0;
                        bool overflow = now > n;
                        if (top ^ overflow) {
                            ans[nans++] = 'R';
                        } else{
                            ans[nans++] = 'L';
                        }
                        now = now * 2;
                        if (top) {
                            now -= 1;
                        }
                        while (now > n2) {
                            now -= n2;
                        }
                        // fprintf(stderr, "%lld\n", now);
                    }
                    ans[nans] = 0;
                    assert(now == target);
                    // printf("%s\n", ans);
                    break;
                }
            }
        }
        ans[nans] = 0;
        printf("%d:%s\n", nans, ans);
    }
    
    return 0;
}
