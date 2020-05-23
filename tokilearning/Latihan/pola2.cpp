#include <iostream>

using namespace std;

int n, t=0;

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            cout << t%10;
            t++;
            }
        cout << endl;
        }
    //system("pause");
    return 0;
}
