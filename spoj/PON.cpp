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

int getint(){
	int ret = 0, mul = 1;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-'){
		mul = -1;
		ch = getchar();
	}
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar()) && ('0' <= ch && ch <= '9'));
	return ret*mul;
}
void getint(int &x){
	x = getint();
}
long long getLL(){
	long long ret = 0, mul = 1LL;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-'){
		mul = -1LL;
		ch = getchar();
	}
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar()) && ('0' <= ch && ch <= '9'));
	return ret*mul;
}
void getLL(long long &x){
	x = getLL();
}

/* -------------- end of azaky's template -------------- */
#define LIM 32768
int GetInt(int l,int r){
	int x = (rand()%LIM)*LIM + (rand()%LIM);
	return l + x%(r-l+1);
}
#define LIMLL 1073741824LL
long long GetLL(long long l, long long r){
	long long x = (long long)GetInt(1,(int)LIMLL)*LIMLL + (long long)GetInt(1,(int)LIMLL);
	return l + x%(r-l+1);
}
long long pmod(long long a, long long b, long long mod){
	if (b == 0) return 1;
	long long ret = pmod(a,b/2,mod);
	ret = (ret*ret) % mod;
	if (b%2) ret = (ret*a) % mod;
	return ret;
}
//long long test[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
bool MillerRabin(long long n){
	if (n < 2) return false;
	if (n < 4) return true;
	if (!(n&1)) return false;
	long long s = 0, d = n-1, r, a, x;
	bool next;
	while (d&1){
		s++; d/=2;
	}
	for (int i=0; i<20000; ++i){
		a = GetLL(2,n-2);
		debug("%I64d\n",a);
		//a = test[i];
		if (a > n-2) return true;
		x = pmod(a,d,n);
		if (x == 1 || x == n-1) continue;
		next = false;
		for (r = 1; r < s; ++r){
			x = (x*x) % n;
			if (x == 1) return false;
			if (x == n-1){
				next = true;
				break;
			}
		}
		if (next) continue;
		return false;
	}
	return true;
}

int main(){
	srand(time(NULL));
	int tc = getint();
	for (int i=0; i<tc; ++i){
		long long p = getLL();
		if (MillerRabin(p)) puts("YES"); else puts("NO");
	}
	return 0;
}
