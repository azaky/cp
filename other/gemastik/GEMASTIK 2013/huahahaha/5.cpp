 #include <iostream>
 using namespace std;
 template class T
 T GetMax(T a,T b) {
 T result;
 result=(a>b)?a:b;
 return(result);
 }
 int main () {
 int i=5,j=6,k
 char a='a',b='b',c;
 k=GetMax<int>(i,j);
 c=GetMax<char>(a,b);
 cout<<k<<endl;
 cout<<c<<endl;
 return 0;
 }
