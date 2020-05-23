#include <stdio.h>
#include <iostream>
int t,i,j,a,l=0;
int main() {
    std::cin>>t;
    for(i=0;i<t;++i){
        std::cin>>a;
        double d=0;
        for(;j<a;++j)d+=(j&1?-1.:1.)/(2.j+1);
        printf("%.17lf\n",d[a-1]);
    }
    return 0;
}
