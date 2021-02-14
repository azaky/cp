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

int ntc, n, h[55], d[55];

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%d",&n);
		REP(i,n) scanf("%d",&h[i]);
		REP(i,n) scanf("%d",&d[i]);
		if (n == 1){
			if (h[0] < d[0]) puts("-1"); else printf("%d\n",h[0]-d[0]);
		}
		else if (n == 2){
			if (h[0] + h[1] != d[0] + d[1]) puts("-1"); else printf("%d\n",abs(h[0]-d[0]));
		}
		else {
			int th = 0, td = 0;
			REP(i,n) th += h[i];
			REP(i,n) td += d[i];
			if (th > td || (td-th)%(n-2) != 0) puts("-1");
			else {
				REP(i,n) h[i] += (td-th)/(n-2);
				bool bisa = true;
				REP(i,n) if (d[i] > h[i] || (h[i]-d[i])%2 != 0) bisa = false;
				if (bisa) printf("%d\n",(td-th)/(n-2)); else puts("-1");
			}
		}
	}
	
	return 0;
}
