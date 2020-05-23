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

db dist(pii a){
	db x = (db)a.A, y = (db)a.B;
	return sqrt(x*x + y*y);
}

int main(){
	int l, w, n;
	pii c, t;
	scanf("%d %d %d %d %d %d %d",&l, &w, &c.A, &c.B, &t.A, &t.B, &n);
	if (!l && !w && !c.A && !c.B && !t.A && !t.B && !n) return 0;
	map<pii,int> gue;
	db ans = 1e30;
	FOR(d,0,n){
		FOR(x,-d,d){
			int y, dd;
			y = d - abs(x);
			pii now, _now;
			if (x % 2 == 0) now.A = x*l + t.A;
				else now.A = x*l + l - t.A;
			if (y % 2 == 0) now.B = y*w + t.B;
				else now.B = y*w + w - t.B;
//			printf("[%d,%d] = (%d,%d)\n",x,y,now.A,now.B);
			now.A -= c.A;
			now.B -= c.B;
			_now = now;
			dd = __gcd(abs(now.A),abs(now.B));
			now.A /= dd; now.B /= dd;
			if (d == n && !gue[now]){
				MN(ans,dist(_now));
			}
			gue[now] = 1;
			y = abs(x) - d;
			if (x % 2 == 0) now.A = x*l + t.A;
				else now.A = x*l + l - t.A;
			if (y % 2 == 0) now.B = y*w + t.B;
				else now.B = y*w + w - t.B;
//			printf("[%d,%d] = (%d,%d)\n",x,y,now.A,now.B);
			now.A -= c.A;
			now.B -= c.B;
			_now = now;
			dd = __gcd(abs(now.A),abs(now.B));
			now.A /= dd; now.B /= dd;
			if (d == n && !gue[now]){
				MN(ans,dist(_now));
			}
			gue[now] = 1;
		}
	}
	printf("%.3lf\n",ans);
	
	main();
}
