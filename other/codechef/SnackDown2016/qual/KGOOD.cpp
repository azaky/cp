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

#define MAXN 100100

int ntc, k, f[30];
char s[MAXN];

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%s%d", s, &k);
		int n = strlen(s);
		RESET(f, 0);
		REP(i, n) {
			f[s[i] - 'a']++;
		}
		vector<int> v;
		REP(i, 26) {
			if (f[i]) {
				v.PB(f[i]);
			}
		}

		int ans = n;
		int m = SZ(v);
		REP(i, m) {
			int lower = v[i];
			int toRemove = 0;
			REP(j, m) {
				if (v[j] < lower) {
					toRemove += v[j];
				}
				else if (v[j] > lower + k) {
					toRemove += v[j] - lower - k;
				}
			}
			// printf("lower = %d, toRemove = %d\n", lower, toRemove);
			MN(ans, toRemove);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
