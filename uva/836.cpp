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

#define MAXN 1111
int n,ans, a[MAXN][MAXN], sum[MAXN][MAXN];
char s[MAXN];

int main(){
	int ntc;
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%s",s);
		n = strlen(s);
		FOR(i,1,n) a[1][i] = s[i-1]-'0';
		FOR(i,2,n){
			scanf("%s",s);
			FOR(j,1,n) a[i][j] = s[j-1]-'0';
		}
		FOR(i,1,n) FOR(j,1,n) sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		ans = 0;
		FOR(i,1,n) FOR(i1,i,n) FOR(j,1,n) FOR(j1,j,n){
			if (sum[i1][j1]-sum[i1][j-1]-sum[i-1][j1]+sum[i-1][j-1] == (i1-i+1)*(j1-j+1))
				MX(ans,sum[i1][j1]-sum[i1][j-1]-sum[i-1][j1]+sum[i-1][j-1]);
		}
		cout << ans << endl;
//		puts("");
		if (itc != ntc) puts("");
	}
	return 0;
}
