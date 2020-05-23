#include <stdio.h>
#include <stdlib.h>

int k;

main(){
       scanf("%d",&k);
       if (k>=1000){
                    printf("1000 %d\n",k/1000);
                    k=k%1000;
                    }
       if (k>=500){
                   printf("500 %d\n",k/500);
                   k=k%500;
                   }
       if (k>=200){
                   printf("200 %d\n",k/200);
                   k=k%200;
                   }
       if (k>=100){
                   printf("100 %d\n",k/100);
                   k=k%100;
                   }
       if (k>=50){
                  printf("50 %d\n",k/50);
                  k=k%50;
                  }
       if (k>=20){
                  printf("20 %d\n",k/20);
                  k=k%20;
                  }
       if (k>=10){
                  printf("10 %d\n",k/10);
                  k=k%10;
                  }
       if (k>=5){
                 printf("5 %d\n",k/5);
                 k=k%5;
                 }
       if (k>=2){
                 printf("2 %d\n",k/2);
                 k=k%2;
                 }
       if (k>=1) printf("1 %d\n",k);
       //system ("pause");
       exit(0);
}
