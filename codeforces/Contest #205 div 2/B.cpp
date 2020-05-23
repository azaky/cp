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

int n, a[1111], c[1111], now, next, ans[1111];

int main(){
	scanf("%d",&n);
	REP(i,2*n) scanf("%d",&a[i]);
	REP(i,2*n) c[a[i]]++;
	now = 1;
	while (true){
		next = 0;
		FOR(i,10,99) if (c[i] > c[next]) next = i;
		if (next == 0) break;
		REP(i,2*n){
			if (a[i] == next){
				ans[i] = now;
				now = 3-now;
			}
		}
		c[next] = 0;
	}
	set<int> s[3];
	REP(i,2*n) s[ans[i]].insert(a[i]);
	printf("%d\n",SZ(s[1])*SZ(s[2]));
	REP(i,2*n) printf("%d ",ans[i]);
	
	return 0;
}
