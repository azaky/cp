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

#define MAXN 1100
int ntc, x, r, c;

int main(int argc, char** argv) {
	if (argc != 1) {
		OPEN(argv[1]);
	}

	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d", &x, &r, &c);
		bool gabriel = false;
		switch (x) {
		case 1:
			gabriel = true;
			break;

		case 2:
			if ((r * c) % 2 == 0) {
				gabriel = true;
			}
			break;

		case 3:
			if (min(r, c) > 1 && (r * c) % 3 == 0) {
				gabriel = true;
			}
			break;

		case 4:
			if ((r * c) % 4 != 0) break;

			if (r > c) swap(r, c);
			if (r == 1) {
				// richard wins
			} else if (r == 2) {
				// richard also wins
			} else if (r == 3) {
				gabriel = true;
			} else {
				gabriel = true;
			}
			break;

		case 5:
			if ((r * c) % 5 != 0) break;

			if (r > c) swap(r, c);
			if (r == 1) {
				// richard wins
			} else if (r == 2) {
				// richard also wins
			} else if (r == 3) {
				if (c > 5) gabriel = true;
			} else {
				gabriel = true;
			}
			break;

		case 6:
			if ((r * c) % 6 != 0) break;

			if (r > c) swap(r, c);
			if (r == 1) {
				// richard wins
			} else if (r == 2) {
				// richard also wins
			} else if (r == 3) {
				// richard also wins
			} else {
				gabriel = true;
			}
			break;
		}

		// printf("x = %d, r =  %d, c = %d\n", x, r, c);
		printf("Case #%d: %s\n", itc, gabriel ? "GABRIEL" : "RICHARD");
	}

	return 0;
}