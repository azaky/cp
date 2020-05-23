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
#define REPD(i,n) for (int i = n-i; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) (s.find(a) != s.end())

/* -------------- end of azaky's template -------------- */

#define MAX 305
int n,h[MAX],dp[MAX][MAX][MAX],visited[MAX][MAX][MAX];

int calc(int k, int a, int b){
	if (k == n) return 3*a;
	if (k == n-1) return min(a,b)*5 + abs(a-b)*3;
	if (visited[k][a][b]) return dp[k][a][b];
	visited[k][a][b] = 1;
	dp[k][a][b] = 1000000000;
	if ((h[k+2] <= a && h[k+2] <= b && !(h[k+2] == a && h[k+2] == b)) || (a < b && b > h[k+2] && a < h[k+2])){
		FOR(i,0,h[k+2]){
			int _a = a-i, _b = b-i, _c = h[k+2]-i;
			if (_a < 0 || _b < 0) break;
			if (_a < _b) dp[k][a][b] = min(dp[k][a][b],7*i+5*_a+calc(k+1,_b-_a,_c));
			else /* _a >= _b */ dp[k][a][b] = min(dp[k][a][b],7*i+5*_b+3*(_a-_b)+calc(k+2,_c,h[k+3]));
		}
	}
	else{
		int i = min(min(a,b),h[k+2]);
		int _a = a-i, _b = b-i, _c = h[k+2]-i;
		if (_a < _b) dp[k][a][b] = min(dp[k][a][b],7*i+5*_a+calc(k+1,_b-_a,_c));
		else /* _a >= _b */ dp[k][a][b] = min(dp[k][a][b],7*i+5*_b+3*(_a-_b)+calc(k+2,_c,h[k+3]));
	}
	return dp[k][a][b];
}

int main(){
	//freopen("skyline.in","r",stdin);
	//freopen("skyline.out","w",stdout);
	
	
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&h[i]);
	
	printf("%d\n",calc(1,h[1],h[2]));
	
	return 0;
}
