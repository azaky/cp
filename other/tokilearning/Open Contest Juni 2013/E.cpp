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

#define MAXN 200005
int next[MAXN][26];
char s[MAXN], x[MAXN];

int main(){
	scanf("%s",s);
	int n = strlen(s);
	REP(i,26) next[n][i] = -1;
	REPD(i,n){
		REP(j,26) next[i][j] = next[i+1][j];
		next[i][s[i]-'a'] = i;
	}
	int ntc;
	scanf("%d",&ntc);
	int ans = 0;
	REP(itc,ntc){
		scanf("%s",x);
		int nx = strlen(x);
		int now = -1;
		bool possible = true;
		REP(i,nx){
			now = next[now+1][x[i]-'a'];
			if (now == -1){
				possible = false;
				break;
			}
		}
		if (possible) ans++;
	}
	printf("%d\n",ans);
	
	return 0;
}
