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

/* -------------- end of azaky's template -------------- */

long long n,k,a[111111],l,need[111111],ans,nans;

int main(){
	scanf("%I64d%I64d",&n,&k);
	for (int i=0; i<n; ++i) scanf("%I64d",&a[i]);
	sort(a,a+n);
	l = 0;
	ans = -1000000000;
	for (int i=0; i<n; ++i){
		if (i==0) need[i] = 0;
			else need[i] = need[i-1] + (i-l)*(a[i]-a[i-1]);
		while (need[i] > k){
			need[i] -= a[i] - a[l];
			++l;
		}
		if (i-l > ans){
			ans = i-l;
			nans = a[i];
		}
	}
	printf("%I64d %I64d\n",ans+1,nans);
	return 0;
}
