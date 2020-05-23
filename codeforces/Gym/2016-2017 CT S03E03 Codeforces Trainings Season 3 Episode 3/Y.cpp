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

int n, f, m, t[555], c[555], cot[555], ans[555];
vector<int> cars[555];

int main(){
	scanf("%d%d%d", &n, &f, &m);
	REP(i, m) {
		scanf("%d%d", &t[i], &c[i]);
		if (c[i] && t[i] != f) {
			cars[t[i]].PB(c[i]);
		}
		cot[t[i]]++;
	}
	bool impossible = false;
	FOR(i, 1, n) {
		if (i == f) continue;
		sort(ALL(cars[i]));
		reverse(ALL(cars[i]));
		int x = 0;
		while (x < SZ(cars[i]) && cot[i] > 0) {
			cot[i] -= cars[i][x++];
		}
		if (cot[i] > 0) {
			impossible = true;
			break;
		} else {
			ans[i] = x;
		}
	}
	if (impossible) {
		puts("IMPOSSIBLE");
	} else {
		FOR(i, 1, n) {
			printf("%d", ans[i]);
			if (i < n) {
				putchar(' ');
			} else {
				putchar('\n');
			}
		}
	}

	return 0;
}