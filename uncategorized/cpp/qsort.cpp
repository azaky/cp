#include <stdio.h>
#include <stdlib.h>

int n,a[99];

void qsort(int l,int r);

main(){
       scanf("%d",&n);
       for (int i=0; i<n; i++)
           scanf("%d",&a[i]);
       qsort(0,n-1);
       for (int i=0; i<n-1; i++)
           printf("%d ",a[i]);
       printf("%d\n",a[n-1]);
       system ("pause");
}

void qsort(int l, int r){
     int i,j,mid,temp;
     i=l;
     j=r;
     mid=a[(l+r)/2];
     do {
         while (a[i]<mid) i++;
         while (a[j]>mid) j--;
         if (i<=j){
                  temp=a[i];
                  a[i]=a[j];
                  a[j]=temp;
                  i++;
                  j--;
                  }
                  }
     while (i<=j);
     if (l<j) qsort(l,j);
     if (i<r) qsort(i,r);
     }
