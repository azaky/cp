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

#define MAXN 1111
int n, v, prev[MAXN], next[MAXN], pos, dp[MAXN], ans[MAXN];
vector<int> tab;

int main(){
	scanf("%d%d",&n,&v);
	FOR(i,1,n){
		int x; scanf("%d",&x);
		prev[i] = x;
		next[x] = i;
	}
	FOR(i,1,n){
		if (prev[i] != 0) continue;
		int now = i, tot = 0, inc = 1;
		while (now != 0){
			tot++;
			if (now == v){
				pos = tot;
				inc = 0;
				break;
			}
			now = next[now];
		}
		if (inc) tab.PB(tot);
	}
	dp[0] = 1;
	REP(i,SZ(tab)) FORD(j,n,tab[i]) if (dp[j-tab[i]]) dp[j] = 1;
	FOR(i,pos,n) if (dp[i-pos]) ans[i] = 1;
	FOR(i,1,n) if (ans[i]) printf("%d\n",i);
	
	return 0;
}
