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
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long LL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

LL n, T, a[111], x, b, y, c, ans = 0;

LL _abs(LL x){ if (x < 0) return -x; return x;}

void taroh(LL p, LL _x, LL _y, LL torque){
	if (n-p+1 < (x-_x) + (y-_y)) return;
	if (p > n){
		if (_x == x && _y == y && _abs(torque) <= T) ++ans;
	}
	else {
		if (_x < x) taroh(p+1,_x+1,_y,torque+a[p]*b);
		if (_y < y) taroh(p+1,_x,_y+1,torque+a[p]*c);
		taroh(p+1,_x,_y,torque);
	}
}

int main(){
	cin >> n >> T;
	FOR(i,1,n) cin >> a[i];
	cin >> x >> b >> y >> c;
	
	taroh(1,0,0,0);
	
	FOR(i,1,x) ans *= i;
	FOR(i,1,y) ans *= i;
	
	cout << ans << endl;
	
	return 0;
}
