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

int ntc, n, pos[22], k;
vector<pii> adj[MAXN];

int best[MAXN], visited[MAXN], prev[MAXN];
char ans[MAXN << 4];
int nans;

void calc(int x, int y) {
    if (x == y) {
        return;
    }

    RESET(best, 63);
    RESET(visited, 0);
    RESET(prev, 0);
    best[x] = 0;
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (v == y) break;

        FORIT(it, adj[v]) {
            int nextt = it->A;
            if (visited[nextt]) continue;
            best[nextt] = best[v] + 1;
            visited[nextt] = 1;
            q.push(nextt);
            prev[nextt] = v;
        }
    }

    assert(visited[y]);
    vector<int> path;
    int now = y;
    path.PB(y);
    while (now != x) {
        assert(now);
        now = prev[now];
        path.PB(now);
    }

    reverse(ALL(path));
    REP(i, SZ(path) - 1) {
        bool found = false;
        FORIT(it, adj[path[i]]) {
            if (it->A == path[i + 1]) {
                found = true;
                ans[nans++] = it->B;
                break;
            }
        }
        assert(found);
    }
}

int main(){
    scanf("%d", &ntc);

    FOR(itc, 1, ntc) {
        fprintf(stderr, "tc %d\n", itc);
        scanf("%d%d%d", &n, &pos[0], &k);
        REP(i, k) {
            scanf("%d", &pos[i + 1]);
        }
        // build graph
        // reset everything
        FOR(i, 1, 2 * n) {
            adj[i].clear();
        }
        FOR(i, 1, n) {
            adj[i].PB(MP(2 * i, 'L'));
            adj[i + n].PB(MP(2 * i - 1, 'L'));
            adj[i].PB(MP(2 * i - 1, 'R'));
            adj[i + n].PB(MP(2 * i, 'R'));
        }
        nans = 0;
        REP(i, k) {
            // fprintf(stderr, "doing %d\n", i);
            calc(pos[i], pos[i + 1]);
            // fprintf(stderr, "done %d\n", i);
        }
        ans[nans] = 0;
        printf("%d:%s\n", nans, ans);
    }
    
    return 0;
}
