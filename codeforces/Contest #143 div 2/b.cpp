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

bool possible(int n, int d, int l){
	//if (n==0) return 1 <= d && d <= l;
	int left, right;
	if (n%2==0){
		left = (n/2) - l*(n/2);
		right = l*(n/2) - (n/2);
	} else {
		left = (n/2+1) - l*(n/2);
		right = l*(n/2+1) - (n/2);
	}
	return left <= d && d <= right;
}

int n,d,l,a;

int main(){
	scanf("%d%d%d",&n,&d,&l);
	if (!possible(n,d,l)){
		printf("-1\n"); return 0;
	}
	for (int i=0; i<n; ++i){
		for (a = 1; a <= l; ++a)
			if (possible(n-i-1,a-d,l)) break;
		d = a-d;
		printf("%d ",a);
	}
	return 0;
}
