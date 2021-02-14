#include <vector>
#include <map>
#include <set>
#include <queue>
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
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long LL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

bool winc[10000001], winp[10000001];
int N, c, p, cc[100], pp[100];

int main(){
	cin >> N >> c >> p;
	FOR(i,1,c) cin >> cc[i];
	FOR(i,1,p) cin >> pp[i];
	
	FOR(k,1,N){
		FOR(i,1,c){
			if (cc[i] <= k){
				if (!winp[k-cc[i]]){
					winc[k] = true; break;
				}
			}
		}
		FOR(i,1,p){
			if (pp[i] <= k){
				if (!winc[k-pp[i]]){
					winp[k] = true; break;
				}
			}
		}
	}
	
	puts( winc[N] ? "YA" : "TIDAK" );
	
	return 0;
}
