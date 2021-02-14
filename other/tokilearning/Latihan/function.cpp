#include <stdio.h>

using namespace std;

int fact(int a);

int main(){
    int n;
    
    scanf("%d",&n);
    if (n<0 || n>10) printf("ditolak\n");
       else printf("%d\n",fact(n));
    
    return 0;
}

int fact(int a){
    if (a==0) return 1;
    return a*fact(a-1);
}
