#include <cstdio>

using namespace std;

int kasus = 1,n,k,c[1111];
long long res,x;

int main(){
	while (kasus++){
		scanf("%d",&n);
		if (n==-1) break;
		
		printf("Case %d:\n",kasus-1);
		
		for (int i=n; i>=0; --i) scanf("%d",&c[i]);
		
		scanf("%d",&k);
		for (int i=0; i<k; ++i){
			scanf("%lld",&x);
			res = 0;
			for (int j=n; j>=0; --j)
				res = x*res + (long long)c[j];
			printf("%lld\n",res);
		}
	}
	return 0;
}
