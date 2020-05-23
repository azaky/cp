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

int x,y,z,x1,yy1,z1;
int a1,a2,a3,a4,a5,a6,ans;

int main(){
	cin >> x >> y >> z >> x1 >> yy1 >> z1;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	ans = 0;
	if (y < 0) ans += a1;
	if (y > yy1) ans += a2;
	if (z < 0) ans += a3;
	if (z > z1) ans += a4;
	if (x < 0) ans += a5;
	if (x > x1) ans += a6;
	cout << ans << endl;
	return 0;
}
