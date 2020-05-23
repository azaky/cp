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

int ntc, n, a[111], total;
double p[111], q[111], lama[11111], baru[11111], ans;

int main(){
	scanf("%d",&ntc);
	REP(itc,ntc){
		scanf("%d",&n);
		REP(i,n) scanf("%d",&a[i]);
		REP(i,n) scanf("%lf",&p[i]);
		REP(i,n) p[i] /= 100.;
		REP(i,n) q[i] = 1-p[i];
		total = 0;
		REP(i,n){
			if (i == 0){
				REP(j,a[i]+1) baru[j] = 0.;
				baru[a[i]] = p[i];
				baru[0] = q[i];
			}
			else {
				REP(j,total+a[i]+1) baru[j] = 0.;
				REP(j,total+1) if (lama[j] != 0){
					baru[j] += lama[j] * q[i];
					baru[j+a[i]] += lama[j] * p[i];
				}
			}
			total += a[i];
			REP(j,total+1) lama[j] = baru[j];
		}
		ans = 0.;
		REP(i,total+1) if (i >= total-i) ans += baru[i];
		printf("%.17lf\n",ans);
	}
	
	return 0;
}
