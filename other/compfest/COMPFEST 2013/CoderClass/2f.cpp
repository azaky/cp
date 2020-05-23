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

int n, a[111111], q;

int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n);
	map<int,int> ada;
	REP(i,n) ada[a[i]] = 1;
	scanf("%d",&q);
	REP(i,q){
		char task = 0; while (task != 'A' && task != 'B' && task != 'C') scanf("%c",&task);
		if (task == 'A'){
			int x;
			scanf("%d",&x);
			printf("%d\n",ada[x]);
		}
		else if (task == 'B'){
			int x;
			scanf("%d",&x);
			printf("%d\n",upper_bound(a,a+n,x)-a);
		}
		else if (task == 'C'){
			int x, y;
			scanf("%d%d",&x,&y);
			if (x > y) swap(x,y);
			printf("%d\n",upper_bound(a,a+n,y)-lower_bound(a,a+n,x));
		}
	}
	
	return 0;
}
