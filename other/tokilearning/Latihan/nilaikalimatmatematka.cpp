#include <stdio.h>
#include <iostream>

using namespace std;

int a,b;
string ch;

int main(){
    cin >> a >> ch >> b;
    if (ch=="-") cout << a-b << endl;
      else if (ch=="+") cout << a+b << endl;
        else if (ch=="*") cout << a*b << endl;
          else if (ch=="<") if (a<b) cout << "benar" << endl;
                     else cout << "salah" << endl;
          else if (ch==">") if (a>b) cout << "benar" << endl;
                     else cout << "salah" << endl;
          else if (ch=="=") if (a==b) cout << "benar" << endl;
                     else cout << "salah" << endl;
    //system("pause");
    return 0;
}
