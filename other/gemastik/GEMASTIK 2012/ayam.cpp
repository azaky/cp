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

const int MAXN = 1111;

int n,up,down;
double vx[MAXN],vy[MAXN],y,xx,yy,t;

int main(){
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%lf%lf",&vx[i],&vy[i]);
	scanf("%lf%lf",&xx,&yy);
	up = down = 0;
	for (int i=0; i<n; ++i){
		t = xx/vx[i];
		y = vy[i]*t - 4.9*t*t;
		if (y <= yy) down = 1;
		if (y >= yy) up = 1;
	}
	if (up&down) printf("Yes\n");
		else printf("No\n");
	return 0;
}
