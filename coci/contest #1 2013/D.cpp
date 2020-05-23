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

#define MAXN 300300
int n, k, c[MAXN];
pii a[MAXN];

int main(){
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d%d",&a[i].A,&a[i].B);
	sort(a,a+n); reverse(a,a+n);
	REP(i,k) scanf("%d",&c[i]);
	sort(c,c+k); reverse(c,c+k);
	ll ans = 0;
	int idk = 0;
	priority_queue <int> jewel;
	REP(i,n){
		if (idk < k && a[i].A <= c[idk]){
			idk++;
			ans += (ll) a[i].B;
			jewel.push(-a[i].B);
		}
		else if (!jewel.empty()){
			if (a[i].B + jewel.top() > 0){
				ans += (ll)(a[i].B + jewel.top());
				jewel.pop();
				jewel.push(-a[i].B);
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
