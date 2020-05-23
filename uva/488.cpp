#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string seq[10], wave[10], num="123456789";

int main(){
    for (int i=1; i<10; i++){
        seq[i]="";
        for (int j=0; j<i; j++) seq[i]=seq[i]+num[i-1];
        wave[i]="";
        for (int j=1; j<=i; j++) wave[i]=wave[i]+seq[j]+"\n";
        for (int j=i-1; j>0; j--) wave[i]=wave[i]+seq[j]+"\n";
        }
    int tc, f, a;
    cin >> tc;
    for (int kasus=0; kasus<tc; kasus++){
        if (kasus>0) cout << endl;
        cin >> a >> f;
        for (int i=1; i<f; i++) cout << wave[a] << endl;
        cout << wave[a];
        }
}
