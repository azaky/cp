#include <stdio.h>

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
long long max(long long a, long long b){return a > b ? a : b;}
#define MAXN 1002
long long n,i,j,x,y,sumc[MAXN][MAXN],dp1[MAXN],dp2[MAXN];

int main(){
	while (1){
		n = getLL(); if (n == 0) return 0;
		for (i=1; i<=n; ++i) sumc[0][i] = 0;
		for (i=1; i<=n; ++i) for (j=1; j<=i; ++j) sumc[i][j] = sumc[i-1][j]+getLL();
		dp2[n+1] = 0;
		for (y=n; y>0; --y){
			dp1[y-1] = 0;
			for (x=y; x<=n; ++x) dp1[x] = max(dp1[x-1],sumc[x][y]+dp2[x+1]);
			dp1[n+1] = dp1[n];
			for (x=y; x<=n+1; ++x) dp2[x] = dp1[x];
		}
		printf("%lld\n",dp1[n]);
	}
}
