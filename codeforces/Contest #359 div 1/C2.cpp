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

#define MAXN 100100
#define INF 3000000000000000000ULL

typedef unsigned long long ull;
typedef pair<ll, ll> pll;

struct point {
    ll x, y, z;
    point () {}
    point (ll _x, ll _y, ll _z) : x(_x), y(_y), z(_z) {}
};

struct cube {
    point tl, br;
    cube () {}
    cube (point _tl, point _br) : tl(_tl), br(_br) {}
};

struct tetra {
    point c;
    ll d;
    tetra () {}
    tetra (point _c, ll _d) : c(_c.x, _c.y, _c.z), d(_d) {}
};

int ntc, n;
ll x[MAXN], y[MAXN], z[MAXN];

point okay(ll d, bool &valid) {
    cube cuba(point(x[0] - d, y[0] - d, z[0] - d), point(x[0] + d, y[0] + d, z[0] + d));
    REP(i, n) {
        cube huba(point(x[i] - d, y[i] - d, z[i] - d), point(x[i] + d, y[i] + d, z[i] + d));
        MX(cuba.tl.x, huba.tl.x);
        MX(cuba.tl.y, huba.tl.y);
        MX(cuba.tl.z, huba.tl.z);
        MN(cuba.br.x, huba.br.x);
        MN(cuba.br.y, huba.br.y);
        MN(cuba.br.z, huba.br.z);
        if (cuba.tl.x > cuba.br.x || cuba.tl.y > cuba.br.y || cuba.tl.z > cuba.br.z) {
            valid = false;
            return point();
        }
    }
    return point((cuba.tl.x + cuba.br.x) / 2, (cuba.tl.y + cuba.br.y) / 2, (cuba.tl.z + cuba.br.z) / 2);
}

int main(){
    scanf("%d", &ntc);
    FOR(itc, 1, ntc) {
        scanf("%d", &n);
        REP(i, n) {
            cin >> x[i] >> y[i] >> z[i];
            // x[i] *= 2;
            // y[i] *= 2;
            // z[i] *= 2;
            // scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
        }
        // binary search the answer
        ll l = 0, r = INF;
        while (l < r) {
            ll d = (l + r) / 2;
            bool valid = true;
            okay(d, valid);
            if (valid) {
                r = d;
            } else {
                l = d + 1;
            }
        }
        bool valid = true;
        printf("%lld %lld\n", l, r);
        point ans = okay(l, valid);
        assert(valid);
        cout << ans.x << ' ' << ans.y << ' ' << ans.z << endl;
    }
    
    return 0;
}
