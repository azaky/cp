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

int ntc, n, k, p[1005], lamp[1005];

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &k);
		REP(i, k) {
			scanf("%d", &p[i]);
		}
		sort(p, p + k);
		int ns = 0;
		while (ns < k && p[ns] * p[ns] <= n) {
			++ns;
		}

		int ans = 0;
		REP(mask, 1 << ns) {
			FOR(i, 1, n) {
				lamp[i] = 0;
			}
			REP(i, ns) {
				if (mask & (1 << i)) {
					for (int j = p[i]; j <= n; j += p[i]) {
						lamp[j] = !lamp[j];
					}
				}
			}
			int current = 0;
			FOR(i, 1, n) {
				current += lamp[i];
			}
			for (int i = ns; i < k; ++i) {
				int temp = current;
				for (int j = p[i]; j <= n; j += p[i]) {
					if (lamp[j]) {
						temp--;
					} else {
						temp++;
					}
				}
				if (temp > current) {
					for (int j = p[i]; j <= n; j += p[i]) {
						if (lamp[j]) {
							current--;
						} else {
							current++;
						}
						lamp[j] = !lamp[j];
					}
				}
			}
			MX(ans, current);
		}
		printf("Case #%d: %d\n", itc, ans);
	}


	return 0;
}