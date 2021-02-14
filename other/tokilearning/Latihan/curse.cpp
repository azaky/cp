#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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

int n, m, b, a[111][111];
pii sum[111][111], ans;

int main(){
	scanf("%d%d%d",&n,&m,&b);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	FOR(i,1,n) FOR(j,1,m){
		pii x = MP(a[i][j] == 9999 ? 0 : a[i][j],a[i][j] == 9999 ? 1 : 0);
		sum[i][j].A = sum[i-1][j].A + sum[i][j-1].A + x.A - sum[i-1][j-1].A;
		sum[i][j].B = sum[i-1][j].B + sum[i][j-1].B + x.B - sum[i-1][j-1].B;
	}
	ans = MP(0,b);
	FOR(i,1,n) FOR(i1,i,n) FOR(j,1,m) FOR(j1,j,m){
		pii x;
		x.A = sum[i1][j1].A + sum[i-1][j-1].A - sum[i1][j-1].A - sum[i-1][j1].A;
		x.B = sum[i1][j1].B + sum[i-1][j-1].B - sum[i1][j-1].B - sum[i-1][j1].B;
		if (x.B <= b){
			if (x.A > ans.A || (x.A == ans.A && x.B < ans.B)) ans = x;
		}
	}
	printf("%d %d\n",ans.A,ans.B);
	
	return 0;
}
