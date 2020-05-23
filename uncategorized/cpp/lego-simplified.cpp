#include <cstdio>
using namespace std;

#define MAXN 100100

int tc, n, a[MAXN];
long long length, total;

int calc(){
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%d",&a[i]);
	total = 0;
	for (int i=0; i<n; ++i) total += (long long) a[i];
	length = 1 + total - (long long) n;
	if (total%length==0) return (int)total/length;
		else return (int)((total/length)+1);
}

int main(){
	scanf("%d",&tc);
	while (tc--) printf("%d\n",calc());
	return 0;
}
