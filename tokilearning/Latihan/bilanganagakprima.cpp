#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    
    int c,t,n;
    
    scanf("%d",&t);
    
    for (int i=0; i<t; i++){
        scanf("%d",&n);
        if (n<8){
                 printf("YA\n");
                 continue;
                 }
        c=0;
        for (int j=2; j<=floor(sqrt(n)); j++)
            if (n%j==0) c++;
        if (c<=1) printf("YA\n");
           else printf("TIDAK\n");
           }
    return 0;
}
