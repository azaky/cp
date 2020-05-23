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

#define prec 100
#define MAXN 333

int n, k;
db area, y[MAXN], savedy[prec * MAXN];

db calc(int i, int j){
	return y[i-1] * (1 - (db)j/prec) + y[i] * (db)j/prec;
}

int main(){
	scanf("%d%d",&n,&k);
	REP(i,n){
		FOR(i,0,k) scanf("%lf",&y[i]);
		area = 0.;
		FOR(i,1,k) FOR(j,1,prec){
			db yptop = savedy[(i-1) * prec + j-1];
			db ypnow = calc(i,j-1);
			db ytop = savedy[(i-1) * prec + j];
			db ynow = calc(i,j);
			db yp = fabs(yptop-ypnow);
			db yy = fabs(ytop-ynow);
			
			if (yptop > ypnow){
				if (ytop > ynow){
					//nothing
				}
				else {
					area += 0.5 * yy / (yy + yp) * yy / (db)prec;
				}
			}
			else {
				if (ytop > ynow){
					area += 0.5 * yp / (yy + yp) * yp / (db)prec;
				}
				else {
					area += 0.5 * (yy + yp) / (db) prec;
				}
			}
			MX(savedy[(i-1) * prec + j-1],ypnow);
		}
		MX(savedy[k * prec], calc(k, prec));
		
		printf("%.17lf\n",area);
	}
		
	return 0;
}
