#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n,a[2222],l,r,ll,rr,total;

int findmore(int x){
	int l = 0, r = n+1, mid;
	while (l<r){
		mid = (l+r)/2;
		if (a[mid]<=x) l = mid+1;
			else r = mid;
		}
	return l;
}

int main(){
	while (1){
		scanf("%d",&n);
		if (n==0) break;
		a[0] = -1; a[n+1] = 1000000000;
		for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
		sort(a,a+(n+2));
		total = 0;
		for (int i=1; i<=n; ++i)
			for (int j=i+1; j<=n; ++j){
				if (a[i]+a[j]>a[n]) break;
				total += n-findmore(a[i]+a[j])+1;
				}
		printf("%d\n",total);
	}
	return 0;
}
