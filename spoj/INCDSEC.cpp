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

#define MAXN (1 << 14)
#define MAXK 52
#define MOD 5000000
int a[MAXN+1], n, k, u, bit[MAXK][MAXN+1], sum[MAXK][MAXN+1], last[MAXN];
PII b[MAXN+1];

void add(int len, int x, int val){for (; x <= MAXN; x += (x & -x)) bit[len][x] = (bit[len][x] + val) % MOD;}
int query(int len, int x){if (len == 0) return 1; int sum = 0; for (; x > 0; x -= (x & -x)) sum = (sum + bit[len][x]) % MOD; return sum;}

int main(){
	scanf("%d%d",&n,&k);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n) b[i] = mp(a[i],i);
	sort(b+1,b+n+1);
	b[0].fi = -1; u = 0;
	FOR(i,1,n){
		if (b[i].fi > b[i-1].fi) u++;
		a[b[i].se] = u;
	}
	FOR(i,1,n) last[a[i]] = -1;
	FOR(i,1,n){
		REP(j,k){
			sum[j+1][i] = sum[j+1][i-1];
			int temp = (last[a[i]] == -1) ? query(j,a[i]-1) : sum[j][i]-sum[j][last[a[i]]-1];
			add(j+1,a[i],temp);
			sum[j+1][i] += temp;
		}
		last[a[i]] = i;
	}
	printf("%d\n",query(k,n));
	
	return 0;
}
