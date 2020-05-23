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

int main(){
	getline(cin,dummy);
	scanf("%d",&n);
	s = (n*(n+1))/2;
	for (int i=0; i<s; ++i) scanf("%d",&a[i]);
	sort(a,a+s);
	if (n==1){
		printf("%d\n",a[0]); return 0;
	}
	for (int i=0; i<(n-2); ++i){
		ans[2+i][0] = a[2*i+1];
		ans[2+i][1] = a[2*i];
		used[2*i+1] = used[2*i] = 1;
	}
	idx = 0;
	for (int i=s-1; i>=s-n-1; --s){
		used[i] = 1;
		c[idx++] = a[i];
	}
	
