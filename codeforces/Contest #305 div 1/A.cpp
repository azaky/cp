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

int m, h1, h2, a1, a2, x1, x2, yoo1, y2;

pii find(int h, int a, int x, int y) {
	vector<int> v(m);
	vector<int> o(m);

	int t = h;
	int c = 0;
	while (!v[t]) {
		v[t] = 1;
		o[t] = c++;
		t = (int)(((ll)x * t + y) % (ll)m);
	}

	if (!v[a]) return MP(-1, 0);

	if (o[a] < o[t]) {
		return MP(o[a], 0);
	} else {
		return MP(o[a], c - o[t]);
	}
}

int main() {
	scanf("%d", &m);
	scanf("%d%d%d%d", &h1, &a1, &x1, &yoo1);
	scanf("%d%d%d%d", &h2, &a2, &x2, &y2);

	pii p1 = find(h1, a1, x1, yoo1);
	pii p2 = find(h2, a2, x2, y2);

	// printf("p1: (%d, %d)\n", p1.A, p1.B);
	// printf("p2: (%d, %d)\n", p2.A, p2.B);

	if (p1.A == -1 || p2.A == -1) {
		puts("-1");
		return 0;
	}

	REP(i, 1000000) {
		ll x = (ll)p1.B * i + p1.A;
		ll i2 = x - p2.A;
		if (p2.B == 0) {
			if (i2 == 0) {
				cout << x << endl;
				return 0;
			}
		} else if (i2 >= 0) {
			ll y = i2 / p2.B;
			y = y * p2.B + p2.A;
			if (x == y) {
				cout << x << endl;
				return 0;
			}
		}
	}

	puts("-1");

	return 0;
}