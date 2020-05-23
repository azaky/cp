#include <cstdio>

using namespace std;

#define MAXN 111111

int n, x, a[MAXN], l[MAXN], r[MAXN], s[MAXN];
long long ans, w, h;

int main(){
	while (1){
		scanf("%d",&n);
		if (n==0) break;
		for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
		a[0] = a[n+1] = -1;
		
		x = 1; s[x] = 1;
		for (int i=2; i<=n+1; ++i){
			while (a[s[x]] > a[i]){
				r[s[x]] = i;
				--x;
			}
			s[++x] = i;
        }
		
		x = 1; s[x] = n;
		for (int i=n-1; i>=0; --i){
			while (a[s[x]] > a[i]){
				l[s[x]] = i;
				--x;
			}
			s[++x] = i;
        }
		
		ans = 0;
		for (int i=1; i<=n; ++i){
			w = (long long)(r[i]-l[i]-1);
			h = (long long)(a[i]);
			if (w*h > ans) ans = w*h;
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
