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

#define LIMIT 10000000
#define MOD 1000000007
long long x = 0, y = 0;

void do_something(void){
	x = (y + y)%MOD;
	y = (x * x)%MOD;
	return;
}

int main(){
	for (long long i=0; i<LIMIT; ++i){
		do_something();
	}
	cout << x << " " << y << endl;
	GetTime
	for (long long i=0; i<LIMIT; ++i){
		do_something();
	}
	cout << x << " " << y << endl;
	GetTime
	debug("write something here\n");
}
