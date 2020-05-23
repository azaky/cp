#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string s;
    
    cin >> s;
    for (int i=1; i<s.length(); i++)
        if (s[i]==s[i-1])
           if (s[i]=='a') s[i]='b';
           else s[i]='a';
    cout << s << endl;
    return 0;
}
