#include <stdio.h>

using namespace std;

void tulis(int n);

int main(){
    int n;
    
    while (scanf("%d\n",&n)!=EOF) tulis(n);
    
    return 0;
}

void tulis(int n){
    if (n<10) printf("satuan\n");
      else if (n<100) printf("puluhan\n");
        else if (n<1000) printf("ratusan\n");
          else if (n<10000) printf("ribuan\n");
            else printf("puluhribuan\n");
}
