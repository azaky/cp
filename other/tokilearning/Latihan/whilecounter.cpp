#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string s;
int sum;

int main(){
    while (getline(cin,s)){
          sum+=atoi(s.c_str());
          }
    cout << sum << endl;
    //system("pause");
    return 0;
}
