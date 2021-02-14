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
#include <limits>
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

#define MAXN 1000100
int n, q, t;
char color[MAXN];
ll cc[MAXN];
vector<int> m, k, b;

int main(){
	scanf("%d", &n);
	scanf("%s", color);
	
	m.PB(0);
	k.PB(0);
	b.PB(0);
	FOR(i, 1, n) {
		if (color[i-1] == 'M') {
			m.PB(i);
		}
		else if (color[i-1] == 'K') {
			k.PB(i);
		}
		else if (color[i-1] == 'B') {
			b.PB(i);
		}
		else assert(false);
	}
	m.PB(n+1);
	k.PB(n+1);
	b.PB(n+1);
	
	scanf("%d", &q);
	FOR(i, 1, n) {
		cc[i] = (ll) i * (ll) (i+1) / 2LL;
	}
	FOR(ntc, 1, q) {
		char c[10];
		scanf("%s %d", c, &t);
		ll ans = 0;
		if (c[0] == 'M') {
			if (t == 0) {
				FOR(i, 1, SZ(m) - 1) {
					ans += cc[m[i] - m[i-1] - 1];
				}
			}
			else {
				FOR(i, 1, SZ(m) - t - 1) {
					ans += (ll) (m[i] - m[i-1]) * (ll) (m[i + t] - m[i + t - 1]);
				}
			}
		}
		else if (c[0] == 'K') {
			if (t == 0) {
				FOR(i, 1, SZ(k) - 1) {
					ans += cc[k[i] - k[i-1] - 1];
				}
			}
			else {
				FOR(i, 1, SZ(k) - t - 1) {
					ans += (ll) (k[i] - k[i-1]) * (ll) (k[i + t] - k[i + t - 1]);
				}
			}
		}
		else if (c[0] == 'B') {
			if (t == 0) {
				FOR(i, 1, SZ(b) - 1) {
					ans += cc[b[i] - b[i-1] - 1];
				}
			}
			else {
				FOR(i, 1, SZ(b) - t - 1) {
					ans += (ll) (b[i] - b[i-1]) * (ll) (b[i + t] - b[i + t - 1]);
				}
			}
		}
		cout << ans << endl;
	}
	
	
	return 0;
}
