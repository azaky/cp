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

int n, k, p, a[111111];
vector<int> odd, even;

int main(){
	scanf("%d%d%d", &n, &k, &p);
	REP(i, n) {
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0) {
			even.PB(a[i]);
		}
		else {
			odd.PB(a[i]);
		}
	}
	if ((SZ(odd) - (k-p)) % 2 != 0 || SZ(odd) < k-p || (SZ(even) + (SZ(odd) - (k-p)) / 2) < p) {
		puts("NO");
	}
	else {
		puts("YES");
		//odd
		REP(i, k-p-1) {
			printf("1 %d\n", odd.back());
			odd.pop_back();
		}
		if (k-p > 0) {
			if (p > 0) {
				printf("1 %d\n", odd.back());
				odd.pop_back();
			}
			else {
				printf("%d", SZ(even) + SZ(odd));
				REP(i, SZ(even)) printf(" %d", even[i]);
				REP(i, SZ(odd)) printf(" %d", odd[i]);
				printf("\n");
			}
		}
		//even
		REP(i, p-1) {
			if (SZ(even)) {
				printf("1 %d\n", even.back());
				even.pop_back();
			}
			else {
				int x = odd.back();
				odd.pop_back();
				int y = odd.back();
				odd.pop_back();
				printf("2 %d %d\n", x, y);
			}
		}
		if (p > 0) {
			printf("%d", SZ(even) + SZ(odd));
			REP(i, SZ(even)) printf(" %d", even[i]);
			REP(i, SZ(odd)) printf(" %d", odd[i]);
			printf("\n");
		}
	}
	
	return 0;
}
