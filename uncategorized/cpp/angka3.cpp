#include <cstdio>
#include <stdlib.h>

int n,base,len=0,arr[16];

int main(){
    scanf("%d %d",&n,&base);
    if (n==0) printf("%d \n",n);
    else {
         while (n!=0){
               ++len;
               arr[len]=n%base;
               n=n/base;
               }
         for (int i=len; i>0; i--) printf("%d",arr[i]);
         printf("\n");
         }
    //system ("pause");
    return 0;
}
         
