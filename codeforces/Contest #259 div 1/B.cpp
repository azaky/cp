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

#define MAXN 111
int a[MAXN], b[MAXN], rp[MAXN][MAXN], n;

bool huba(int i, int m) {
	if (i == n) {
		return true;
	}
	
	int x = a[i] - min(a[i]-1, m);
	int y = a[i] + min(a[i]-1, m);
	FOR(j, x, y) {
		bool irp = true;
		REP(k, i) {
			if (!rp[b[k]][j]) {
				irp = false;
				break;
			}
		}
		if (irp) {
			b[i] = j;
			bool huba2 = huba(i+1, m-abs(a[i]-b[i]));
			if (huba2) {
				return true;
			}
		}
	}
	return false;
}

int main(){
	FOR(i, 1, 59) {
		FOR(j, 1, 59) {
			rp[i][j] = (__gcd(i, j) == 1);
		}
	}
	
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &a[i]);
	}
	//sort(a, a+n);
	int y = 0;
	REP(i, n) {
		y += a[i] - 1;
	}
	int x = 0;
	while (x < y) {
		int m = (x + y) / 2;
		bool bisa = huba(0, m);
		if (bisa) {
			y = m;
		}
		else {
			x = m + 1;
		}
	}
	assert(huba(0,x));
	REP(i, n) {
		printf("%d ", b[i]);
	}
	puts("");
	
	return 0;
}
