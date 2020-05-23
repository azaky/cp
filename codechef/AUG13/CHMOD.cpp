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

const int p[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

#define MAXN 100100
int n, a[MAXN], lastzero[MAXN], c[MAXN][30], q, l, r, m;

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	lastzero[0] = 0;
	FOR(i,1,n){
		if (a[i] == 0){
			lastzero[i] = i; continue;
		}
		lastzero[i] = lastzero[i-1];
		int x = a[i];
		REP(j,25){
			c[i][j] = c[i-1][j];
			while (x % p[j] == 0){
				x /= p[j];
				c[i][j]++;
			}
		}
	}
	scanf("%d",&q);
	REP(it,q){
		scanf("%d%d%d",&l,&r,&m);
		if (lastzero[r] >= l){
			puts("0"); continue;
		}
		ll ans = 1;
		REP(j,25){
			ll pp = c[r][j] - c[l-1][j];
			if (!pp) continue;
			ll mul = 1;
			ll t = 0;
			while ((1LL << t) <= pp) t++;
			t--;
			for (; t >= 0; --t){
				mul *= mul;
				mul %= m;
				if (pp & (1LL << t)){
					mul *= (ll)p[j];
					mul %= m;
				}
			}
			ans *= mul;
			ans %= m;
//			printf("p = %d, ans = %I64d\n",p[j],ans);
		}
		printf("%I64d\n",ans%m);
	}
	
	return 0;
}
