#include <cstdio>
#include <stdlib.h>

int n,m=0,k=0,arr[15][15];

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        ++m;
        k=k+m;
        arr[0][i]=k;
        arr[i][0]=k;
        }
    for (int i=1; i<n; i++){
        for (int j=1; j<n; j++){
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            printf("%d",arr[i][j]);
            printf(" ");
            }
        printf("%d\n",arr[i][n-1]);
        }
    system ("pause");
}
