#include <cstdio>
#include <cmath>
int main(){
	double l;
	while (scanf("%lf",&l) == 1 && l != 0) printf("%.2lf\n",0.5*l*l/acos(-1.));
	return 0;
}
