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

int n, m, a[1111][111];

int main(){
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) FOR(j, 1, m) {
		scanf("%d", &a[i][j]);
	}
	vector<string> ans;
	char buf[1000];
	//For every row 1<=i_1<n there exists a column j such that T(i_1,j) != T(i_1+1,j) and T(i_1+1,j) = T(n,j)
	FOR(i1, 1, n-1) {
		bool valid = false;
		FOR(j, 1, m) {
			if (a[i1][j] != a[i1+1][j] && a[i1+1][j] == a[n][j]) {
				valid = true;
				break;
			}
		}
		if (!valid) {
			sprintf(buf, "i1=%d", i1);
			ans.PB(buf);
		}
	}
	//For every pair of rows 1<=i_1< i_2<n there exists a column j such that T(i_1,j) != T(i_1+1,j) and T(i_1+1,j) = T(i_2,j) = T(i_2+1,j).
	FOR(i1, 1, n-2) FOR(i2, i1+1, n-1) {
		bool valid = false;
		FOR(j, 1, m) {
			if (a[i1][j] != a[i1+1][j] && a[i1+1][j] == a[i2][j] && a[i2][j] == a[i2+1][j]) {
				valid = true;
				break;
			}
		}
		if (!valid) {
			sprintf(buf, "i1=%d i2=%d", i1, i2);
			ans.PB(buf);
		}
	}
	printf("%d\n", SZ(ans));
	REP(i, SZ(ans)) printf("%s\n", ans[i].c_str());
	
	return 0;
}
