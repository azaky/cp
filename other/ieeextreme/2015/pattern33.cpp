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


/** Suffix Array **/
/* complexity: O(N log N) */
#define MAXN 1100100

void buildFailTable(int m, char *pattern, int *t){
	int i = 0, j = -1;
	t[0] = -1;
	while (i < m){
		while (j >= 0 && pattern[i] != pattern[j]) j = t[j];
		i++; j++;
		t[i] = j;
	}
}

char T[MAXN+5];
int n;
int fail[MAXN + 5];

int ntc;

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%s", T);
		n = strlen(T);
		buildFailTable(n, T, fail);

		// for (int i = 0; i < n; ++i) {
		// 	printf("%3d", i);
		// }
		// puts("");
		// for (int i = 0; i < n; ++i) {
		// 	printf("%3c", T[i]);
		// }
		// puts("");
		// for (int i = 0; i < n; ++i) {
		// 	printf("%3d", fail[i]);
		// }
		// puts("");

		int pn = 1;
		int pos = 0;
		for (int i = 0; i < n; ++i) {
			pos = i % pn;
			if (T[pos] != T[i]) {
				// printf("i = %d, fail nih\n", i);
				pn = i + 1 - fail[i + 1];
			}
			// printf("i =  %d, pn = %d\n", i, pn);
		}

		printf("%d\n", pn);
	}

	return 0;
}