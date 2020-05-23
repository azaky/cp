#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int max(int a, int b);

main(){
       int a,b;
       scanf("%d %d",&a,&b);
       swap(&a,&b);
       printf("%d %d\n",a,b);
       printf("%d\n",max(a,b));
       system ("pause");
}

void swap(int *a, int *b){
     int temp;
     temp=*a;
     *a=*b;
     *b=temp;
}
     
int max(int a,int b){
    if (a>b) return max(b,a);
       else return b;
}
