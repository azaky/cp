 #include <iostream>
 using namespace std;
 class C1 {
	 float i, j;
 public:
 C1 (void) { i = 0; j = 1; }
 };
 class C2 {
 int x,y;
 public:
 C2 (float a, float b) { x=a; y=b; }
 int plus() { return x+y;}
 };
 int main () {
 C1 d;
 C2 * p1;
 p1 = (C2*)&d;
 cout << p1->plus();
 return 0;
 }
