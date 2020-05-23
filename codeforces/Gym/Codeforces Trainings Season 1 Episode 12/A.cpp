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

const db PI = acos(-1.);

int main(){
	db h, r, d1, h1, d2, h2, d, n, x, ans, nh2;
	
	cin >> h >> r >> d1 >> h1 >> d2 >> h2 >> d >> n;

	// case drowning 
	if (d > d1) {
		ans = h1 + h2 + (n * n * n) / (PI * r * r);
		// case sialan
		if (ans < n) {
			ans = (h1 + h2) * PI * r * r / (n * n - PI * r * r);
		}
		
		if (ans > h) {
			ans = h;
		}
		printf("%.17lf\n", ans);
		return 0;
	}
	
	x = n * d / d2;
	nh2 = h2 + (x * n * n) / (PI * r * r);
	if (x > nh2) {
		nh2 = (h2 * PI * r * r) / (PI * r * r - n * n);
		x = nh2 + (n * d - nh2 * d2) / (d1);
	}
	
	if (x > n) {
		x = n;
	}
	ans = h1 + h2 + (x * n * n) / (PI * r * r);
	//case sialan lagi
	if (ans < x) {
		ans = (h1 + h2) * PI * r * r / (n * n - PI * r * r);
	}
	
	if (ans > h) {
		ans = h;
	}
	printf("%.17lf\n", ans);
	
	return 0;
}
