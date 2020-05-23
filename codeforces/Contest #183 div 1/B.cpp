#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
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
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

//prefefined macros
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

/* -------------- end of azaky's template -------------- */

int main(){
	
	ll n, m, x, y, a, b, d, xx, yy, x1, y1, x2, y2;
	
	cin >> n >> m >> x >> y >> a >> b;
	
	d = __gcd(a,b);
	a /= d; b /= d ;
	
	if ((n/a) < (m/b)){
		xx = (n/a) * a;
		yy = (n/a) * b;
	}
	else {
		xx = (m/b) * a;
		yy = (m/b) * b;
	}
	
	if (x < (xx+1)/2) x1 = 0;
	else if (x + (xx/2) > n) x1 = n-xx;
	else x1 = x - (xx+1)/2;
	x2 = x1 + xx;
	
	if (y < (yy+1)/2) y1 = 0;
	else if (y + (yy/2) > m) y1 = m-yy;
	else y1 = y - (yy+1)/2;
	y2 = y1 + yy;
	
	assert(x2 <= n && y2 <= m && 0 <= x1 && 0 <= y1);
	
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	
	return 0;
}
