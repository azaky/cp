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

#define THRESHOLD 358400

int image[30][77][111], all[77][611], newAll[77][611], a[77][111];
int black[30];
char buffer[100], ans[10];

void loadAlphabet() {
    REP(x, 26) {
        char ch = 'a' + x;
        if (ch == 'f' || ch == 'h' || ch == 'x') continue;
        sprintf(buffer, "l/alphabet/%c.in", ch);
        FILE *falpha = fopen(buffer, "r");
        black[x] = 0;
        REP(i, 70) REP(j, 100) {
            fscanf(falpha, "%d", &image[x][i][j]);
            if (image[x][i][j] == 0) {
                black[x]++;
            }
        }
        fclose(falpha);
    }
}

void medianFilter() {
    REP(i, 70) REP(j, 600) {
        vector<int> vals;
        FOR(ii, i - 1, i + 1) FOR(jj, j - 1, j + 1) {
            if (ii < 0 || ii >= 70 || jj < 0 || jj >= 600) {
                continue;
            } else {
                vals.PB(all[ii][jj]);
            }
        }
        sort(ALL(vals));
        newAll[i][j] = vals[(SZ(vals) + 1) / 2];
    }
    bool allSame = true;
    REP(i, 70) REP(j, 600) {
        if (all[i][j] != newAll[i][j]) {
            allSame = false;
        }
        all[i][j] = newAll[i][j];
    }
    // assert(!allSame);
}

int main(){
    loadAlphabet();

    FOR(itc, 1, 800) {
        sprintf(buffer, "l/l1/%03d.in", itc);
        FILE *f = fopen(buffer, "r");
        REP(i, 70) REP(j, 600) {
            fscanf(f, "%d", &all[i][j]);
        }
        fclose(f);

        // medianFilter();

        int totalerror = 0;
        REP(t, 6) {
            REP(i, 70) REP(j, 100) {
                a[i][j] = all[i][100 * t + j];
            }
            int best = 255 * 70 * 100;
            pii bestOffset;
            char chans;
            REP(x, 26) {
                char ch = 'a' + x;
                if (ch == 'f' || ch == 'h' || ch == 'x') continue;
                int threshold = black[x] * 255 / 5;
                FOR(offseti, -10, 10) FOR(offsetj, -30, 30) {
                    int error = 0;
                    bool tooMuchError = false;
                    REP(i, 70) {
                        if (tooMuchError) break;
                        REP(j, 100) {
                            if (image[x][i][j] == 0) {
                                int ii = i + offseti, jj = j + offsetj;
                                if (ii < 0 || ii >= 70 || jj < 0 || jj >= 100) {
                                    tooMuchError = true;
                                    break;
                                    // error += a[ii][jj];
                                } else {
                                    error += a[ii][jj];
                                }
                                if (error > threshold) {
                                    tooMuchError = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (!tooMuchError && error < best) {
                        best = error;
                        chans = ch;
                        bestOffset = MP(offseti, offsetj);
                    }
                }
            }
            if (best > black[chans] * 255 / 10) {
                fprintf(stderr, "SMALL: %.3lf: %c\n", 1. - (db) best / (255 * 70 * 100), chans);
                fprintf(stderr, "offset: i: %d, j: %d\n", bestOffset.A, bestOffset.B);
            }
            ans[t] = chans;
            totalerror += best;
        }

        ans[6] = 0;
        printf("%s\n", ans);
        fprintf(stderr, "TC %d: %.3lf\n", itc, 1. - (db)totalerror / (600 * 70 * 255));
        fprintf(stderr, "%s\n", ans);
    }
    
    return 0;
}
