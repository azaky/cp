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

const int coin[] = {5,10,20,50,100,200};
#define INF 1000000000
int a[10], dpseller[1000], dpbuyer[1000], ans, price;

int main(){
	REP(i,6) scanf("%d",&a[i]);
	int total = 0;
	REP(i,6) total += a[i];
	if (total == 0) return 0;
	//count dp for seller
	FOR(i,1,700) dpseller[i] = INF;
	dpseller[0] = 0;
	REP(i,6){
		FOR(j,coin[i],700){
			MN(dpseller[j],dpseller[j-coin[i]]+1);
		}
	}
	//count dp for buyer
	FOR(i,1,700) dpbuyer[i] = INF;
	dpbuyer[0] = 0;
	REP(i,6){
		REP(j,a[i]){
			FORD(k,700,coin[i]){
				MN(dpbuyer[k],dpbuyer[k-coin[i]]+1);
			}
		}
	}
//	for (int i = 5; i < 200; i += 5) printf("[%d %d] ",i,dpbuyer[i]);
//	puts("\n");
//	for (int i = 5; i < 200; i += 5) printf("[%d %d] ",i,dpseller[i]);
	double _price;
	scanf("%lf",&_price);
	price = (int)round(100.*_price);
//	printf("\n\n%d\n",price);
	int ans = INF;
	FOR(i,price,700){
		MN(ans,dpbuyer[i]+dpseller[i-price]);
	}
	printf("%3d\n",ans);
	
	main();
}
