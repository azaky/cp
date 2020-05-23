#include <string.h>
#include <iostream>

using namespace std;

int main(){
    string a[3];
    for (int i=0; i<3; i++) cin >> a[i];
    for (int i=0; i<2; i++)
        for (int j=2; j>i; j--)
            if (a[j]+a[j-1]<a[j-1]+a[j]) swap(a[j],a[j-1]);
    cout << a[0] << a[1] << a[2] << endl;
    return 0;
}
