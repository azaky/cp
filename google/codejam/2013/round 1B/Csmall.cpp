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
#include <cassert>
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

const int NW = 521196;

char word[NW+5][15];
char s[55];
int len[NW+5], ntc, n, dp[55][55], ans;

int main(){
	FILE *dict = fopen("dictionary.txt","r");
	REP(i,NW) fscanf(dict,"%s",word[i]);
	REP(i,NW) len[i] = strlen(word[i]);
	fclose(dict);
	
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%s",s);
		n = strlen(s);
		FOR(i,0,n) FOR(j,0,n) dp[i][j] = 1000;
		dp[0][0] = 0;
		FOR(pos,1,n){
			REP(i,NW){
				if (len[i] > pos) continue;
				int diff = 0;
				int first = -5, last = -5;
				REP(j,len[i]){
					if (word[i][j] != s[j+pos-len[i]]){
						if (j - last < 5){
							diff = -1; break;
						}
						if (first == -5) first = j;
						diff++; last = j;
					}
				}
				if (diff == -1) continue;
				if (last == -5){
					FOR(j,0,pos-len[i]){
						if (dp[pos-len[i]][j] < dp[pos][j]) dp[pos][j] = dp[pos-len[i]][j];
					}
				}
				else FOR(j,0,pos-len[i]){
					if (first+pos-len[i]+1 - j < 5 && j != 0) continue;
					if (dp[pos-len[i]][j] + diff < dp[pos][last+pos-len[i]+1]) dp[pos][last+pos-len[i]+1] = dp[pos-len[i]][j] + diff;
				}
			}
		}
		ans = n;
		FOR(last,0,n) if (dp[n][last] < ans){
			ans = dp[n][last];
		}
		
		printf("Case #%d: %d\n",itc,ans);
	}
	
	
	return 0;
}
