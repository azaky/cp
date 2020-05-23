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

const int maxn = 1000100;
int prime[maxn], prev[maxn], tc, x;
int phi(int x);

int main(){
	//precalculation
	for (int i=0; i<maxn; ++i) prime[i] = 1;
	prime[1] = 0;
	for (int i=2; i*i < maxn; ++i)
		if (prime[i]){
			for (int j=2; i*j < maxn; ++j){
				prime[i*j] = 0;
				prev[i*j] = i;
			}
		}
	tc = getint();
	while (tc--){
		x = getint();
		printf("%d\n",phi(x));
	}		
	return 0;
}
int phi(int x){
	if (x < 3) return 1;
	int ret = 1, p;
	while (x > 1){
		p = prime[x] ? x : prev[x]; x /= p; ret *= p-1;
		while (x % p == 0){
			x /= p;
			ret *= p;
		}
	}
	return ret;
}
