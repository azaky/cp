#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n, t, b[100], sum=0;

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&t);
        sum+=t;
        }
    printf("%d\n",sum);
    //system("pause");
    return 0;
}
