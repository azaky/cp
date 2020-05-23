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

/* -------------- end of DELAPAN.3gp's template -------------- */

#define MAXN 5000500

int ntc;
int r, c, n;
ll k, h;


int bit[MAXN];

void update(int k, int v) {
    for (int x = k; x <= n; x += (x & -x)) {
        bit[x] += v;
    }
}

int query(int k) {
    int sum = 0;
    for (int x = k; x > 0; x -= (x & -x)) {
        sum += bit[x];
    }
    return sum;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

int main(){
    scanf("%d", &ntc);

    FOR(itc, 1, ntc) {
        scanf("%d %d %lld %lld", &r, &c, &k, &h);
        ll lr = r, lc = c;
        n = r * c;
        vector<vector<int> > a(r + 1, vector<int>(c + 1));
        vector<pair<int, pii> > v;
        rep1(i, r) {
            rep1(j, c) {
                ll li = i, lj = j;
                a[i][j] = ((((li - 1) * lc + lj) * k + h) % (lr * lc)) + 1;
                v.PB(MP(a, MP(i, j)));
            }
        }

        sort(ALL(v));

        vector<int> ans(r + c, -1);
        vector<pii> mpos(r + c);
        ans[0] = a[0][0];
        ans[r + c - 2] = a[r - 1][c - 1];
        mpos[0] = MP(0, 0);
        mpos[r + c - 2] = MP(r - 1, c - 1);

        // initialize BIT
        RESET(bit, 0);
        update(0 + 1, 1);
        update(r + c - 2 + 1, 1);

        FORIT(it, v) {
            int id = it->A;
            int nr = it->B->A, nc = it->B->B;
            int pos = nr + nc;
            if (ans[pos] != -1) {
                continue;
            }

            // find left
            int l = 0, r = pos - 1;
            while (l < r) {
                
            }
        }
	}
	
	return 0;
}
