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

#define MAXN 200200
int ntc, n, bit[MAXN], a[MAXN], ans[MAXN];

void update(int k, int val){for (int x = k; x <= n; x += (x & -x)) bit[x] += val;}
int query(int k){int sum = 0; for (int x = k; x > 0; x -= (x & -x)) sum += bit[x]; return sum;}

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d",&n);
		FOR(i,1,n) scanf("%d",&a[i]);
		FOR(i,0,n) bit[i] = 0;
		FOR(i,1,n) update(i,1);
		FORD(i,n,1){
			int l = 1, r = n, m = (l+r)>>1, pos = i-a[i];
			while (l < r){
				if (query(m) < pos) l = m+1; else r = m;
				m = (l+r)>>1;
			}
			update(m,-1);
			ans[i] = m;
		}
		FOR(i,1,n-1) printf("%d ",ans[i]); printf("%d\n",ans[n]);
	}
	return 0;
}
