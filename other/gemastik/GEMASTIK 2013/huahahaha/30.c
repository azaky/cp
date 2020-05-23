 #include <iostream>
 using namespace std;
 class A {
	 protected:
 int x;
 public:
 A() {x = 0; cout << "A1 ";}
A(int _x) { x = _x; cout << "A2 "; }
A(const A& _A) { x = _A.x; cout << "A3 "; }
 ~A() { cout << "A4 "; }
 void f1() { cout << "Af1 ";}
 void f2() { cout << "Af2 "; }
 };
 class B : public A {
 protected:
 double y;
 public:
 B() { y = 0; cout << "B1 ";}
 B(int a, double b) : A(a) { y = b; cout << "B2 ";}
 B(const B& _B) { y = _B.y; cout << "B3 "; }
 ~B() { cout << "B4 "; }
 void f1() { cout << "Bf1 "; }
 void f2() { cout << "Bf2 "; }
 };
 int main() {
 A a;
 B b;
 A *pa;
 pa = &b;
 pa -> f2();
 return 0;
 }
