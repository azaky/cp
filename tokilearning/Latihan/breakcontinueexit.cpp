#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n;

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        if (i==93){
                   printf("ERROR\n");
                   break;
                   }
        else if (i%10) printf("%d\n",i);
        }
    //system("pause");
    return 0;
}
