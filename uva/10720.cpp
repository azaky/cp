#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 20202;
int n, d[maxn], sum[maxn], rmax[maxn], lhs, rhs;

int main(){
	do{
		scanf("%d",&n);
		if (!n) return 0;
		for (int i=1; i<=n; ++i) scanf("%d",&d[i]);
		sort(d+1,d+n+1); reverse(d+1,d+n+1);
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
		
		int now = n+1; d[0] = n+1; d[n+1] = -1;
		for (int r = 1; r <= n; ++r){
			while (d[now] < r) --now;
			rmax[r] = now;
		}
		for (int r = 1; r < n; ++r){
			lhs = sum[r];
			rhs = r*(r-1) + ((rmax[r] < r+1) ? (sum[n]-sum[r]) : (sum[n]-sum[rmax[r]] + (rmax[r]-r)*r));
			if (lhs > rhs) valid = false;
		}
		
		/*
		for (int r = 1; r < n; ++r){
			lhs = sum[r];
			rhs = r*(r-1);
			for (int i = r+1; i <= n; ++i) rhs += min(r,d[i]);
			if (lhs > rhs) valid = false;
		}
		*/
		if (valid) puts("Possible"); else puts("Not possible");
	}
	while (true);

}
