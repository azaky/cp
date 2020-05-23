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

#define MAXN 111
int ntc, n, m, k;
ll a[MAXN][MAXN], sum[MAXN][MAXN], v[MAXN], sumv[MAXN];

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d%d",&n,&m,&k);
		FOR(i,1,n) FOR(j,1,m) scanf("%lld",&a[i][j]);
		FOR(i,1,n) FOR(j,1,m) sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		int area = 0; ll p = 0;
		FOR(x,1,n) FOR(y,x,n){
			FOR(i,1,m) v[i] = sum[y][i]-sum[x-1][i]-sum[y][i-1]+sum[x-1][i-1];
			FOR(i,1,m) sumv[i] = sumv[i-1] + v[i];
			int f = 1, b = 1;
			for (f = 1; f <= m; ++f){
				if (sumv[b]-sumv[f-1] > k) continue;
				while (b < m && sumv[b+1]-sumv[f-1] <= k) b++;
				if ((y-x+1)*(b-f+1) > area){
					area = (y-x+1)*(b-f+1);
					p = sumv[b]-sumv[f-1];
//					printf("Location [%d,%d]..[%d,%d], price = %I64d\n",x,f,y,b,p);
				}
				else if ((y-x+1)*(b-f+1) == area && sumv[b]-sumv[f-1] < p){
					p = sumv[b]-sumv[f-1];
//					printf("Location [%d,%d]..[%d,%d], price = %I64d\n",x,f,y,b,p);
				}
			}
		}
		printf("Case #%d: %d %lld\n",itc,area,p);
	}
	
	return 0;
}
