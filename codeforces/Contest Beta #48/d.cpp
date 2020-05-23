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

int n,a[100100],answer,candidate;

bool check(int x){
	++candidate;
	vector <int> v;
	for (int i=0; i<n; ++i)
		if (i != x) v.push_back(a[i]);
	if ((int)v.size() <= 1) return true;
	int geo = 1;
	if (v[0] == 0){
		for (int i=0; i<(int)v.size(); ++i)
			if (v[i] != 0) geo = 0;
		return geo;
	}
	for (int i=1; i<(int)v.size(); ++i)
		if (v[i]*v[0] != v[i-1]*v[1]) geo = 0;
	return geo;
}

int main(){
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%d",&a[i]);
	if (check(n)) {puts("0"); return 0;}
	candidate = 0;
	for (int i=0; i<n; ++i){
		if (i == 0 || i == n-1){if (check(i)){puts("1"); return 0;}}
		else if (a[i-1]*a[i+1] != a[i]*a[i]){
			if (check(i-1) || check(i) || check(i+1)){
				puts("1"); return 0;
			}
		}
		if (candidate > 20) break;
	}
	puts("2");
	return 0;
}
