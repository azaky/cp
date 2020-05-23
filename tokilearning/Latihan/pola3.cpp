#include <iostream>

using namespace std;

int n, k;

int main(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        if (i%k) cout << i;
           else cout << "*";
        if (i==n) cout << endl;
           else cout << " ";
           }
    //system("pause");
    return 0;
}
