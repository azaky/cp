#include <cstdio>
#include <stdlib.h>

int w,h,n,a,b,c,d,k,arr[19][19];

int main(){
    scanf("%d %d %d",&w,&h,&n);
    for (int i=0; i<n; i++){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        for (int wx=a-1; wx<c; wx++)
            for (int hx=b-1; hx<d; hx++)
                arr[wx][hx]=k;
                }
    for (int hx=0; hx<h; hx++){
        for (int wx=0; wx<w; wx++)
            printf("%d",arr[wx][hx]);
        printf("\n");
        }
    system ("pause");
    return 0;
}
