#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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

char s[111111];
int n, zero, ada[111111];
ll ans, k;

int main(){
	scanf("%s",s);
	n = strlen(s);
	ans = 1LL; zero = 0;
	REP(i,n){
		if (s[i] == '?') zero++;
		else if ('0' <= s[i] && s[i] <= '9') continue;
		else ada[s[i]-'A'] = 1;
	}
	k = 10LL;
	REP(i,10) if (ada[i]){
		ans *= k;
		k--;
	}
	if ('A' <= s[0] && s[0] <= 'J'){
		ans /= 10LL; ans *= 9LL;
	}
	if (s[0] == '?'){
		zero--;
		ans *= 9LL;
	}
	printf("%I64d",ans);
	REP(i,zero) printf("0");
	puts("");
	
	return 0;
}
