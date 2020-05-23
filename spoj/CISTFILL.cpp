#include <cstdio>
#include <cstdlib>
#include <cmath>
#define MAXN 50005
#define EPS 1e-7
using namespace std;

int tc,n,w,h,b[MAXN],d[MAXN],a[MAXN];
double total,v,l,r,mid;

int main(){
	scanf("%d",&tc);
	while (tc--){
		scanf("%d",&n);
		total = 0;
		for (int i=0; i<n; ++i){
			scanf("%d%d%d%d",&b[i],&d[i],&w,&h);
			a[i] = w*h;
			total += (double)a[i]*d[i];
		}
		scanf("%lf",&v);
		if (v>total){
			printf("OVERFLOW\n");
			continue;
		}
		l = 0.0;
		r = 1100000.0;
		while ((r-l)>EPS){
			mid = (l+r)/2.0;
			total = 0;
			for (int i=0; i<n; ++i)
				if (mid > (double)(b[i]+d[i])) total += (double)(a[i]*d[i]);
					else if (mid > (double)b[i]) total += (double)a[i]*(mid-(double)b[i]);
			//printf("%.2lf %.2lf %.2lf\n",l,r,total);
			if (total < v) l = mid;
				else  r = mid;
		}
		printf("%.2lf\n",l);
	}
	return 0;
}
