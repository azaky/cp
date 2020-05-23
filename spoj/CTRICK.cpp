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

#define MAXN (1 << 15)
int ntc, n, bit[MAXN+1], ans[MAXN+1], pos, l, r, mid;
void update(int k){for(int x = k; x <= MAXN; bit[x]++, x += (x & -x));}
int query(int k){int sum = 0; for(int x = k; x > 0; sum += bit[x], x -= (x & -x)); return sum;}

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%d",&n);
		FOR(i,0,MAXN) bit[i] = 0;
		pos = 0;
		FOR(i,1,n){
			pos = (pos - query(pos) + i)%(n-i+1)+1;
			l = 1; r = n;
			while (true){
				mid = (l+r)/2;
				if (mid-query(mid) < pos) l = mid+1;
				else if (mid-query(mid) > pos || query(mid)-query(mid-1) == 1) r = mid-1;
				else {pos = mid; ans[mid] = i; update(mid); break;}
			}
		}
		FOR(i,1,n-1) printf("%d ",ans[i]); printf("%d\n",ans[n]);
	}
	return 0;
}
