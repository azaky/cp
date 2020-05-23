#include <iostream>
#include <stdlib.h>

using namespace std;

int xa,xb,ya,yb;

int main(){
    cin >> xa >> ya >> xb >> yb;
    cout << abs(xa-xb)+abs(ya-yb) << endl;
    //system("pause");
    return 0;
}
