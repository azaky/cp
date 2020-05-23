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

#define MAXN 222222

LL nstep, n, x[MAXN], s[MAXN], task, a, k, add, app[MAXN];

int main(){
	cin >> nstep;
	n = 1;
	x[1] = s[1] = 0;
	REP(step,nstep){
		cin >> task;
		if (task == 1){
			cin >> a >> k;
			a = min(a,n);
			add += a*k;
			app[a] += k;
		}
		if (task == 2){
			cin >> k;
			x[++n] = k;
			s[n] = s[n-1] + x[n];
			app[n] = 0;
		}
		if (task == 3){
			add -= app[n];
			app[n-1] += app[n];
			n--;
		}
		double avg = (double)(s[n]+add)/(double)n;
		printf("%.15lf\n",avg);
	}
	
	return 0;
}
