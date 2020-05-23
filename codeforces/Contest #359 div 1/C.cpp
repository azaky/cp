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
    point () {};
    point (ll _x, ll _y, ll _z) : x(_x), y(_y), z(_z) {}
};

int ntc, n;
ll x[MAXN], y[MAXN], z[MAXN];

pair<pll, pll> allright(ll d, ll* x, ll* y, bool& valid) {
    pll topLeft(-INF, -INF), bottomRight(INF, INF);
    REP(i, n) {
        pll tl = MP(x[i] + y[i] - d, x[i] - y[i] - d);
        pll br = MP(x[i] + y[i] + d, x[i] - y[i] + d);
        // if (br.B < topLeft.B || br.A < topLeft.A || bottomRight.A < tl.A || bottomRight.B < tl.B) {
        //     valid = false;
        //     return MP(topLeft, bottomRight);
        // }
        MX(topLeft.A, tl.A);
        MX(topLeft.B, tl.B);
        MN(bottomRight.A, br.A);
        MN(bottomRight.B, br.B);
        if (topLeft.A > bottomRight.A) {
            // printf("fail at i = %d\n", i);
            // printf("%lld > %lld\n", topLeft.A, bottomRight.A);
            // printf("topLeft = (%lld, %lld), bottomRight = (%lld, %lld)\n", topLeft.A, topLeft.B, bottomRight.A, bottomRight.B);
            valid = false;
            return MP(pll(), pll());
        }
    }
    // printf("d = %lld\n", d);
    // printf("topLeft = (%lld, %lld), bottomRight = (%lld, %lld)\n", topLeft.A, topLeft.B, bottomRight.A, bottomRight.B);
    return MP(topLeft, bottomRight);
}

pll intersect(pll a, pll b, bool &valid) {
    if (a.B < b.A || b.B < a.A) {
        valid = false;
        return pll();
    }
    return MP(max(a.A, b.A), min(a.B, b.B));
}

point okay(ll d, bool &valid) {
    pair<pll, pll> xy = allright(d, x, y, valid);
    if (!valid) {
        return point();
    }
    pair<pll, pll> yz = allright(d, y, z, valid);
    if (!valid) {
        return point();
    }
    pair<pll, pll> zx = allright(d, z, x, valid);
    if (!valid) {
        return point();
    }

    // xy <-> yz
    pll ry = intersect(MP((xy.A.A - xy.B.B) / 2, (xy.B.A - xy.A.B) / 2), MP((yz.A.A + yz.A.B) / 2, (yz.B.A + yz.B.B) / 2), valid);
    if (!valid) {
        return point();
    }
    // yz <-> zx
    pll rz = intersect(MP((yz.A.A - yz.B.B) / 2, (yz.B.A - yz.A.B) / 2), MP((zx.A.A + zx.A.B) / 2, (zx.B.A + zx.B.B) / 2), valid);
    if (!valid) {
        return point();
    }
    // zx <-> xy
    pll rx = intersect(MP((zx.A.A - zx.B.B) / 2, (zx.B.A - zx.A.B) / 2), MP((xy.A.A + xy.A.B) / 2, (xy.B.A + xy.B.B) / 2), valid);
    if (!valid) {
        return point();
    }

    return point((rx.A + rx.B) / 2, (ry.A + ry.B) / 2, (rz.A + rz.B) / 2);
}

int main(){
    scanf("%d", &ntc);
    FOR(itc, 1, ntc) {
        scanf("%d", &n);
        REP(i, n) {
            cin >> x[i] >> y[i] >> z[i];
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
