#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long p(int a, int b);

main(){
       int a,b;
       long long hasil;
       scanf("%d %d",&a,&b);
       hasil=pow(a,b)%1000000007;
       printf("%lld\n",hasil);
       system ("pause");
}

long long p(int a, int b){
     long long temp;
     if (b==0) temp=1;
        else if (b%2) temp=a*p(a,b-1);
             else {
                  temp=p(a,b/2);
                  temp=temp*temp;
                  }
     return temp;
}
