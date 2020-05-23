#include <cstdio>
#include <stdlib.h>
#include <math.h>

int a,b,count=0;
bool prime;

int main(){
    scanf("%d %d",&a,&b);
    for (int i=a; i<=b; i++){
        if (i>1){
                 prime=true;
                 for (int j=2; j<=floor(sqrt(i)); j++)
                     if (i%j==0){
                                 prime=false;
                                 break;
                                 }
                 if (!prime) ++count;
                 }
                 }
    printf("%d\n",count);
    //system ("pause");
    return 0;
}
