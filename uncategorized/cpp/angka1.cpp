#include <cstdio>
#include <stdlib.h>

int main(){
    int n,j=0,k=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        ++j;
        k=k+j;
        printf("%d\n",k);
        }
    //system ("pause");
    return 0;
}
