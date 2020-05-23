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

const int MAXN = 111;
int tc, ans,aa,bb,n,a[MAXN],x;

int calc(int k){
	int ret = 0;
	while (k < n){
		if (aa <= a[k] && a[k] <= bb){
			++ret; k += a[k];
		}
		else break;
	}
	return ret;
}

int main(){
	scanf("%d",&tc);
	for (int _tc=1; _tc <= tc; ++_tc){
		scanf("%d%d%d",&n,&aa,&bb);
		for (int i=0; i<n; ++i) scanf("%d",&a[i]);
		ans = 0;
		for (int i=0; i<n; ++i){
			x = calc(i);
			if (x>ans) ans = x;
		}
		printf("Case #%d: %d\n",_tc,ans);
	}
	return 0;
}
