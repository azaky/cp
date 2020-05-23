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

#define MAXN 111111
int n, s[MAXN], a[MAXN], b[MAXN], uua, uub;

int main(){
	srand(time(0));
	scanf("%d",&n);
	REP(i,n) scanf("%d",&s[i]);
//	sort(s,s+n);
FOR(tri,1,10){
	REP(i,n){
		a[i] = (s[i] + rand()%2)/2;
		b[i] = s[i] - a[i];
	}
	map <int,int> ua, ub;
	uua = uub = 0;
	REP(i,n){
		if (ua[a[i]]) uua++;
		ub[a[i]] = 1;
	}
	REP(i,n){
		if (ub[b[i]]) uub++;
		ub[b[i]] = 1;
	}
	int lim = n/3;
	if (n % 3) lim++;
	if (uua > lim || uub > lim){
		continue;
	}
	else{
		puts("YES");
		REP(i,n) printf("%d ",a[i]); puts("");
		REP(i,n) printf("%d ",b[i]); puts("");
		return 0;
	}
}
puts("NO");
	
	return 0;
}
