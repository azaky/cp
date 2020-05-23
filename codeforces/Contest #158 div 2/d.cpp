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

vector <PII> black, white;
int n, color, weight, iw = 0, ib = 0;

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%d%d",&color,&weight);
		if (color == 1) black.pb(mp(weight,i)); else white.pb(mp(weight,i));
	}
	REP(i,n-1){
		if ((white[iw].fi < black[ib].fi) || (white[iw].fi == black[ib].fi && iw+1 != white.size())){
			printf("%d %d %d\n",white[iw].se,black[ib].se,white[iw].fi);
			black[ib].fi -= white[iw++].fi;
		}
		else{
			printf("%d %d %d\n",white[iw].se,black[ib].se,black[ib].fi);
			white[iw].fi -= black[ib++].fi;
		}
	}
	return 0;
}
