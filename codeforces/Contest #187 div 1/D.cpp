#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
	#define GetTime()	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

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

/* -------------- end of azaky's template -------------- */

int n, x[111111], y[111111];
db ansx, ansy, ans;

int main(){
	scanf("%d",&n);
	REP(i,n){
		int _x, _y;
		scanf("%d%d",&_x,&_y);
		x[i] = _x+_y; y[i] = _x-_y;
	}
	ansx = (db)(*max_element(x,x+n)+*min_element(x,x+n))/2.;
	ansy = (db)(*max_element(y,y+n)+*min_element(y,y+n))/2.;
//	printf("%.2lf %.2lf\n",ansx,ansy);
	REP(i,n){
		MX(ans,min(fabs((db)x[i]-ansx),abs((db)y[i]-ansy)));
	}
	printf("%.17lf\n",(db)ans);
	return 0;
}
