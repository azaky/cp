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

#define MAXN 222222
int n, p[MAXN], BIT[MAXN];
void update(int k, int v){
	for (int x = k; x <= 2*n; x += (x & -x)) BIT[x] += v;
}
int query(int k){
	int ret = 0; for (int x = k; x > 0; x -= (x & -x)) ret += BIT[x]; return ret;
}

int main(){
	scanf("%d",&n);
	REP(i,n){
		int x, y;
		scanf("%d%d",&x,&y);
		p[x] = y; p[y] = x;
	}
	ll ans1 = 0, ans2 = 0;
	FOR(i,1,2*n){
		if (p[i] > i){
			update(i,1);
		}
		else {
			update(i,1);
			update(p[i],-2);
			ll intersect = (ll)(query(i-1)-query(p[i]));
			ll inside = (ll)(((i - p[i] - 1) - intersect)/2);
			ll outside = (ll)n - 1 - intersect - inside;
//			printf("LINE %d..%d, int = %I64d, in = %I64d, out = %I64d\n",p[i],i,intersect,inside,outside);
			ans1 += inside * outside;
			ans2 += intersect * (inside + outside);
		}
	}
//	cout << ans1 << "---" << ans2 << endl;
	ll nn = (ll)n;
	ll ans = (nn*(nn-1)*(nn-2))/6LL - ans1 - ans2/2LL;
	cout << ans << endl;
	
	return 0;
}
