#include <cstdio>
#include <cstring>

using namespace std;

int n,a[10][10],ans,shift[10],sum[10],maks;

void brute(int r){
	if (r<n){
		for (int i=0; i<n; ++i){
			shift[r] = i;
			brute(r+1);
		}
		return;
	}
	maks = -1111111111;
	memset(sum,0,sizeof(sum));
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			sum[j] += a[i][(j+shift[i])%n];
	for (int i=0; i<n; ++i)
		if (sum[i]>maks) maks = sum[i];
	if (maks < ans) ans = maks;
	return;
}

int main(){
	while (1){
		scanf("%d",&n);
		if (n<0) break;
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				scanf("%d",&a[i][j]);
		ans = 1111111111;
		shift[0] = 0;
		brute(1);
		printf("%d\n",ans);
	}
	return 0;
}
