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

int main(){
	int ntc;
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		int r1, r2, a[4][4];
		scanf("%d", &r1);
		REP(i, 4) REP(j, 4) scanf("%d", &a[i][j]);
		set<int> s;
		REP(i, 4) s.insert(a[r1-1][i]);
		scanf("%d", &r2);
		REP(i, 4) REP(j, 4) scanf("%d", &a[i][j]);
		set<int> ans;
		REP(i, 4) if (EXIST(a[r2-1][i], s)) ans.insert(a[r2-1][i]);
		if (SZ(ans) == 0) {
			printf("Case #%d: Volunteer cheated!\n", itc);
		}
		else if (SZ(ans) == 1) {
			printf("Case #%d: %d\n", itc, *(ans.begin()));
		}
		else {
			printf("Case #%d: Bad magician!\n", itc);
		}
	}
	
	return 0;
}
