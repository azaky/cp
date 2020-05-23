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

const long long MOD = 1000000007;
const int MAXN = 100000;
int n,t,a[MAXN],p;
long long ans;

int main(){
	scanf("%d%d",&n,&t);
	for (int i=0; i<n; ++i) scanf("%d",&a[i]);
	sort(a,a+n);
	p = 0; ans = 1;
	for (int i=0; i<n; ++i){
		while (a[p]-a[i] <= t && p < n) ++p;
		--p;
		ans = (ans*(long long)(p-i+1))%MOD;
	}
	cout << ans << endl;
	return 0;
}
