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

const LL MAXN = 1000000009;
LL n,x,y,c,l,r,mid;
LL kombi(LL s){return (s*s+s)/2LL;}
LL hitung(LL s, LL x, LL y){
	if (x >= s && y >= s) return kombi(s);
	if (x + y <= s + 1) return x*y;
	if (x >= s) return kombi(s)-kombi(s-y);
	if (y >= s) return kombi(s)-kombi(s-x);
	return x*y - kombi(x+y-s-1);
}
LL nyala(LL s){
	LL ret = 1;
	ret += hitung(s-1,x-1,y-1);
//	debug("%I64d\n",ret);
	ret += hitung(s-1,n-x,y-1);
//	debug("%I64d\n",ret);
	ret += hitung(s-1,n-x,n-y);
//	debug("%I64d\n",ret);
	ret += hitung(s-1,x-1,n-y);
//	debug("%I64d\n",ret);
	ret += min(s,x-1)+min(s,y-1)+min(s,n-x)+min(s,n-y);
	return ret;
}
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&x,&y,&c);
	/*
	for (LL s = 0; s <= 10; ++s){
		debug("DETIK %I64d = %I64d lampu\n",s,nyala(s));
	}
	*/
	
	l = 0; r = MAXN;
	for (LL coba = 0; coba < 100; ++coba){
		mid = (l+r)/2LL;
		if (nyala(mid) >= c) r = mid; else l = mid+1;
	}
	printf("%I64d\n",mid);
	
	return 0;
}
