#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

struct circle{
       double r,pos;
       bool used;
       };

int n,m;
double best;
circle circ[8];

void calc(int k, double l, double r){
     double l0,r0;
     if (k==m){
               best=min(best,r-l);
               return;
               }
     if (r-l>=best) return;
     for (int i=0; i<m; i++){
         if (circ[i].used) continue;
         circ[i].pos=0;
         for (int j=0; j<m; j++)
             if (circ[j].used)
                circ[i].pos=max(circ[i].pos,circ[j].pos+2*sqrt(circ[i].r*circ[j].r));
         l0=min(l,circ[i].pos-circ[i].r);
         r0=max(r,circ[i].pos+circ[i].r);
         circ[i].used=true;
         calc(k+1,l0,r0);
         circ[i].used=false;
         }
     }

int main(){
    scanf("%d\n",&n);
    for (int kasus=0; kasus<n; kasus++){
        scanf("%d",&m);
        for (int i=0; i<m; i++) scanf("%lf",&circ[i].r);
        best=1e50;
        calc(0,0,0);
        printf("%.3lf\n",best);
        }
    return 0;
}
