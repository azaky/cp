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
#define REPD(i,n) for (int i = n-i; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) (s.find(a) != s.end())

/* -------------- end of azaky's template -------------- */

const double PI = 3.1415926535897932384626433832795;

int n;
double x,y,ans;
vector<double> angle;

int main(){
	scanf("%d",&n);
	REP(i,n){
		scanf("%lf%lf",&x,&y);
		angle.pb(atan2(y,x));
	}
	sort(angle.begin(),angle.end());
	ans = 0.0;
	REP(i,n-1) if (angle[i+1]-angle[i] > ans) ans = angle[i+1]-angle[i];
	if (angle[0]+ 2*PI -angle[n-1] > ans) ans = 2*PI + angle[0] - angle[n-1];
	printf("%.17lf\n",360.-(ans * 180. / PI));
		
	
	return 0;
}
