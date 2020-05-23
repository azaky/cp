#include <stdio.h>

using namespace std;

int main(){
    
    int n;
    
    scanf("%d",&n);
    printf("%d\n",n);
    
    for (int i=n/2; i>0; i--)
        if (n%i==0) printf("%d\n",i);
        
    return 0;
}

