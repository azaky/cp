#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 200000
#define INF 2000000000
#define writeln; printf("\n");

using namespace std;

int n,a,b,n1,n2,s1,s2,a1[50],a2[50],sum,sum1[MAXN],sum2[MAXN],l,r,ans = 0;

int main(){
	scanf("%d%d%d",&n,&a,&b);
	s1 = 1 << n;
	for (int i=0; i<n; ++i) scanf("%d",&a1[i]);
	for (int s=0; s<s1; ++s){
		sum = 0;
		for (int i=0; i<n; ++i)
			if ((s & (1 << i)) > 0) sum += a1[i];
		if (a <= sum && sum <= b) ++ans;
	}
	printf("%d\n",ans);
	system("pause");
	return 0;
}
	
