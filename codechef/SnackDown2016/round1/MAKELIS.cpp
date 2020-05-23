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

int ntc, nk;
vector<int> r1, r2;

vector<pii> gen(int x) {
    if (x == 53759) {

        vector<pii> k;
        k.PB(MP(6, 0));
        k.PB(MP(5, 0));
        k.PB(MP(6, 1));
        k.PB(MP(3, 0));
        k.PB(MP(9, 0));
        k.PB(MP(11, 2));
        return k;
    } else if (x == 65279) {
        vector<pii> k;
        k.PB(MP(4, 1));
        k.PB(MP(15, 1));
        k.PB(MP(13, 1));
        k.PB(MP(11, 0));
        k.PB(MP(3, 2));
        k.PB(MP(2, 1));
        return k;
    }
    r1.clear();
    r2.clear();
    if (x == 63839) {
        r1 = {4, 12, 17, 9, 3, 13, 2, 7, 6, 14, 15, 8, 5, 10, 11, 16};
        r2 = {8, 13, 14, 6, 10, 2, 5, 11, 9, 15, 12, 3, 16, 17, 4, 7};
    } else if (x == 86371) {
        r1 = {6, 2, 12, 10, 17, 4, 8, 16, 7, 14, 13, 5, 15, 11, 3, 9};
        r2 = {11, 7, 14, 16, 5, 9, 10, 4, 8, 3, 17, 15, 12, 6, 2, 13};
    } else if (x == 87359) {
        r1 = {16, 13, 12, 5, 3, 10, 14, 7, 6, 17, 15, 9, 8, 11, 2, 4};
        r2 = {11, 8, 15, 3, 9, 10, 17, 4, 7, 16, 12, 14, 5, 13, 6, 2};
    } else if (x == 92129) {
        r1 = {16, 10, 12, 3, 11, 4, 13, 14, 2, 7, 9, 15, 8, 5, 6, 17};
        r2 = {4, 14, 11, 9, 2, 10, 3, 5, 7, 12, 13, 6, 15, 8, 16, 17};
    } else if (x == 96479) {
        r1 = {4, 2, 9, 6, 8, 14, 17, 16, 13, 15, 5, 11, 12, 7, 10, 3};
        r2 = {16, 3, 11, 4, 15, 12, 9, 5, 14, 13, 17, 8, 10, 2, 7, 6};
    } else {
        // vector<int> r1;
        FOR(i, 2, 17) {
            r1.PB(i);
        }
        // random_shuffle(ALL(r1));
        // vector<int> r2;
        FORD(i, 17, 2) {
            r2.PB(i);
        }
        // random_shuffle(ALL(r2));
    }

    vector<pii> k;
    while (x > 0) {
        bool found = false;
        FORIT(it, r1) {
            if (x % *it == 0) {
                k.PB(MP(*it, 0));
                x /= *it;
                found = true;
                break;
            }
        }
        // FOR(i, 2, 17) {
        //     if (x % i == 0) {
        //         k.PB(MP(i, 0));
        //         x /= i;
        //         found = true;
        //         break;
        //     }
        // }
        if (found) continue;

        FORIT(it, r2) {
            if (x % *it == 1) {
                k.PB(MP(*it, 1));
                x /= *it;
                found = true;
                break;
            }
        }
        // FORD(i, 17, 2) {
        //     if (x % i == 1) {
        //         k.PB(MP(i, 1));
        //         x /= i;
        //         break;
        //     }
        // }
    }
    assert(k.back().B == 1);
    k.pop_back();
    reverse(ALL(k));
    return k;
}

int dp[111][111] = {0};
int lis[111] = {0};

int way(const vector<int> &a) {
    int n = SZ(a);
    RESET(dp, 0);
    RESET(lis, 0);
    REP(i, n) {
        dp[a[i]][1] = 1;
        lis[a[i]] = 1;
        REPD(j, i) {
            if (a[j] > a[i]) continue;

            MX(lis[a[i]], lis[a[j]] + 1);
            FOR(k, 1, lis[a[i]]) {
                dp[a[i]][k] += dp[a[j]][k - 1];
            }
        }
    }
    int maxlis = 0;
    REP(i, n) {
        MX(maxlis, lis[a[i]]);
    }
    int ans = 0;
    FOR(i, 1, n) {
        ans += dp[i][maxlis];
    }
    REP(i, n) {
        printf("%d ", a[i]);
    }
    FOR(i, 1, n) {
        printf("lis[%d] = %d\n", i, lis[i]);
    }
    // FOR(i, 1, n) FOR(j, 1, n) {
    //     printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
    // }
    return ans;
}

int main(){
    // srand(time(0));
    scanf("%d", &ntc);
    // ntc = 100000;
    // scanf("%d", &nk);
    // int ans = nk;
    FOR(itc, 1, ntc) {
        scanf("%d", &nk);
        // nk = itc;
        // nk = 53759;
        int n = 1;
        int len = 1;
        vector<int> seq;
        seq.PB(1);

        vector<pii> k = gen(nk);
        REP(ik, SZ(k)) {
            // printf("%d, %d\n", k[ik].A, k[ik].B);
            REP(i, k[ik].A) {
                seq.PB(n + k[ik].A - i);
            }
            n += k[ik].A;
            len++;
            if (k[ik].B) {
                // assert(k[ik].B == 1);
                REP(i, k[ik].B) {
                    vector<int> newseq;
                    newseq.PB(1);
                    REP(i, len - 1) {
                        newseq.PB(n + 1 + i);
                    }
                    n += len - 1;
                    FOR(i, 1, SZ(seq) - 1) {
                        newseq.PB(seq[i]);
                    }
                    seq = newseq;
                }
            }
        }
        // if (SZ(seq) > 100) {
        //     printf("K = %d, N = %d\n", nk, SZ(seq));
        // }
        // MN(ans, SZ(seq));
        // if (SZ(seq) <= 100) {
        //     FORIT(it, k) {
        //         printf("%d %d\n", it->A, it->B);
        //     }
        //     break;
        // }
        // if (SZ(seq) <= 100) {
        //     FORIT(it, r1) {
        //         printf("%d ", *it);
        //     }
        //     puts("");
        //     FORIT(it, r2) {
        //         printf("%d ", *it);
        //     }
        //     puts("");
        //     break;
        // }
        printf("%d\n", SZ(seq));
        REP(i, SZ(seq)) {
            if (i) {
                putchar(' ');
            }
            printf("%d", seq[i]);
        }
        putchar('\n');
        // printf("#lis: %d\n", way(seq));
    }
    // printf("best = %d\n", ans);
    return 0;
}
