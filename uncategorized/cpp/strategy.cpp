#include <stdio.h>
#include <stdlib.h>

void solve(int n0, int c1, int c2, int c3, int time);
int t,n,max,a[2][11];

main(){
       scanf("%d",&t);
       for (int kasus=0; kasus<t; kasus++){
           scanf("%d",&n);
           for (int i=0; i<3; i++)
               for (int j=0; j<n; j++)
                   scanf("%d",&a[i][j]);
           max=0;
           solve(0,0,0,0,0);
           printf("%d\n",max);
           }
}

void solve(int n0, int c1, int c2, int c3, int time){
     if ((n0==n) or (time==280))
        if (c1+c2+c3>max) max=c1+c2+c3;
           else {}
        else {
             n0++;
             solve(n0,c1,c2,c3,time);
             if ((c1<(n+1)/2)/* and ((time+a[0,n0])<=280)*/)
                solve(n0,c1,c2,c3,a[0,n0]);
             
             }
}
