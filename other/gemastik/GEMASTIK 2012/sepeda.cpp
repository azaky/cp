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

const int MAXN = 1001000;
int n,a[MAXN],b[MAXN],turnu,turnd,ans=0;

int main(){
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%d",&a[i]);
	for (int i=0; i<n; ++i) scanf("%d",&b[i]);
	
	for (int i=0; i<n; ++i){
		turnu = b[i]-a[i];
		if (turnu < 0) turnu += 9;
		turnd = a[i]-b[i];
		if (turnd < 0) turnd += 9;
		ans += min(turnu,turnd);
		a[i+1] += b[i]-a[i];
		if (a[i+1] < 1) a[i+1] += 9;
		if (a[i+1] > 9) a[i+1] -= 9;
	}
	printf("%d\n",ans);
	
	return 0;
}
