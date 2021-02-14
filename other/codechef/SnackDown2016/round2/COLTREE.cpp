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

int n, k, ntc;
ll dp[555][555], comb[555][555];
vector<int> child[555], adj[555];

void dfs (int v) {
    if (child[v].empty()) {
        FOR(i, 0, k) {
            if (i == 1) {
                dp[v][i] = 1;
            } else {
                dp[v][i] = 0;
            }
        }
        return;
    }

    FORIT(it, child[v]) {
        dfs(*it);
    }
    vector<vector<ll> > ddp(SZ(child[v]) + 1, vector<ll>(k + 1, 0));
    ddp[0][1] = 1;

    // printf("V = %d\n", v);
    FOR(i, 1, SZ(child[v])) {
        // using the same color as v
        // FOR(j, 1, k) {
        //     ddp[i][j] = ddp[i - 1][j];
        // }
        FOR(j, 1, k) {
            FOR(x, 1, j) {
                // using x colors, differs from v
                if (x < j) {
                    ddp[i][j] += (ddp[i - 1][j - x] * (dp[child[v][i - 1]][x] * x % MOD) % MOD) * comb[x][j - x - 1] % MOD;
                    ddp[i][j] %= MOD;
                }
                // using x colors, but root is the same as v
                ddp[i][j] += ddp[i - 1][j - x + 1] * dp[child[v][i - 1]][x] % MOD;
                ddp[i][j] %= MOD;
            }
            // printf("ddp[%d][%d] = %lld\n", i, j, ddp[i][j]);
        }
    }
    FOR(i, 1, k) {
        dp[v][i] = ddp[SZ(child[v])][i];
        // printf("dp[%d][%d] = %lld\n", v, i, dp[v][i]);
    }
}

void dfschild (int v, int parent) {
    child[v].clear();
    FORIT(it, adj[v]) {
        if (*it != parent) {
            // printf("child %d = %d\n", v, *it);
            child[v].PB(*it);
            dfschild(*it, v);
        }
    }
    // printf("child[%d] = %d\n", v, SZ(child[v]));
}


int main(){
    FOR(i, 0, 50) FOR(j, 0, 50) {
        if (i && j) {
            comb[i][j] = (comb[i][j - 1] + comb[i - 1][j]) % MOD;
        } else {
            comb[i][j] = 1;
        }
    }
    scanf("%d", &ntc);
    FOR(itc, 1, ntc) {
        scanf("%d%d", &n, &k);
        FOR(i, 1, n) {
            adj[i].clear();
        }
        REP(i, n - 1) {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].PB(b);
            adj[b].PB(a);
        }

        dfschild(1, -1);
        dfs(1);
        ll ans = 0;
        FOR(i, 1, k) {
            ans += dp[1][i] * i % MOD * comb[k - i][i];
            ans %= MOD;
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}
