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
const int maxd = 5000;
struct BigNum{
	int d[maxd];
	int sign;
	BigNum(){
		memset(d,0,sizeof(d));
		sign = 1;
	}
	BigNum(int n){
		memset(d,0,sizeof(d));
		sign = n<0 ? -1 : 1;
		n = abs(n);
		for (int i=0; n>0; ++i){
			d[i] = n%10;
			n /= 10;
		}
	}
	BigNum(string s){
		memset(d,0,sizeof(d));
		if (s[0]=='-'){
			sign = -1;
			s.erase(0,1);
		}
		else sign = 1;
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
		if (sign<0) printf("-");
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
	if (A.sign!=B.sign) return false;
	for (int i=maxd-1; i>=0; --i) if (A.d[i]!=B.d[i]) return false;
	return true;
}
bool operator!=(BigNum A, BigNum B){
	return !(A==B);
}
bool operator<(BigNum A, BigNum B){
	if (A.sign!=B.sign) return A.sign<B.sign;
	if (A.sign < 0){
		A.sign = B.sign = 1;
		return (B<A);
	}
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
BigNum operator-(BigNum A){
	for (int i=maxd-1; i>=0; --i)
		if (A.d[i]!=0){
			A.sign = -A.sign;
			return A;
		}
	return A;
}
BigNum operator+(BigNum A,BigNum B);
BigNum operator-(BigNum A,BigNum B);
BigNum operator+(BigNum A,BigNum B){
	if (A.sign!=B.sign){
		if (A.sign < 0){
			A.sign = 1;
			return B-A;
		}
		else if (B.sign < 0){
			B.sign = 1;
			return A-B;
		}
	}
	if (A.sign < 0){
		A.sign = B.sign = 1;
		return -(A+B);
	}
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
BigNum operator-(BigNum A,BigNum B){
	if (A < B) return -(B-A);
	if (A.sign!=B.sign) return A+(-B);
	if (A.sign < 0) return (-B)-(-A);
	BigNum ret = zero;
	int iA = A.length();
	for (int i=0; i<=iA; ++i){
		ret[i] = A[i]-B[i];
		if (ret[i]<0){
			ret[i] += base;
			--A[i+1];
		}
	}
	return ret;
}
BigNum operator*(BigNum A,BigNum B){
	int iA = A.length(),iB = B.length(),p;
	BigNum ret = zero;
	if (A[iA]==0 || B[iB]==0) return ret;
	ret.sign = A.sign*B.sign;
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
BigNum operator-=(BigNum &A,const BigNum &B){
	A = A-B;
	return A-B;
}
BigNum operator*=(BigNum &A,const BigNum &B){
	A = A*B;
	return A*B;
}

#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
typedef long long LL;

/* -------------- end of azaky's template -------------- */

LL a, b, dp[2222222];
BigNum dpBIG[100];

int main(){
	cin >> a >> b;
	if (b == 1){
		cout << 1 << endl;
		return 0;
	}
	if (a > 92){
		REP(i,b) dp[i] = 1;
		FOR(i,b,a) dp[i] = dp[i-1]+dp[i-b];
		cout << dp[a] << endl;
		return 0;
	}
	else {
		REP(i,b) dpBIG[i] = (BigNum)1;
		FOR(i,b,a) dpBIG[i] = dpBIG[i-1]+dpBIG[i-b];
		dpBIG[a].println();
		return 0;
	}
	
}
