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

#define MAXN 200200

int n, c[MAXN], d[MAXN];

int main(){
	scanf("%d", &n);
	int changes = -1, offset = 0;
	REP(i, n) {
		scanf("%d%d", &c[i], &d[i]);
	}
	REP(i, n - 1) {
		if (d[i] != d[i + 1]) {
			changes = i;
			break;
		} else {
			offset += c[i];
		}
	}

	if (changes == -1) {
		if (d[0] == 2) {
			// always div 2
			int cur = 0, maks = 0;
			REP(i, n) {
				cur += c[i];
				MX(maks, cur);
			}
			printf("%d\n", 1899 + cur - maks);
		} else {
			puts("Infinity");
		}
	} else {
		// brute force?
		int l, r;
		if (d[changes] == 1) {
			// 0 ... offset -> offset + c[i]
			// x ... x + offset -> x + offset + c[i]
			// x + offset >= 1900 <=> x >= 1900 - offset
			// x + offset + c[i] <= 1899 <=> x <= 1899 - offset - c[i]
			l = 1900 - offset;
			r = 1899 - offset - c[changes];
		} else {
			// 0 ... offset -> offset + c[i]
			// x ... x + offset -> x + offset + c[i]
			// x + offset <= 1899 <=> x <= 1899 - offset
			// x + offset + c[i] >= 1900 <=> x >= 1900 - offset - c[i]
			l = 1900 - offset - c[changes];
			r = 1899 - offset;
		}
		if (r < l) {
			puts("Impossible");
		} else {
			bool found = false;
			int ans = -2000000000;
			FOR(x, l, r) {
				bool valid = true;
				int cur = x;
				REP(i, n) {
					if (d[i] == 1 && cur <= 1899) valid = false;
					if (d[i] == 2 && cur >= 1900) valid = false;
					cur += c[i];
				}
				if (valid) {
					ans = cur;
					found = true;
				}
			}
			if (found) {
				printf("%d\n", ans);
			} else {
				puts("Impossible");
			}
		}
	}
	
	return 0;
}