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

#define MAXN 50
#define MOD 1000000007
int n, m, a[MAXN][MAXN];
vector<pair<int,pii> > ans;

void query(int t, int rc, int v){
	ans.PB(MP(t,MP(rc,v)));
	if (t == 1) FOR(i,1,n) a[i][rc] = (a[i][rc]+v)%MOD;
	else if (t == 2) FOR(i,1,n) a[i][rc] = (a[i][rc]-v+MOD)%MOD;
	else if (t == 3) FOR(i,1,m) REP(j,v) a[rc][i] = (a[rc][i]+a[rc][i])%MOD;
	else puts("Yafi Jelek");
}

int minc(int c){
	int ret = a[1][c];
	FOR(i,2,n) MN(ret,a[i][c]);
	return ret;
}
int maxc(int c){
	int ret = a[1][c];
	FOR(i,2,n) MX(ret,a[i][c]);
	return ret;
}

void yafi(int c){
	int vmax, vmin;
	while (vmax = maxc(c)){
		if (minc(c) == 0){
			//cari nilai tambah yang ga ngasilin 0
			FOR(v,1,n+1){
				bool nol = false;
				FOR(i,1,n) if ((a[i][c]+v)%MOD == 0) nol = true;
				if (!nol){
					query(1,c,v);
					break;
				}
			}
			continue;
		}
		FOR(i,1,n){
			int k = 0, _a = a[i][c];
			while (_a <= vmax){
				k++;
				_a += _a;
			}
			k--;
			if (k != 0) query(3,i,k);
		}
		vmin = minc(c);
		if (vmin == vmax) query(2,c,vmax);
		else query(2,c,vmin-1);
	}
}

int main(){
	char subsoal[11]; scanf("%s %d",subsoal,&n);
	scanf("%d%d",&n,&m);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	FOR(c,1,m) yafi(c);
	
	printf("%d\n",SZ(ans));
	REP(i,SZ(ans)) printf("%d %d %d\n",ans[i].A,ans[i].B.A,ans[i].B.B);
	
	return 0;
}
