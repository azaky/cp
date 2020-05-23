#include <cstdio>
#include <string>
#include <iostream>
#define MAXN 1001001
using namespace std;

int tc,n,a[MAXN],allnine,ans[MAXN],larger,p;
string s;

int main(){
	scanf("%d\n",&tc);
	while (tc--){
		getline(cin,s);
		n = s.length();
		for (int i=0; i<n; ++i)
			a[i] = (int)s[i] - 48;
		allnine = 1;
		for (int i=0; i<n; ++i)
			if (a[i]!=9) allnine = 0;
		if (allnine){
			printf("1");
			for (int i=1; i<n; ++i) printf("0");
			printf("1\n");
			continue;
		}
		for (int i=0; i<(n+1)/2; ++i){
			ans[i] = a[i];
			ans[n-1-i] = ans[i];
		}
		larger = 0;
		for (int i=0; i<n; ++i)
			if (ans[i] > a[i]){
				larger = 1;
				break;
			}
			else if (ans[i] < a[i]) break;
		if (!larger){
			for (int i=0; i<(n+1)/2; ++i)
				if (ans[i]!=9) p = i;
			++ans[p];
			if (p!=n-1-p) ++ans[n-1-p];
			for (int i=p+1; i<(n+1)/2; ++i){
				ans[i] = 0;
				ans[n-1-i] = 0;
			}
		}
		for (int i=0; i<n; ++i) printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}
			
