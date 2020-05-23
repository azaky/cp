long factorial(long n) {
long result = 1;
if(n == 0)
return result;
result = factorial(n-1) * n;
return result;
}

#include <stdio.h>

int main(){
    printf("%ld\n",factorial(5));
    return 0;
}
