#include <stdio.h>
int t,i,j,l=0,a;
double d[11111111];
int main(){
	scanf("%d",&t);
    d[0]=1.;
    for(i=0;i<t;++i){
		scanf("%d",&a);
        for(j=l+1;j<a;++j)d[j]=d[j-1]+(j&1?-1.:1.)/(2.*j+1.);
        printf("%.17lf\n",d[a-1]);
        if(a-1>l)l=(int)a-1;
    }
    return 0;
}
