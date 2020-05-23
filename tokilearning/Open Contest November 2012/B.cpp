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

int n,a[1111],ans1[1111],ans2[1111],k;

int calc(int *x){
	int ret = 0;
	for (int i=1; i<n; ++i) ret += abs(x[i]-x[i-1]);
	return ret;
}
void print(int *x){
	for (int i=0; i+1<n; ++i) printf("%d ",x[i]);
	printf("%d\n",x[n-1]);
}

int main(){
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%d",&a[i]);
	sort(a,a+n);
	k = 0;
	if (n%2 == 0){
		k = 0;
		for (int l=0,r=n/2; r < n && l < n/2; ++l, ++r){
			ans1[k++] = a[l];
			ans1[k++] = a[r];
		}
		k = 0;
		for (int l=0,r=n/2; r < n && l < n/2; ++l,++r){
			ans2[k++] = a[r];
			ans2[k++] = a[l];
		}
	}
	else {
		k = 0;
		for (int l=0,r=n/2; r < n || l < n/2; ++l,++r){
			ans1[k++] = a[r];
			if (l<n/2) ans1[k++] = a[l];
		}
		k = 0;
		for (int l=0,r=(n/2)+1; r < n || l <= n/2; ++l,++r){
			ans2[k++] = a[l];
			if (r<n) ans2[k++] = a[r];
		}
	}
	if (calc(ans1)>calc(ans2)) print(ans1); else print(ans2);
	return 0;
}
