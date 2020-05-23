#include <stdio.h>

using namespace std;

int main(){
    int n;
    double max,min,sum,z;
    
    scanf("%d %lf", &n, &sum);
    max=min=sum;
    
    for (int i=1; i<n; i++){
        scanf("%lf",&z);
        if (z>max) max=z;
        if (z<min) min=z;
        sum+=z;
        }
    sum/=n;
    
    printf("%.2f %.2f %.2f\n",min,max,sum);
    
    return 0;
}
