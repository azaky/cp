#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    int n, v[50005];
    long long m,c,c2;
    double aa=0.0, bb=-1e100, mid, mid2;
    
    scanf("%d %lld",&n,&m);
    for (int i=0; i<n; i++){
        scanf("%d",&v[i]);
        if (v[i]>bb) bb=v[i];
        }
    bb*=2;
    
    for (int k=0; k<64; k++){
        
        mid=(aa+bb)/2.0; mid2=mid-1e-4;
        c=0; c2=0;
        
        for (int i=0; i<n; i++) c=c+(long long)ceil(v[i]/mid);
        for (int i=0; i<n; i++) c2=c2+(long long)ceil(v[i]/mid2);
        
        if (c<=m && c2>m) break;
        else if (c>m) aa=mid;
        else bb=mid;
        }
    
    printf("%.2lf\n",mid);
    return 0;
}
