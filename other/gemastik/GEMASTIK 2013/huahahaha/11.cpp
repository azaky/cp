 #include <iostream>
 using namespace std;
 const char arr[] = {'c', 'b', 'a'};
 void does(int a, int b, int c) { cout << arr[a]; cout << arr[b]; cout << arr[c]; }
 int main() { 
	 int i = 0; 
	 does(i++, i++, i++); 
 return 0;
 }
