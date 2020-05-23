#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string s;
int n, a[10000];
long long dp[10000];

int main(){	
	while (1){
		getline(cin,s);
		if (s=="0") break;
		
		n = s.length();
		for (int i=0; i<n; i++) a[i] = (int)s[i] - 48;
		
		dp[0] = 1;
		dp[1] = 1;
		for (int i=2; i<=n; i++){
			dp[i] = 0;
			if (a[i-1]!=0) dp[i] += dp[i-1];
			if (a[i-2]==1 || (a[i-2]==2 && a[i-1]<7)) dp[i] += dp[i-2];
		}
		
		printf("%lld\n",dp[n]);
	}
	return 0;
}
	
