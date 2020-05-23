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

#define MAXN 1100

int ntc, n, k, r, c;
char a[MAXN][MAXN], buffer[10];

int chuba, itcglobal;

void resethuba() {
	chuba = 0;
}

void huba(char ch, int r, int c) {
	if (!(a[r][c] != ch)) {
		return;
		fprintf(stderr, "FAIL ON TC %d\n", itcglobal);
		fflush(stdout);
		assert(false);
	}
	a[r][c] = ch;
	chuba++;
	printf("%c %d %d\n", ch, r, c);
}

void verifyhuba(int ans, int nans) {
	FOR(i, 1, n) FOR(j, 1, n) {
		if (a[i][j] == 'o') {
			ans -= 2;
		} else if (a[i][j] != '.') {
			ans--;
		}
	}
	if (!(ans == 0) || !(chuba == nans)) {
		fprintf(stderr, "FAIL ON TC %d\n", itcglobal);
		fflush(stdout);
		assert(false);
	}
}

void printgrid(const char* message) {
	return;
	puts(message);
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			printf("%c", a[i][j]);
		}
		puts("");
	}
}

int main(){
	scanf("%d", &ntc);

	FOR(itc, 1, ntc) {
		itcglobal = itc;
		resethuba();
		scanf("%d%d", &n, &k);
		RESET(a, '.');
		int pos = 1;
		int ans = 3 * n - 2;
		int nans = 3 * n - 3;
		REP(i, k) {
			scanf("%s%d%d", buffer, &r, &c);
			char p = buffer[0];
			if (p != '+') {
				pos = c;
				if (p == 'o') {
					nans--;
				}
			} else {
				nans--;
			}
			a[r][c] = p;
		}
		if (a[1][pos] == '+') {
			nans++;
		}
		printgrid("before");

		if (n == 1) {
			ans = 2;
			nans = 1;
			if (a[1][1] == 'o') {
				nans--;
			}
			printf("Case #%d: %d %d\n", itc, ans, nans);
			if (a[1][1] != 'o') {
				huba('o', 1, 1);
			}
			printgrid("after");
			verifyhuba(ans, nans);
			continue;
		}

		if (n == 3 && a[1][1] == '+' && a[1][3] == '+' && (a[1][2] == 'x' || a[1][2] == 'o')) {
			ans = 6;
			nans = 2;
			if (a[1][2] == 'x') {
				nans++;
			}
			printf("Case #%d: %d %d\n", itc, ans, nans);
			huba('o', 1, 2);
			huba('x', 3, 1);
			huba('+', 3, 2);
			printgrid("after");
			verifyhuba(ans, nans);
			continue;
		}

		if (pos != 1) {
			nans--;
		}
		printf("Case #%d: %d %d\n", itc, ans, nans);
		FOR(i, 1, n) {
			if (i == pos) {
				if (a[1][i] == 'o') continue;
				huba('o', 1, i);
			} else {
				if (a[1][i] == '+') continue;
				huba('+', 1, i);
			}
		}
		int dir = (pos == 2) ? -1 : +1;
		int posc = (pos + dir) % n;
		posc = (posc + n - 1) % n + 1;
		FOR(i, 2, n - 1) {
			huba('x', i, posc);
			posc = (posc + dir) % n;
			posc = (posc + n - 1) % n + 1;
		}
		if (pos == 1) {
			FOR(i, 2, n - 1) {
				huba('+', n, i);
			}
			huba('x', n, n);
		} else {
			FOR(i, 2, n - 1) {
				if (i == posc) {
					huba('o', n, i);
				} else {
					huba('+', n, i);
				}
			}
		}
		printgrid("after");
		verifyhuba(ans, nans);
	}
	
	return 0;
}