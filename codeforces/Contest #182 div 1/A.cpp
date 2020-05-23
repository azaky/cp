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

int n, a[1111], sum;

int main(){
	scanf("%d",&n);
	REP(i,2*n-1) scanf("%d",&a[i]);
	sort(a,a+2*n-1);
	if (n % 2 == 0){
		REP(i,n-1){
			if (a[2*i]+a[2*i+1] > 0) break;
			else a[2*i] *= -1, a[2*i+1] *= -1;
		}
	}
	else {
		REP(i,2*n-1) if (a[i] > 0) break; else a[i] *= -1;
	}
	sum = 0;
	REP(i,2*n-1) sum += a[i];
	printf("%d\n",sum);
	
	return 0;
}
