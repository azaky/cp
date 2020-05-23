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
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
	#define GetTime int time_void = clock(); printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
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

#define MAXN 100100

int tc, n, a[MAXN];
long long length, total;

int calc(){
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%d",&a[i]);
	total = 0;
	for (int i=0; i<n; ++i) total += (long long) a[i];
	length = 1 + total - (long long) n;
	if (total%length==0) return (int)total/length;
		else return (int)((total/length)+1);
}

int main(){
	scanf("%d",&tc);
	while (tc--) printf("%d\n",calc());
	return 0;
}
