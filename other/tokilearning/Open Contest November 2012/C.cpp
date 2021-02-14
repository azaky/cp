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

int sqr(int x){return x*x;}

#define INF 1000000
char s[111];
int n,k,nkismis,dp[111][111][111],ans,addk,kismis[111];

int main(){
	scanf("%d%d%s",&n,&k,s);
	for (int i=n; i>0; --i) s[i] = s[i-1];
	nkismis = 0;
	for (int i=1; i<=n; ++i)
		if (s[i] == 'x') kismis[++nkismis] = i;
	for (int i=1; i<=nkismis; ++i) debug("KISMIS %d\n",kismis[i]);
	for (int idx = 1; idx <= nkismis; ++idx)
		for (int pos = idx; pos <= n-(nkismis-idx); ++pos)
			for (int kk = 0; kk <= k; ++kk){
				//the basis
				if (idx == 1){
					dp[idx][pos][kk] = (kk == abs(pos-kismis[1])) ? sqr(pos-1) : -INF;
				debug("DP[%d][%d][%d] = %d\n",idx,pos,kk,dp[idx][pos][kk]);
					continue;
				}
				//the inductive step
				addk = abs(pos-kismis[idx]);
				dp[idx][pos][kk] = -INF;
				for (int pos2 = idx-1; pos2 < pos; ++pos2)
					for (int kk2 = 0; kk2+addk <= kk; ++kk2)
						dp[idx][pos][kk] = max(dp[idx][pos][kk],dp[idx-1][pos2][kk2]+sqr(pos-pos2-1));
				debug("DP[%d][%d][%d] = %d\n",idx,pos,kk,dp[idx][pos][kk]);
			}
	ans = -INF;
	for (int pos = nkismis; pos <= n; ++pos)
		for (int kk = 0; kk <= k; ++kk)
			ans = max(ans,dp[nkismis][pos][kk]+sqr(n-pos));
	printf("%d\n",ans);
		
	return 0;
}
