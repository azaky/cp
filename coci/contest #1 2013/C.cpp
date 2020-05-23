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
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
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
int n, a[MAXN][MAXN], s[MAXN][MAXN], cx[MAXN*MAXN], cy[MAXN*MAXN];

int sum(int rx, int cx, int ry, int cy){
	return s[ry][cy] - s[ry][cx-1] - s[rx-1][cy] + s[rx-1][cx-1];
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n) FOR(j,1,n) scanf("%d",&a[i][j]);
	FOR(i,1,n) FOR(j,1,n) s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
	ll ans = 0;
	FOR(r,1,n-1) FOR(c,1,n-1){
		int nx = 0, ny = 0;
		FOR(i,1,r) FOR(j,1,c) cx[nx++] = sum(i,j,r,c);
		sort(cx,cx+nx);
		FOR(i,r+1,n) FOR(j,c+1,n) ans += (ll)(upper_bound(cx,cx+nx,sum(r+1,c+1,i,j))-lower_bound(cx,cx+nx,sum(r+1,c+1,i,j)));
		FOR(i,r+1,n) FOR(j,1,c) cy[ny++] = sum(r+1,j,i,c);
		sort(cy,cy+ny);
		FOR(i,1,r) FOR(j,c+1,n) ans += (ll)(upper_bound(cy,cy+ny,sum(i,c+1,r,j))-lower_bound(cy,cy+ny,sum(i,c+1,r,j)));
	}
	cout << ans << endl;
	
	return 0;
}
