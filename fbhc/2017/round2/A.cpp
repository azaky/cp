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

#define INF 1000000000

int n, m, k, ntc;

int calc1(int n, int m, int k) {
	if (2 * k + 3 > m) return INF;
	int need = (n + k - 1) / k;
	if (need == 1) return INF;
	return need;
}

int calc2(int n, int m, int k) {
	if (2 * k + 3 > m) return INF;
	if (2 * k + 1 > n) return INF;
	int need = (k + 2 + k - 1) / k;
	return need + 2;
}

int calc(int n, int m, int k) {
	return min(calc1(n, m, k), calc2(n, m, k));
}

int main(){
	scanf("%d", &ntc);

	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &n, &m, &k);
		int ans = min(calc(n, m, k), calc(m, n, k));
		if (ans == INF) {
			ans = -1;
		}
		printf("Case #%d: %d\n", itc, ans);
	}
	
	return 0;
}