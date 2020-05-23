/*
ID: a_zaky01
PROG: humble
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

int k,n,p[99],temp[99];
long long h[100001];
FILE *fin,*fout;

int main(){
    fin=fopen("humble.in","r");
    fout=fopen("humble.out","w");
    fscanf(fin,"%d %d",&k,&n);
    for (int i=0; i<k; i++)
        fscanf(fin,"%d",&p[i]);
    h[0]=1;
    for (int i=1; i<=n; i++){
        h[i]=p[0]*h[temp[0]];
        for (int j=1; j<k; j++)
            if (p[j]*h[temp[j]]<h[i])
               h[i]=p[j]*h[temp[j]];
        for (int j=0; j<k; j++)
            if (p[j]*h[temp[j]]==h[i])
               temp[j]++;
               }
    fprintf(fout,"%lld\n",h[n]);
    //system ("pause");
    return 0;
}       
