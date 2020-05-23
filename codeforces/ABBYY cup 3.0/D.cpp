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

#define MOD 1000000007LL
int n, cot[1111111];
vector<int> a;

int main(){
/*
	scanf("%d",&n);
	REP(i,n) a.PB(i);
	do {
		int step = 0;
		vector<int> b;
		REP(i,n) b.PB(i);
		REP(i,n){
			if (a[i] == b[i]) continue;
			FOR(j,i+1,n-1) if (a[i] == b[j]){
				step++;
				swap(b[i],b[j]);
				break;
			}
		}
		cot[step]++;
	} while (next_permutation(ALL(a)));
	FOR(step,0,100) if (cot[step]) printf("%d STEPS = %d ways\n",step,cot[step]);
	
	return 0;
*/
	fact[0] = 1LL;
	FOR(i,1,1000005) fact[i] = (fact[i-1] * (ll)i)%MOD;
	scanf("%d",&n);
	REP(i,n){
		int x; scanf("%d",&x);
		if (x) a.PB(x);
	}
	n = SZ(a);
	sort(ALL(a));
	if (a[0] == 2){
		printf("%I64d\n",fact[n]);
	}
	else {
		
	}
	
	
	return 0;
}
