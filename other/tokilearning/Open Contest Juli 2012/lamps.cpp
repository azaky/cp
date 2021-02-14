#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

#define MAXN 100100

int n,a[MAXN],ans[MAXN],used[MAXN],nans,current;

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    nans = 0;
    for (int i=1; i<=n; ++i){
        current = a[i];
        for (int j=1; j*j<=i; ++j){
            if (i%j!=0) continue;
            if (used[j]) current = 1-current;
            if (j*j!=i && used[i/j]) current = 1-current;
            }
        if (current==1){
                        ans[nans++] = i;
                        used[i] = 1;
                        }
        }
    printf("%d\n",nans);
    for (int i=0; i<nans; ++i) printf("%d\n",ans[i]);
    return 0;
}
