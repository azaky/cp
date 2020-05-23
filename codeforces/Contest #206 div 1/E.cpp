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

ll x;
//int v[111][111], dp[111][111];
int l[111][111];
vector<int> mem[111];
map<ll,int> dp, v;

int calc(ll x, int p, int red){
	/* removing last p digits of x, minus red */
//	printf("x = %I64d, p = %d, red = %d\n",x,p,red);
	if (x < 0) return 0;
	if (x == 0) return 1;
//	if (v[p][red]) return dp[p][red];
//	v[p][red] = 1;
	if (v[x]) return dp[x];
	v[x] = 1;
	dp[x] = 0;
	REP(i,10){
		if (l[i][(int)(x%10LL)]){
			dp[x] |= calc(x/10LL - (ll)i,p+1,i);
		}
	}
	return dp[x];
}

int main(){
	int pos[100] = {0};
	REP(i,7) REP(j,7-i){
		if (!pos[4*i+7*j]){
			pos[4*i+7*j] = 1;
			REP(_i,i) mem[4*i+7*j].PB(4);
			REP(_i,j) mem[4*i+7*j].PB(7);
			REP(_i,6-i-j) mem[4*i+7*j].PB(0);
		}
	}
//	REP(i,100) if (pos[i]) printf("%d ",i);
	REP(i,100) if (pos[i]){
		l[i/10][i%10] = 1;
	}
	
	ll __x = 1;
//	while (__x){RESET(v,0); if (!calc(__x,0,0)){ printf("%I64d\n",__x);}__x++;}
	
	
	
	int _n; scanf("%d",&_n);
	REP(_i,_n){
		ll x;
		scanf("%I64d",&x);
		v.clear();
		dp.clear();
		if (!calc(x,0,0)){
			puts("-1");
		}
		else {
			/* recursive backtracking */
			vector<ll> ans(6);
			ll total = 0, ten = 1LL, _x = x;
			int p = 0;
			while (total != _x){
				REP(i,10){
					if (l[i][(int)(x%10LL)] && calc(x/10LL - (ll)i,p+1,i)){
						REP(j,6) ans[j] += ten * mem[10*i+(int)(x%10LL)][j];
						x = x/10LL - (ll)i;
						break;
					}
				}
//				printf("[");REP(i,6) printf("%I64d ",ans[i]); puts("]");
				p++; ten *= 10LL;
				total = 0; REP(i,6) total += ans[i];
//				printf("total = %I64d, _x = %I64d\n",total,_x);
			}
			REP(i,6) printf("%I64d ",ans[i]); puts("");
		}
	}
	
	return 0;
}
