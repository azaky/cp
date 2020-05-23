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

struct huba {
    huba () {}
    huba (ll x, ll y) : a(x), b(y) {}
    ll a, b;

    bool operator< (const huba &other) {
        // the one with b == 0 should be on the right side
        if (this->b == 0) {
            return false;
        } else if (other.b == 0) {
            return true;
        }
        return this->a * other.b < this->b * other.a;
    }
};

const int MAXN = 1 << 18 + 5;

int n, q, itcglobal;
ll a[MAXN], b[MAXN], suma[MAXN], sumb[MAXN];
int x, y;
ll c, d;
vector<huba> node[MAXN << 1];
vector<ll> prefixa[MAXN << 1], prefixb[MAXN << 1];

void build(int v, int l, int r) {
    if (l == r) {
        node[v].resize(1);
        node[v][0] = huba(a[l], b[l]);
        prefixa[v].resize(1);
        prefixb[v].resize(1);
        prefixa[v][0] = a[l];
        prefixb[v][0] = b[l];
    } else {
        int m = (l + r) >> 1;
        int vl = v << 1;
        int vr = vl | 1;
        build(vl, l, m);
        build(vr, m + 1, r);
        
        int size = r - l + 1;
        node[v].resize(size);
        prefixa[v].resize(size);
        prefixb[v].resize(size);
        merge(ALL(node[vl]), ALL(node[vr]), node[v].begin());
        REP(i, size) {
            if (i) {
                prefixa[v][i] = prefixa[v][i - 1] + node[v][i].a;
                prefixb[v][i] = prefixb[v][i - 1] + node[v][i].b;
            } else {
                prefixa[v][i] = node[v][i].a;
                prefixb[v][i] = node[v][i].b;
            }
        }
    }
}

ll query(int v, int l, int r, int x, int y, ll c, ll d) {
    if (r < x || y < l) {
        return 0;
    } else if (x <= l && r <= y) {
        // FORIT(it, node[v]) {
        //     // if (itcglobal == 994) fprintf(stderr, "(%lld,%lld) ", it->a, it->b);
        // }
        // if (itcglobal == 994) fprintf(stderr, "\n");
        // if (itcglobal == 994) fprintf(stderr, "finding (%lld,%lld)\n", d, c);
        // int bl = 0, br = SZ(node[v]);
        // huba now(d, c);
        // while (bl < br) {
        //     int m = (bl + br) >> 1;
        //     if (node[v][m] < now) {
        //         bl = m + 1;
        //     } else {
        //         br = m;
        //     }
        // }
        // // if (itcglobal == 994) fprintf(stderr, "found!: (%d,%d)\n", bl, br);
        // // int idxbrute = -1;
        // // for (int i = 0; i <= SZ(node[v]); ++i) {
        // //     if (i == SZ(node[v]) || now < node[v][i] || node[v][i].b == 0) {
        // //         idxbrute = i;
        // //         break;
        // //     }
        // // }
        // int idx = bl;
        // fprintf(stderr, "idx = %d, idxbrute = %d\n", idx, idxbrute);
        // if (itcglobal == 994) assert(idxbrute == idx);
        int idx = lower_bound(ALL(node[v]), huba(d, c)) - node[v].begin();
        if (idx == 0) {
            return 0;
        } else {
            return c * prefixa[v][idx - 1] - d * prefixb[v][idx - 1];
        }
    } else {
        int m = (l + r) >> 1;
        int vl = v << 1;
        int vr = vl | 1;
        ll ql = query(vl, l, m, x, y, c, d);
        ll qr = query(vr, m + 1, r, x, y, c, d);
        return ql + qr;
    }
}

int main(){
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
    }
    FOR(i, 1, n) {
        scanf("%lld", &b[i]);
    }

    // we need n to be power of two
    int n2 = 1;
    while (n2 < n) {
        n2 <<= 1;
    }
    n = n2;

    // build usual prefix sum
    FOR(i, 1, n) {
        suma[i] = suma[i - 1] + a[i];
        sumb[i] = sumb[i - 1] + b[i];
    }

    // build range tree
    build(1, 1, n);

    scanf("%d", &q);

    FOR(iq, 1, q) {
        itcglobal = iq;
        scanf("%d%d%lld%lld", &x, &y, &c, &d);
        ll sum = c * (suma[y] - suma[x - 1]) - d * (sumb[y] - sumb[x - 1]);
        ll negative = query(1, 1, n, x, y, c, d);
        printf("%lld\n", sum - negative);
        fflush(stdout);
    }
    
    return 0;
}
