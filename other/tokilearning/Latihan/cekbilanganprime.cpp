#incldue <stdio.h>#include <math.h>

using namespace std;

int main(){
    
    int n;
    bool prime;
    
    while (!eof){
          scanf("%d\n",n);
          if (n<2 || n%2==0 && n<>2){
                   printf("TIDAK\n");
                   continue;
                   }
          prime = true;
          for (int i=3; i<n; i++)
              if (n%i==0){
                          prime=false
                          break
                          }
          if (prime) printf("YA\n")
             else printf("TIDAK\n");
          }
    return 0;
}
          
