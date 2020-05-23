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

int n,k,same,a[111111];

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; ++i) scanf("%d",&a[i]); a[0] = -1;
	same = 1;
	for (int i=k; i<=n; ++i) if (a[i]!=a[k]) same = 0;
	if (!same){ printf("-1\n"); return 0;}
	for (int i=k; i>=0; --i) if (a[i]!=a[k]){
		printf("%d\n",i); return 0;
	}
	return 0;
}
