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
#include <limits>
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
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

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

inline void OPEN(const string &s) {
	freopen((s + ".txt").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 555
#define INF 1000000000
int ntc, n, m, ans,v[MAXN][MAXN][2],dp[MAXN][MAXN][2];
char s[MAXN], a[MAXN][MAXN];

int calcup(int r, int c, int udah){
	if (r < 1 || r > n || c < 1 || c > m) return -INF;
	if (a[r][c] == '#') return -INF;
	if (r == 1 && c == 1){
		if (udah) return -INF; else return 1;
	}
	if (v[r][c][udah]) return dp[r][c][udah];
	v[r][c][udah] = 1;
	
	int ret = -INF;
	MX(ret,1 + calcup(r-1,c,udah));
	MX(ret,1 + calcup(r,c-1,udah));
	if (udah && a[r][c-1] == '.'){
		int cb = 2;
		int nr = r, nc = c-1;
		while (nr <= n){
			MX(ret,cb+calcup(nr,nc-1,0));
			nr++; cb++;
			if (a[nr][nc] == '#') break;
		}
	}
	return dp[r][c][udah] = ret;
}

int calcle(int r, int c, int udah){
	if (r < 1 || r > n || c < 1 || c > m) return -INF;
	if (a[r][c] == '#') return -INF;
	if (r == 1 && c == 1){
		if (udah) return -INF; else return 1;
	}
	if (v[r][c][udah]) return dp[r][c][udah];
	v[r][c][udah] = 1;
	
	int ret = -INF;
	MX(ret,1 + calcup(r-1,c,udah));
	MX(ret,1 + calcup(r,c-1,udah));
	if (udah && a[r-1][c] == '.'){
		int cb = 2;
		int nr = r-1, nc = c;
		while (nc <= m){
			MX(ret,cb+calcup(nr-1,nc,0));
			nc++; cb++;
			if (a[nr][nc] == '#') break;
		}
	}
	return dp[r][c][udah] = ret;
}

int main(){
	OPEN("aaaaaa");
	
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d",&n,&m);
		FOR(i,1,n){
			scanf("%s",s);
			FOR(j,1,m) a[i][j] = s[j-1];
		}
		ans = 0;
		/* dp atas */
		RESET(v,0);
		FOR(i,1,n) FOR(j,1,m){
			MX(ans,calcup(i,j,0));
			MX(ans,calcup(i,j,1));
		}
		FOR(i,1,n) FOR(j,1,m){
			int temp = 1+calcup(i,j-1,0);
			int nr = i, nc = j;
			if (a[nr][nc] == '#') continue;
			while (nr > 0){
				MX(ans,temp);
				temp++; nr--;
				if (a[nr][nc] == '#') break;
			}
		}
/*
		FOR(i,1,n){
			FOR(j,1,m) printf("%3d",calcup(i,j,0) < 0 ? -1 : calcup(i,j,0));
			puts("");
		}
		puts("");
		FOR(i,1,n){
			FOR(j,1,m) printf("%3d",calcup(i,j,1) < 0 ? -1 : calcup(i,j,1));
			puts("");
		}
		puts("");
*/		
		/* dp kiri */
		RESET(v,0);
		FOR(i,1,n) FOR(j,1,m){
			MX(ans,calcle(i,j,0));
			MX(ans,calcle(i,j,1));
		}
		FOR(i,1,n) FOR(j,1,m){
			int temp = 1+calcle(i-1,j,0);
			int nr = i, nc = j;
			if (a[nr][nc] == '#') continue;
			while (nc > 0){
				MX(ans,temp);
				temp++; nc--;
				if (a[nr][nc] == '#') break;
			}
		}
		printf("Case #%d: %d\n",itc,ans);
	}
	
	return 0;
}
