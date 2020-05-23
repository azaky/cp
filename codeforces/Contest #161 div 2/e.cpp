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

#define MAXN 1010
#define MAXT 2010
int n, m, k, a[MAXN][MAXN], ma, mb;
LL sum1[MAXT][MAXT], sum2[MAXT][MAXT], f[MAXN][MAXN];

void precompute(){
	/* / */
	FOR(s,2,m+n) for(int i = s > m ? s-m : 1, j = s-i; i <= n && j > 0; ++i, --j) sum1[s][i] = sum1[s][i-1] + (LL) a[i][j];
	/* \ */
	FOR(d,1-m,n-1) for(int i = d > 0 ? d+1 : 1, j = i-d; i <= n && j <= m; ++i, ++j) sum2[d+1000][i] = sum2[d+1000][i-1] + (LL) a[i][j];
}
LL ring(int i, int j, int s){
	if (s == 0) return (LL)a[i][j];
	LL ret = 0;
	ret += sum1[i+j-s][i] - sum1[i+j-s][i-s];
	ret += sum2[i+s-j+1000][i+s] - sum2[i+s-j+1000][i];
	ret += sum1[i+j+s][i+s-1] - sum1[i+j+s][i-1];
	ret += sum2[i-s-j+1000][i-1] - sum2[i-s-j+1000][i-s-1];
	//printf("RING [%d][%d] {%d} = %I64d\n",i,j,s,ret);
	return ret;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	precompute();
	FOR(i,k,n-k+1) FOR(j,k,m-k+1){
		f[i][j] = 0;
		REP(size,k) f[i][j] += (LL)(k-size)*ring(i,j,size);
	}
	ma = mb = k;
	FOR(i,k,n-k+1) FOR(j,k,m-k+1) if (f[i][j] > f[ma][mb]) ma = i, mb = j;
	printf("%d %d\n",ma,mb);
	
	return 0;
}
