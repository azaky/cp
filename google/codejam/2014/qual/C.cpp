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
		bool swapped = false;
		bool possible = true;
		char ans[55][55];
		RESET(ans, '.');
		int r, c, m;
		scanf("%d%d%d", &r, &c, &m);
		if (r > c) {
			swapped = true;
			swap(r, c);
		}
		
		int rest = r*c - m;
		assert(rest > 0);
		if (r == 1) {
			ans[1][c] = 'c';
			FOR(i, 1, m) ans[1][i] = '*';
		}
		else if (r == 2) {
			if (rest == 1) {
				RESET(ans, '*');
				ans[1][1] = 'c';
			}
			else if (m <= 2 * (c-2) && m % 2 == 0) {
				FOR(i, 1, m / 2) ans[1][i] = ans[2][i] = '*';
				ans[1][c] = 'c';
			}
			else {
				possible = false;
			}
		}
		else {
			if (m <= (c-2) * r - 2 || m == (c-2) * r) {
				int k = m / r;
				FOR(i, 1, r) FOR(j, 1, k) ans[i][j] = '*';
				int t = m % r;
				if (t == r-1) {
					FOR(i, 1, r-2) ans[i][k+1] = '*';
					ans[1][k+2] = '*';
				}
				else {
					FOR(i, 1, t) ans[i][k+1] = '*';
				}
				ans[1][c] = 'c';
			}
			else if (rest == 1) {
				RESET(ans, '*');
				ans[1][1] = 'c';
			}
			else if (rest != 2 && rest != 3 && rest != 5 && rest != 7) {
				RESET(ans, '*');
				if (rest % 3 == 0) {
					FOR(i, 1, rest / 3) ans[i][1] = ans[i][2] = ans[i][3] = '.';
					ans[1][1] = 'c';
				}
				else if (rest % 3 == 1) {
					int k = (rest-4) / 3;
					FOR(i, 1, k) ans[i][1] = ans[i][2] = ans[i][3] = '.';
					ans[k+1][1] = ans[k+1][2] = ans[k+2][1] = ans[k+2][2] = '.';
					ans[1][1] = 'c';
				}
				else {
					int k = (rest-2) / 3;
					FOR(i, 1, k) ans[i][1] = ans[i][2] = ans[i][3] = '.';
					ans[k+1][1] = ans[k+1][2] = '.';
					ans[1][1] = 'c';
				}
			}
			else {
				possible = false;
			}
		}
		
		if (possible) {
			int total = 0;
			FOR(i, 1, r) FOR(j, 1, c) if (ans[i][j] == '*') total++;
			//fprintf(stderr, "tc %d\n", itc);
			assert(total == m);
		}
		
		printf("Case #%d:\n", itc);
		if (possible) {
			if (swapped) {
				FOR(j, 1, c) {
					FOR(i, 1, r) putchar(ans[i][j]);
					puts("");
				}
			}
			else {
				FOR(i, 1, r) {
					FOR(j, 1, c) putchar(ans[i][j]);
					puts("");
				}
			}
		}
		else {
			puts("Impossible");
		}
	}
	
	return 0;
}
