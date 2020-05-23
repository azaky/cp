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

#define MAXN 1011
int n,m,k,a[MAXN][MAXN];
char hor[MAXN][MAXN], ver[MAXN][MAXN];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	REP(i,2*n-1){
		if (i%2) scanf("%s",ver[i/2]); else scanf("%s",hor[i/2]);
	}
	if (k == 1){
		int cn = 0, ce = 0;
		REP(i,n) REP(j,m-1) if (hor[i][j] == 'N') cn++; else ce++;
		REP(i,n-1) REP(j,m) if (ver[i][j] == 'N') cn++; else ce++;
//		printf("N = %d, E = %d\n",cn,ce);
		if (ce*4 < (cn+ce)*3) puts("NO");
		else {
			puts("YES");
			REP(i,n){REP(j,m) printf("1 "); puts("");}
		}
		return 0;
	}
	if (n < m){
		REP(i,n){
			a[i][0] = 1;
			REP(j,m-1){
				if (hor[i][j] == 'E') a[i][j+1] = a[i][j]; else a[i][j+1] = 3-a[i][j];
			}
			if (i == 0) continue;
			int un = 0;
			REP(j,m) if ((a[i][j] == a[i-1][j] && ver[i-1][j] == 'N') || (a[i][j] != a[i-1][j] && ver[i-1][j] == 'E')) un++;
			if (un > m-un){
				REP(j,m) a[i][j] = 3-a[i][j];
			}
		}
	}
	else {
		REP(i,m){
			a[0][i] = 1;
			REP(j,n-1){
				if (ver[j][i] == 'E') a[j+1][i] = a[j][i]; else a[j+1][i] = 3-a[j][i];
			}
			if (i == 0) continue;
			int un = 0;
			REP(j,n) if ((a[j][i] == a[j][i-1] && hor[j][i-1] == 'N') || (a[j][i] != a[j][i-1] && hor[j][i-1] == 'E')) un++;
			if (un > n-un){
				REP(j,n) a[j][i] = 3-a[j][i];
			}
		}
	}
	puts("YES");
	REP(i,n){REP(j,m) printf("%d ",a[i][j]); puts("");}
	
	return 0;
}
