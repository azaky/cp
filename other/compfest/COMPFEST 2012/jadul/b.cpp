#include <iostream>
#include <cmath>
using namespace std;

long long tc, a, b, c;

inline long long f(long long x){return a*x*x + b*x + c;};
inline long long m(void){return -b/a/2;}

int main(){
	cin >> tc;
	while (tc--){
		cin >> a >> b >> c;
		cout << (f(m()) > f(m()+1) ? f(m()) : f(m()+1)) << endl;
		//cout << f((long long)round(double(-b)/double(a)/double(2))) << endl;
	}
	return 0;
}
