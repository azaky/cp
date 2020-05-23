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

#define MAXK 111
int ntc, n, k, lama[MAXK], baru[MAXK];

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d",&n,&k);
		REP(i,k) lama[i] = baru[i] = 0;
		REP(i,n){
			int x;
			scanf("%d",&x);
			x %= k;
			while (x < 0) x += k;
			if (!i){
				lama[x] = 1;
				continue;
			}
			REP(j,k) baru[j] = 0;
			REP(j,k){
				if (lama[j]){
					baru[(j+x)%k] = 1;
					baru[(j-x+k)%k] = 1;
				}
			}
			REP(j,k) lama[j] = baru[j];
		}
		puts(lama[0] ? "Divisible" : "Not divisible");
	}
	
	return 0;
}
