#include <stdio.h>
#include <stdlib.h>

using namespace std;

int a,b;
double area;

int main(){
    scanf("%d %d",&a,&b);
    area = a*b*0.5;
    printf("%.2lf\n",area);
    //system("pause");
    return 0;
}
