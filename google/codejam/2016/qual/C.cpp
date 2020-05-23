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

int main() {
	int ntc, n, t;

	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &t);
		printf("Case #%d:\n", itc);
		int ans = 0;
		while (ans < t) {
			string temp = "";
			int x = ans;
			while (x > 0) {
				temp += '0' + (x & 1);
				temp += '0' + (x & 1);
				x >>= 1;
			}
			while (SZ(temp) < n - 4) {
				temp += '0';
				temp += '0';
			}

			printf("11%s11", temp.c_str());
			FOR(i, 2, 10) {
				printf(" %d", i + 1);
			}
			printf("\n");

			++ans;
		}
		// int three = 3;
		// while (ans < t) {
		// 	string temp = "";
		// 	int x = three;
		// 	while (x > 0) {
		// 		temp += '0' + (x & 1);
		// 		x >>= 1;
		// 	}
		// 	while (SZ(temp) < n - 2) {
		// 		temp += '0';
		// 	}

		// 	printf("1%s1", temp.c_str());
		// 	FOR(i, 2, 10) {
		// 		printf(" %d", i + 1);
		// 	}
		// 	printf("\n");

		// 	three += 3;
		// 	ans++;
		// }
	}

	return 0;
}