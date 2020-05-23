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

#define MAXN 22

int r, c;
char grid[MAXN][MAXN];
int a[MAXN][MAXN];

int main(){
	while (scanf("%d %d", &r, &c) == 2) {
		if (r == 0 && c == 0) break;

		REP(i, r) {
			scanf("%s", grid[i]);
		}

		int ans = -1;
		REP(mask, 1 << c) {
			// copy grid
			REP(i, r) REP(j, c) {
				a[i][j] = grid[i][j] == 'X';
			}
			int flip = 0;
			REP(i, c) {
				if (mask & (1 << i)) {
					flip++;
					FOR(j, i - 1, i + 1) {
						if (0 <= j && j < c) {
							a[0][j] = 1 - a[0][j];
						}
					}
					a[1][i] = 1 - a[1][i];
				}
			}
			FOR(i, 1, r - 1) {
				REP(j, c) {
					if (a[i - 1][j]) {
						flip++;
						FOR(k, j - 1, j + 1) {
							if (0 <= k && k < c) {
								a[i][k] = 1 - a[i][k];
							}
						}
						a[i - 1][j] = 1 - a[i - 1][j];
						if (i < r - 1) {
							a[i + 1][j] = 1 - a[i + 1][j];
						}
					}
				}
			}
			bool valid = true;
			REP(i, c) {
				if (a[r - 1][i]) {
					valid = false;
					break;
				}
			}
			if (valid) {
				if (ans == -1 || flip < ans) {
					ans = flip;
				}
			}
		}

		if (ans == -1) {
			puts("Damaged billboard.");
		} else {
			printf("You have to tap %d tiles.\n", ans);
		}
	}
	
	return 0;
}