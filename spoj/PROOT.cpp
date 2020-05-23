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

typedef long long LL;

LL power(LL r, LL x, LL p){
	if (x == 0) return 1;
	LL ret = power(r,x>>1,p);
	ret = (ret*ret)%p;
	return x&1 ? (ret*r)%p : ret;
}

LL p, k, tau, primitive, r;
vector<LL> factor;

int main(){
	while (1){
		getLL(p); getLL(k);
		if (p + k == 0) return 0;
		//factorize p-1
		factor.clear();
		for (LL i=1; i*i < p; ++i){
			if ((p-1)%i) continue;
			if (i != p-1) factor.push_back(i);
			if (i*i!=p-1 && i!=1) factor.push_back((p-1)/i);
		}
		tau = (LL)factor.size();
		for (LL i=0; i<k; ++i){
			primitive = 1;
			r = getLL();
			for (LL i=0; i<tau; ++i) if (power(r,factor[i],p) == 1) primitive = 0;
			if (primitive) puts("YES"); else puts("NO");
		}
	}
	
}
