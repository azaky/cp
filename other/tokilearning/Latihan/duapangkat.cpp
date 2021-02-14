#include <stdio.h>
#include <stdlib.h>

int n;

int main(){
    scanf("%d",&n);
    while (!(n%2)) n=n/2;
    if (n==1) printf("TRUE\n");
      else printf("FALSE\n");
    //system("pause");
    return 0;
}
