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

int n, k, a[5555], d[1111111], ada[1111111];

int main(){
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n);
	REP(i,n) FOR(j,i+1,n-1) d[a[j]-a[i]]++;
	
	int lim = k*(k+1)/2;
	
	FOR(m,n-k,1000001){
		int used = 0;
		for (int i = m; i <= 1000001; i += m) used += d[i];
		if (used <= lim){
			used = 0;
			REP(i,m) ada[i] = 0;
			REP(i,n){
				if (ada[a[i]%m]) used++;
				ada[a[i]%m]++;
			}
			if (used <= k){
				printf("%d\n",m);
				return 0;
			}
		}
	}
	
	return 0;
}
