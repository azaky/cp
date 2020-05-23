#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

inline int StringToInt(string s){
	int x;
	stringstream(s) >> x;
	return x;
}
inline string IntToString(int x){
	stringstream s;
	s << x;
	return s.str();
}
//BigNum Template
const int base = 10;
const int maxd = 200;
struct BigNum{
	int d[maxd];
	BigNum(){
		memset(d,0,sizeof(d));
	}
	BigNum(int n){
		memset(d,0,sizeof(d));
		n = abs(n);
		for (int i=0; n>0; ++i){
			d[i] = n%10;
			n /= 10;
		}
	}
	BigNum(string s){
		memset(d,0,sizeof(d));
		int _length = s.length();
		for (int i=0; i<_length; ++i) d[i] = (int)s[_length-i-1]-48;
	}
	int &operator[](const int n){
		return d[n];
	}
	int length(){
		int ret = maxd-1;
		while (d[ret]==0 && ret>0) --ret;
		return ret;
	}
	void print(){
		for (int i=length(); i>=0; --i) printf("%d",d[i]);
		return;
	}
	void println(){
		print(); printf("\n");
		return;
	}
};
const BigNum zero = BigNum(0);
bool operator==(BigNum A, BigNum B){
	for (int i=maxd-1; i>=0; --i) if (A.d[i]!=B.d[i]) return false;
	return true;
}
bool operator!=(BigNum A, BigNum B){
	return !(A==B);
}
bool operator<(BigNum A, BigNum B){
	for (int i=maxd-1; i>=0; --i) if (A.d[i]!=B.d[i]) return A.d[i]<B.d[i];
	return false;
}
bool operator>(BigNum A, BigNum B){
	return B<A;
}
bool operator<=(BigNum A, BigNum B){
	return (A<B || A==B);
}
bool operator>=(BigNum A, BigNum B){
	return (A>B || A==B);
}
BigNum operator+(BigNum A){
	return A;
}
BigNum operator+(BigNum A,BigNum B){
	int iA = A.length(),iB = B.length(),i;
	if (A[iA]==0) return B;
		else if (B[iB]==0) return A;
	BigNum ret = zero;
	int carry = 0, s = 0;
	for (i=0; i<=iA || i<=iB; ++i){
		s = carry + A[i] + B[i];
		carry = s/base; s %= base;
		ret[i] = s;
	}
	if (carry>0) ret[i++] = carry;
	return ret;
}
BigNum operator*(BigNum A,BigNum B){
	int iA = A.length(),iB = B.length(),p;
	BigNum ret = zero;
	if (A[iA]==0 || B[iB]==0) return ret;
	for (int _iA=0; _iA<=iA; ++_iA)
		for (int _iB=0; _iB<=iB; ++_iB){
			p = A[_iA]*B[_iB];
			ret[_iA+_iB] += p%base;
			ret[_iA+_iB+1] += p/base;
		}
	for (int i=0; i<maxd; ++i){
		ret[i+1] += ret[i]/base;
		ret[i] %= base;
	}
	return ret;
}
BigNum operator+=(BigNum &A,const BigNum &B){
	A = A+B;
	return A+B;
}
BigNum operator*=(BigNum &A,const BigNum &B){
	A = A*B;
	return A*B;
}

/* -------------- end of azaky's template -------------- */

BigNum power(BigNum a, int b){
	if (a==0) return a;
	if (b==0) return BigNum(1);
	BigNum ret = power(a,b/2);
	ret = ret*ret;
	if (b&1) ret = ret*a;
	return ret;
}

int main(){
	BigNum s;
	return 0;
}
