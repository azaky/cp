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

#define MAXN 211111
LL n, k;
LL a, b, c, r;
LL m[MAXN], last[MAXN];

int main(){
	int ntc; cin >> ntc;
	FOR(itc,1,ntc){
		cin >> n >> k;
		cin >> a >> b >> c >> r;
		m[0] = a;
		FOR(i,1,k-1) m[i] = (b*m[i-1]+c) % r;
		RESET(last,-1);
		REP(i,k) if (0 <= m[i] && m[i] <= k) last[m[i]] = i;
		FOR(i,k,2*k){
			FOR(j,0,k) if (last[j] < i-k){
				m[i] = j; break;
			}
			last[m[i]] = i;
		}
		printf("Case #%d: %d\n",itc,(int)m[(n-1-k)%(k+1)+k]);
	}
	
	return 0;
}
