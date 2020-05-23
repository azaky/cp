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

const int MAXN = 100100;
int n,x,a[MAXN],b[MAXN],l,r,mid,lose;

int lala(int m){
	for (int i=0; i<m; ++i)
		if (a[i]+b[m-i-1] >= x) return 1;
	return 0;
}

int main(){
	scanf("%d%d",&n,&x);
	for (int i=0; i<n; ++i) scanf("%d",&a[i]);
	for (int i=0; i<n; ++i) scanf("%d",&b[i]);
	sort(a,a+n); sort(b,b+n);
	if (a[0] + b[0] >= x){
		printf("1 %d\n",n);
		return 0;
	}
	l = 1; r = n; mid = (l+r) / 2;
	while (l < r){
		debug("%d %d\n",l,r);
		mid = (l+r) / 2;
		if (lala(mid)) r = mid - 1;
			else if (!lala(mid+1)) l = mid + 1;
				else {
					r = mid = l;
					break;
				}
	}
	mid = (l+r) / 2;
	++mid;
	debug("%d\n",mid);
	lose = 0;
	for (int i=0; i<mid; ++i)
		if (a[i]+b[mid-i-1] < x) ++lose;
	debug("%d\n",lose);
	printf("1 %d\n",n-lose);
	return 0;
}
