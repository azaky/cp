#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    int n,x,s;
    while (scanf("%d\n",&n)!=EOF){
          x=(int)ceil((-1+sqrt(1+8*n))/2);
          s=n-(x*(x-1))/2;
          if (x%2) printf("TERM %d IS %d/%d\n",n,x+1-s,s);
          else printf("TERM %d IS %d/%d\n",n,s,x+1-s);
          }
}
