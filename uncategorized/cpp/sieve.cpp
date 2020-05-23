#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long max,prime[10000000];
bool notprime[10000000];

main(){
       scanf("%d",&max);
       notprime[1]=true;
       for (long i=2; i<=max/2; i++)
           notprime[2*i]=true;
       for (long i=3; i<=floor(sqrt(max)); i++)
           if (!notprime[i])
              for (long j=2; j<=max/i; j++)
                   notprime[j*i]=true;
       prime[1]=2;
       long k=1;
       for (long i=3; i<=max; i++)
           if (!notprime[i]) {
                             k++;
                             prime[k]=i;
                             }
       for (long i=1; i<=k; i++)
           printf("%ld\n",prime[i]);
       system ("pause");
       }
