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
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

#define MAXN 55
int n, a[MAXN], p, sum, v[MAXN];
double dp[MAXN][MAXN][MAXN], f[MAXN], ans = 0;

double fact(int k){
	if (k < 0) return 0.;
	if (k == 0) return 1.;
	if (v[k]) return f[k];
	v[k] = 1; return f[k] = (double)k * fact(k-1);
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]), sum += a[i];
	scanf("%d",&p);
	if (sum <= p){
		printf("%d.0000\n",n);
		return 0;
	}
	FOR(k,1,n){
		//k is the stopper
		RESET(dp,0);
		//dp[i][t][total]
		dp[0][0][0] = 1.;
		FOR(i,1,n){
			if (i == k) continue;
			FOR(t,1,i){
				FOR(total,a[i],p){
					FOR(j,t-1,i-1){
						dp[i][t][total] += (double)t * dp[j][t-1][total-a[i]];
					}
				}
			}
		}
//		printf("=== stopper = %d ===\n",k);
//		double tot = 0.;
		FOR(total,p-a[k]+1,p){
			FOR(i,1,n) FOR(t,0,i){
//				tot += (double)t * dp[i][t][total] * fact(n-t-1);
				ans += (double)t * dp[i][t][total] * fact(n-t-1) / fact(n);
			}
		}
//		printf("%.5lf\n\n",tot);
	}
	printf("%.17lf\n",ans);
	
	return 0;
}
