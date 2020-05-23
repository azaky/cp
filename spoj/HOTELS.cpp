#include <cstdio>

using namespace std;

int n, head, tail;
long long m, ans = 0, a[311111], sum[311111];

long long getsum(){return sum[tail]-sum[head-1];}

int main(){
	scanf("%d%lld",&n,&m);
	for (int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	sum[0] = 0;
	for (int i=1; i<=n; ++i) sum[i] = sum[i-1] + a[i];
	head = tail = 1;
	while (tail<=n){
		while (getsum() > m) ++head;
		while (getsum() <= m){
			if (getsum() > ans) ans = getsum();
			++tail;
			if (tail>n) break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
