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

int tc, n, k, possible;
long long a[111], sum[111];

int main(){
	scanf("%d",&tc);
	for (int _tc = 1; _tc <= tc; ++_tc){
		scanf("%d%d",&n,&k);
		for (int i=1; i<=n; ++i) scanf("%I64d",&a[i]);
		sort(a+1,a+(n+1));
		sum[0] = 0;
		for (int i=1; i<=n; ++i) sum[i] = sum[i-1] + a[i];
		possible = 0;
		for (int i=k; i<=n; ++i)
			if (sum[i] - sum[i-k-1] > 2*a[i]) possible = 1;
		printf("Case #%d: ",_tc);
		if (possible) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}
