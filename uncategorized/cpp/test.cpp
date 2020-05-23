#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int a[100];

int main(){
    for (int i=0; i<10; ++i) scanf("%d",&a[i]);
    sort(a+3,a+8);
    for (int i=0; i<10; ++i) printf("%d ",a[i]);
    printf("\n%d\n",a[-9]);
    system ("pause");
    return 0;
}
