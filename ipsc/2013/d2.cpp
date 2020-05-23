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

#define MOD 65521
#define MAXX 1000000
#define BON (1<<26)

int ntc, n;
char s[3000];
int next[3000][30], dp[BON+5], ans[BON+5];

int main(){
	scanf("%d",&ntc);
	REP(itc,ntc){
		scanf("%s",s);
		n = strlen(s);
		printf("TC[%d]-> n = %d\n",itc+1,n);
		continue;
		REP(i,n){
			REP(j,26) next[i][j] = -1;
			FORD(j,n-1,i) next[i][s[j]-'a'] = j;
		}
		RESET(dp,0); dp[0] = -1;
		bool possible = true;
		REP(mask,BON){
			if (!mask) continue;
			int aha = 0;
			ans[mask] = 0;
			REP(i,26) if ((1<<i)&mask){
				if (next[dp[mask^(1<<i)]+1][i] == -1){
					aha = -1;
					break;
				}
				else MX(aha,next[dp[mask^(1<<i)]+1][i]);
			}
			if (aha == -1){
//				printf("%d\n",mask);
				possible = false; break;
			}
			dp[mask] = aha;
		}
		puts(possible ? "YES" : "NO");
		fprintf(stderr,"TEST %d DONE\n",itc+1);
	}
	
	return 0;
}
