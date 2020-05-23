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

int n, ada[30], cot[30], haha[30];
char s[1111];

int main(){
	scanf("%s%d",s,&n);
	int len = (int)strlen(s);
	REP(i,len){
		if (!ada[s[i]-'a']) ada[s[i]-'a'] = 1;
		cot[s[i]-'a'] ++;
	}
	int total = 0;
	REP(i,26) total += ada[i];
	if (total > n){
		puts("-1");
		return 0;
	}
	FOR(nans,1,1000){
		REP(i,26) haha[i] = cot[i]/nans + ((cot[i]%nans == 0) ? 0 : 1);
		total = 0;
		REP(i,26) total += haha[i];
		if (total <= n){
			printf("%d\n",nans);
			REP(i,26) REP(j,haha[i]) printf("%c",'a'+i);
			REP(i,n-total) printf("z");
			printf("\n");
			return 0;
		}
	}
	
	return 0;
}
