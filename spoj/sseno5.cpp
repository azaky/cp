#include <iostream>

using namespace std;

int main(){
    int n,r,pos[100];
    cin >> n >> r;
    for (int i=0; i<n; i++) cin >> pos[i];
    int m=pos[0]+2*r,tower=1;
    for (int i=0; i<n; i++)
        if (pos[i]>m){
                      tower++;
                      m=pos[i]+2*r;
                      }
    cout << tower << endl;
    return 0;
}
