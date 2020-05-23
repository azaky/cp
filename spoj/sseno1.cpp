#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++)
            if ((i+j)%3) cout << "*";
            else cout << "x";
        cout << endl;
        }
    return 0;
}
