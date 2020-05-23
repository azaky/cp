#include <math.h>
#include <stdio.h>
using namespace std;

int tc;
double n,m,ans;

int main(){
	scanf("%d",&tc);
	for (int itc = 1; itc <= tc; ++itc){
		printf("Scenario #%d:\n",itc);
		scanf("%lf%lf",&n,&m);
		ans = n*m;
		if ((int(n*m))%2) ans = ans + sqrt(2) - 1.0;
		printf("%.2lf\n\n",ans);
	}
	return 0;
}
