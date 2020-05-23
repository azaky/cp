#include <iostream>
using namespace std;

int main(){
 int i = 5;
 double d = 11.7;
 int& r = i;
 double& s = d;
 int *p = &i;
 cout << (*p) * s << endl;
 
 return 0;
}
