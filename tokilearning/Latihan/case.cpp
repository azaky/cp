#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n;

int main(){
    scanf("%d",&n);
    if (n<10) printf("satuan\n");
      else if (n<100) printf("puluhan\n");
        else if (n<1000) printf("ratusan\n");
          else if (n<10000) printf("ribuan\n");
            else printf("puluhribuan\n");
    //system("pause");
    return 0;
}
