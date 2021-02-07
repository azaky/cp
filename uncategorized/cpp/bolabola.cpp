#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
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
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

int getint(){
	int ret = 0, mul = 1;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-'){
		mul = -1;
		ch = getchar();
	}
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar()) && ('0' <= ch && ch <= '9'));
	return ret*mul;
}
void getint(int &x){
	x = getint();
}
long long getLL(){
	long long ret = 0, mul = 1LL;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-'){
		mul = -1LL;
		ch = getchar();
	}
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar()) && ('0' <= ch && ch <= '9'));
	return ret*mul;
}
void getLL(long long &x){
	x = getLL();
}

/* -------------- end of azaky's template -------------- */

#define INF 1000000000
#define MAXN 1004
int n, a[MAXN][MAXN], sumc[MAXN][MAXN], dp[MAXN][MAXN], maxdp[MAXN][MAXN];

int main(){
	scanf("%d",&n);
	for (int i=1; i <= n; ++i)
		for (int j=1; j <= i; ++j){
			scanf("%d",&a[i][j]);
			sumc[i][j] = sumc[i-1][j] + a[i][j];
		}
	for (int y = n; y > 0; --y){
		maxdp[y-1][y] = -INF;
		for (int x = y; x <= n; ++x){
			dp[x][y] = sumc[x][y] + maxdp[x+1][y+1];
			maxdp[x][y] = max(maxdp[x-1][y],dp[x][y]);
		}
		maxdp[n+1][y] = maxdp[n][y];
	}
	printf("%d\n",maxdp[n][1]);
	return 0;
}