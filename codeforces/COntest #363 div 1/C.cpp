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

#define MAXN 22

int n, k, nonzero;
double p[MAXN], dp[1 << 20][20], dptotal[1 << 20], ans[MAXN];

int main(){
    /**
        A = p(A)
        B = p(B)
        C = P(C)
        
        AB = p(B) * (A)
        BA = p(A) * (B)
        AC = p(C) * (A)
        CA = p(A) * (C)
        BC = p(C) * (B)
        CB = p(B) * (C)

        AB = p(B) / (1 - p(B)) * A
        BA = p(A) / (1 - p(A)) * B
        AC = p(C) / (1 - p(C)) * A
        CA = p(A) / (1 - p(A)) * C
        BC = p(C) / (1 - p(C)) * B
        CB = p(B) / (1 - p(B)) * C

        [AB]C = p(C) / (1 - p(A) - p(B)) * [AB]

        [AB]C = p(C) * [AB] + (p(A) + p(B)) * [AB]C

        sum = q(A) * (B + C) = p(A)

        ABC = p(C) * (AB + ABC + ACB)
        BAC = p(C) * (BA + BCA + BAC)
        ACB = p(B) * (AC + ACB + ABC)


        ...C = p(C) * (... + .C.. + ..C. + ...C)

        A[BC] = 

        sum = sigma ([AB] * p(C)) + sigma (A[BC] * (1 - p(A)))
            = sigma ([AB] * p(C)) + sum - sigma(A[BC] * p(A))

        sigma(A[BC] * p(A)) = sigma([AB] * p(C))

        IF A[BC] = BC -> 
        sum = sigma([AB] * p(C)) + sigma([AB] * (1 - p(C))) = sigma([AB])

        [AB]C = p(C) * [AB]C + p(C) * [AB] + p(C) * 
        [AB]C = p(C) * (AB + ACB +)
        [AC]B = q(B) * [AC]
        [BC]A = q(A) * [BC]

        ABC = p(C) * ()

        sum = sigma p(A) * (1 - p(A)) = 3 - sigma p^2

        AB = p(B) * (A + AB) <-> AB * (1 - p(B)) = p(B) * A <-> AB = p(B) * A / (1 - p(B))
        BA = p(A) * 

        ABC = p(C) * (AB + ABC) -> ABC = p(C) * AB / (1 - p(C))
        BAC = p(C) * (BA + BAC)

        [AB]C = p(C) * [AB] + p(C) * [AB]C -> [AB]C * (1 - p(C)) = p(C) * [AB] 

        [AB]C = p(C) / (1. - p(C)) * AB
        sum = q(A) * 

        AB = p(B) * (AB + BA + CA)
        BA = p(A) * (BA + AB + CB)
        AC = p(C) * (AC + BA + CA)`
        CA = p(A) * (CA + BC + AC)
        BC = p(C) * (BC + AB + CB)
        CB = p(B) * (CB + AC + BC)
        sum = 1

        p(C) * (AB + BA) = p(B) * CA + p(A) * CB

        ans(A) = AB + BA + AC + CA = AB * (1 - p(C)) + 
        ans(A) = AB + BA + AC + CA = p(A) * (AB + CB + BC + AC) + (p(B) + p(C)) * (BA + CA) = p(A) * (AB + AC) + p(A) * (BC + CB) + (p(B) + p(C)) * (BA + CA)

        [AB]C = p(C) * (C[AB] + D[AB])
    **/
    /* AB = p(A) * AB + p(A) * BC + p(B) * AC */
    /* BC = p(B) * BC + p(B) * AC + p(C) * AB */
    /* AC = p(C) * AC + p(A) * BC + p(C) * AB */
    /* AB + BC + CA = AB * (p(A) + p(C) + p(C)) + BC * (p(A) + p(B) + p(A)) + CA * (p(B) + p(B) + p(C)) */

    scanf("%d%d", &n, &k);
    REP(i, n) {
        scanf("%lf", &p[i]);
        if (!p[i]) {
            ++nonzero;
        }
    }

    k = MN(nonzero, k);

    // REP(i, n) {
    //     if (fabs(p[i] - 1.) < 1e-6) {
    //         REP(i, n) {
    //             printf("%.lf ", p[i]);
    //         }
    //         putchar('\n');

    //         return 0;
    //     }
    // }

    REP(s, 1 << n) {
        int t = __builtin_popcount(s);
        if (!t || t > k) continue;

        if (t == 1) {
            REP(i, n) if (s & (1 << i)) {
                dp[s][i] = dptotal[s] = p[i];
            }
        } else {
            REP(i, n) {
                if ((1 << i) & s) {
                    db rec = 0;
                    REP(j, n) {
                        if (((1 << j) & s) && i != j) {
                            rec += p[j];
                        }
                    }
                    if (fabs(rec - 1.) < 1e7) continue;
                    dptotal[s] += p[i] * dptotal[s ^ (1 << i)] / (1. - rec);
                    // dptotal[s] += dptotal[s ^ (1 << i)];
                    // dptotal[s] += p[i] * dptotal[s ^ (1 << i)];
                    // printf("dp[%d][%d] = %.9lf\n", s, i, dp[s][i]);
                }
            }
        }

        if (t == k) {
            REP(i, n) {
                if ((1 << i) & s) {
                    ans[i] += dptotal[s];
                }
            }
        }
    }

    REP(i, n) {
        printf("%.17lf ", ans[i]);
    }
    putchar('\n');
    
    return 0;
}
