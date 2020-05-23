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

PII t[1111];
int n;

int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&t[i].fi,&t[i].se);
	sort(t,t+n);
	int k = 0;
	int last = 0;
	int que = 0, maxque = 0;
	while (k < n){
		int time = t[k].fi;
		int add = t[k].se;
		k++;
		while (k < n && t[k].fi == time){
			add += t[k].se;
			k++;
		}
		int sent = min(que,time-last);
		que -= sent;
		que += add;
		if (que > maxque) maxque = que;
		last = time;
	}
	last += que;
	printf("%d %d\n",last,maxque);
	
	return 0;
}
