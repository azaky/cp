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

#define MAXN 55555
char s[MAXN], ans[MAXN];
int n, a[MAXN], last[MAXN][30], best[MAXN];
pii dp[MAXN][111];

int main(){
	scanf("%s",s);
	n = strlen(s);
	REP(i,n) a[i] = s[i] - 'a';
	//first, with even length
	REP(i,26) last[n][i] = -1;
	REPD(i,n){
		dp[i][2] = MP(last[i+1][a[i]],-1);
		REP(j,26) last[i][j] = last[i+1][j];
		last[i][a[i]] = i;
	}
	int lim = min(100,n);
	int maxlen = 1;
	for (int len = 4; len <= lim; len += 2){
		//collecting info from last table
		best[n] = dp[n][len-2].A = -1;
		REPD(i,n){
			best[i] = -1;
			if (dp[i][len-2].A != -1) best[i] = i;
			if (best[i+1] != -1){
				if (best[i] != -1){
					if (dp[best[i+1]][len-2].A < dp[best[i]][len-2].A) best[i] = best[i+1];
				}
				else best[i] = best[i+1];
			}
		}
		bool dapet = false;
		REP(i,n){
			dp[i][len].A = -1;
			if (best[i+1] == -1) continue;
			if (dp[best[i+1]][len-2].A == n-1) continue;
			if (last[dp[best[i+1]][len-2].A+1][a[i]] != -1){
				dapet = true;
				dp[i][len].A = last[dp[best[i+1]][len-2].A+1][a[i]];
				dp[i][len].B = best[i+1];
			}
		}
//		REP(i,n) printf("dp[%d][%d] = %d\n",i,len,dp[i][len].A);
		if (!dapet) break; else maxlen = len;
	}
	//second, with odd length
	REP(i,n) dp[i][1] = MP(i,-1);
	for (int len = 3; len <= lim; len += 2){
		//collecting info from last table
		best[n] = dp[n][len-2].A = -1;
		REPD(i,n){
			best[i] = -1;
			if (dp[i][len-2].A != -1) best[i] = i;
			if (best[i+1] != -1){
				if (best[i] != -1){
					if (dp[best[i+1]][len-2].A < dp[best[i]][len-2].A) best[i] = best[i+1];
				}
				else best[i] = best[i+1];
			}
		}
		bool dapet = false;
		REP(i,n){
			dp[i][len].A = -1;
			if (best[i+1] == -1) continue;
			if (dp[best[i+1]][len-2].A == n-1) continue;
			if (last[dp[best[i+1]][len-2].A+1][a[i]] != -1){
				dapet = true;
				dp[i][len].A = last[dp[best[i+1]][len-2].A+1][a[i]];
				dp[i][len].B = best[i+1];
			}
		}
//		REP(i,n) printf("dp[%d][%d] = %d\n",i,len,dp[i][len].A);
		if (!dapet) break; else maxlen = max(maxlen,len);
	}
	
	//print palindrom panjangnya maxlen
	int len = maxlen;
	REP(i,n){
		if (dp[i][maxlen].A != -1){
			int now = i;
			int pos = 0;
			while (now != -1){
//				printf("dp[%d][%d] = (%d,%d)\n",now,len,dp[now][len].A,dp[now][len].B);
				ans[pos] = s[now];
				ans[maxlen-pos-1] = s[dp[now][len].A];
				now = dp[now][len].B;
				pos++; len-=2;
			}
			printf("%s\n",ans);
			return 0;
		}
	}
	
	return 0;
}
