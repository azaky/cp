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
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 5555
int n, m, a[MAXN][MAXN], c[MAXN][MAXN], last, ans;
char s[MAXN][MAXN];

int main(){
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%s",s[i]);
	FOR(i,1,n) FOR(j,1,m) a[i][j] = s[i-1][j-1] == '1';
	FOR(i,1,n){
		last = 0;
		FOR(j,1,m){
			if (a[i][j] == 1){
				if (a[i][j-1] == 0) last = j;
				c[last][j] ++;
			}
		}
	}
	FORD(i,m,2){
		FOR(j,2,i){
			c[j][i] += c[j-1][i];
//			printf("c[%d][%d] = %d\n",i,j,c[i][j]);
		}
	}
	
	ans = 0;
	FOR(i,1,m) FOR(j,i,m) MX(ans,(j-i+1)*c[i][j]);
	printf("%d\n",ans);
	
	return 0;
}
