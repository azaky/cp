/*
ID: a_zaky01
PROG: ariprog
LANG: C++
*/

/*
This is the same as the solution in the analysis, with a few changes and optimizations.
*/

#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

int len, limit, bound, size=0, bisq[50000];
bool found=false, stat[250001];
FILE *fin, *fout;

int main () {

    fin = fopen("ariprog.in", "r");
    fout = fopen("ariprog.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin,"%d %d",&len,&limit);

    for (int i=0; i<=limit; i++)  
        for (int j=i; j<=limit; j++) {
            if (!stat[i*i+j*j]) {
                bisq[size] = i*i+j*j;
                size++;
            }
            stat[i*i+j*j] = true;
        }

    bound=2*limit*limit;
    sort(bisq,bisq+size);

    if (len==3) for (int diff=1; diff<=bound/(len-1); diff++)
       for (int p=0; bisq[p]<=(bound-((len-2)*diff)); p++) {
           bool meet=true;

           for (int c=1; c<len; c++)
               if (!stat[bisq[p]+c*diff]) {
                  meet=false;
                  break;
                  }

           if (meet) {
              found=true;
              fprintf(fout,"%d %d\n",bisq[p],diff);
              }
           }  
    else for (int diff=4; diff<=bound/(len-1); diff+=4)
         for (int p=0; bisq[p]<=(bound-((len-2)*diff)); p++) {
             bool meet=true;

             for (int c=len-1; c>0; c--)
                  if (!stat[bisq[p]+c*diff]) {
                      meet=false;
                      break;
                      }

             if (meet) {
                found=true;
                fprintf(fout,"%d %d\n",bisq[p],diff);
                }
             }

    if (!found) fprintf(fout,"NONE\n");
    return 0;
}
