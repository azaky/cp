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

#define MAXN 6000
int n, m, s[MAXN], ans = 0;
double pos[MAXN];

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d%lf",&s[i],&pos[i]);
	FOR(t,1,m){
		int same[MAXN], diff[MAXN], k = 1;
		RESET(same,0); RESET(diff,0);
		FOR(i,1,n){
			if (s[i] != t && s[i] != 0) diff[k]++;
			else if (s[i] == t){
				same[k]++;
				if (s[i+1] != t) k++;
			}
		}
		k--;
		FOR(i,1,k) diff[i] = diff[i-1] + diff[i], same[i] = same[i-1] + same[i];
		int best = 0;
		FOR(i,0,k) if (diff[i]+same[k]-same[i] < diff[best]+same[k]-same[best] || (diff[i]+same[k]-same[i] == diff[best]+same[k]-same[best] && diff[i] > diff[best])) best = i;
		int _k = 1;
		//printf("%d\n",k);
		//FOR(i,1,k) printf(" ---> (%d,%d)\n",diff[i],same[i]);
		//printf("%d : %d\n",k,best);
		ans += diff[best]+same[k]-same[best];
		FOR(i,1,n){
			if (s[i] == t){
				if (s[i+1] != t) _k++;
				s[i] = 0;
			}
			else if (_k <= best) s[i] = 0;
		}
		//FOR(i,1,n) printf("%d ",s[i]); printf("%d\n",ans);
	}
	printf("%d\n",ans);
	return 0;
}
