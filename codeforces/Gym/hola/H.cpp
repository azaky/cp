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

#define MAXN 200200

int n;
vector<int> adj[MAXN];

pii hubaMin(int v, int parent, int player) {
	pii ans = MP(0, 0);
	if (player < 0) {
		ans.A = n;
	}
	FORIT(it, adj[v]) {
		if (*it != parent) {
			pii child = hubaMin(*it, v, -player);
			ans.B += child.B;
			if (player > 0) {
				ans.A += child.A;
			} else {
				MN(ans.A, child.A);
			}
		}
	}
	if (ans.B == 0) {
		ans = MP(1, 1);
	}
	return ans;
}

pii hubaMax(int v, int parent, int player) {
	pii ans = MP(0, 0);
	if (player > 0) {
		ans.A = -n;
	} else {
		ans.A = 1;
	}
	FORIT(it, adj[v]) {
		if (*it != parent) {
			pii child = hubaMax(*it, v, -player);
			ans.B += child.B;
			if (player > 0) {
				MX(ans.A, child.A - child.B);
			} else {
				ans.A += child.A - 1;
			}
		}
	}
	if (ans.B == 0) {
		ans = MP(1, 1);
	} else if (player > 0) {
		ans.A += ans.B;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	REP(i, n-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		adj[x].PB(y);
		adj[y].PB(x);
	}
	printf("%d %d\n", hubaMax(0, -1, 1).A, hubaMin(0, -1, 1).A);

	return 0;
}