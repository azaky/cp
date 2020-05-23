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

#define MAXN 500500
#define MAXC 5050
int n,x[MAXN],y[MAXN];
long long xx[MAXC],yy[MAXC],ans;

int main(){
	scanf("%d",&n);
	for (int i=0; i<n; ++i){
		scanf("%d%d",&x[i],&y[i]);
		++xx[x[i]]; ++yy[y[i]];
	}
	for (int i=0; i<n; ++i)
		ans += (xx[x[i]]-1)*(yy[y[i]]-1);
	printf("%lld\n",ans);
	return 0;
}
