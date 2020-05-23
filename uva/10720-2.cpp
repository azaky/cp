#include <cstdio>
#include <algorithm>
using namespace std;

int n, d[maxn], sum[maxn], rmax[maxn];

int main(){
	do{
		scanf("%d",&n);
		if (!n) return 0;
		for (int i=1; i<=n; ++i) scanf("%d",&d[i]);
		sort(d+1,d+n+1);
		//check sum
		bool valid = true;
		sum[0] = 0;
		for (int i=1; i<=n; ++i){
			sum[i] = sum[i-1] + d[i];
			if (d[i] >= n || d[i] < 0) valid = false;
		}
		if (sum[n] % 2 != 0 || !valid){
			puts("Not possible");
			continue;
		}
		//erdos-gallai theorem
		valid = true;
		int now = 0; d[n+1] = n+1;
		for (int r = 1; r <= n; ++r){
			while (d[now] <= r) ++now;
			--now;
			rmax[r] = now;
		}
		for (int r = 1; r < n; ++r){
			lhs = sum[r]-sum[i-1];
			rhs = r*(r-1) + (rmax[r] < r+1 ? (n-r)*r : rhs += sum[rmax[r]]-sum[r] + (n-rmax[r])*r);
			if (lhs > rhs) valid = false;
		}
		if (valid) puts("Possible"); else puts("Not possible");
	}

}
