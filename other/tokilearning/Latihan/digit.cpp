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
	int sign; //in this beta template, so we work on assumption that BigNum is always nonnegative
	int length(){
		int ret = maxd;
		while (d[ret]==0 && ret>=0) --ret;
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

inline BigNum sum(BigNum A, BigNum B){
	int iA = A.length(),iB = B.length(),i;
	if (A.d[iA]==0) return B;
		else if (B.d[iB]==0) return A;
	BigNum ret;
	int carry = 0, s = 0;
	for (i=0; i<=iA || i<=iB; ++i){
		s = carry + A.d[i] + B.d[i];
		carry = s/base; s %= base;
		ret.d[i] = s;
	}
	if (carry>0) ret.d[i++] = carry;
	return ret;
}

inline BigNum product(BigNum A,BigNum B){
	int iA = A.length(),iB = B.length(),p;
	BigNum ret;
	if (A.d[iA]==0 || B.d[iB]==0) return ret;
	for (int _iA=0; _iA<=iA; ++_iA)
		for (int _iB=0; _iB<=iB; ++_iB){
			p = A.d[_iA]*B.d[_iB];
			ret.d[_iA+_iB] += p%base;
			ret.d[_iA+_iB+1] += p/base;
		}
	for (int i=0; i<maxd; ++i){
		ret.d[i+1] += ret.d[i]/base;
		ret.d[i] %= base;
	}
	return ret;
}

inline BigNum power(BigNum A,int p){
	BigNum ret;
	if (p==0){
		ret.d[0] = 1;
		return ret;
	}
	ret = power(A,p/2);
	ret = product(ret,ret);
	if (p&1) ret = product(ret,A);
	return ret;
}

/* -------------- end of azaky's template -------------- */

const int MAXN = 5050;
BigNum now;
int len,s[MAXN],tc,n;

int main(){
	BigNum now;
	now.d[0] = 1; len = 0;
	for (int i=0; i<MAXN; ++i){
		for (int j=0; j<=len; ++j) s[i]+= now.d[j];
		now = sum(now,now);
		if (now.d[len+1]>0) ++len;
	}
	scanf("%d",&tc);
	while (tc--){
		scanf("%d",&n); printf("%d\n",s[n]);
	}
	return 0;
}
