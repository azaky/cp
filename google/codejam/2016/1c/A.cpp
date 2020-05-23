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

int ntc, n, p[33], total;

int majority() {
	int ret = 0;
	REP(i, n) {
		if (p[i] > p[ret]) {
			ret = i;
		}
	}
	return ret;
}

int main() {
	OPEN("A-large");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		total = 0;
		scanf("%d", &n);
		REP(i, n) {
			scanf("%d", &p[i]);
			total += p[i];
		}
		printf("Case #%d:", itc);
		while (total > 0) {
			int a = majority();
			p[a]--; total--;
			if (p[majority()] * 2 > total) {
				int b = majority();
				p[b]--; total--;
				if (p[majority()] * 2 > total) {
					exit(1);
				}
				printf(" %c%c", 'A' + a, 'A' + b);
			} else {
				printf(" %c", 'A' + a);
			}
		}
		putchar('\n');
	}

	return 0;
}