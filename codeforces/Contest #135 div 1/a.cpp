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

vector <int> oddv,h,l;
int n,a[111111],hh,ll;

int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
	a[0] = 1; a[n+1] = 1000000005;
	for (int i=1; i<=n; ++i) ++a[i];
	for (int i=1; i<=n; ++i)
		if (a[i]>a[i-1] && a[i]>a[i+1]) h.push_back(i);
	for (int i=n; i>=1; --i)
		if (a[i]<a[i-1] && a[i]<a[i+1]) l.push_back(i);
	hh = h.size(); ll = l.size();
	debug("%d %d\n",hh,ll);
	if (hh == 0 && ll == 0){
		printf("YES\n"); return 0;
	}
	if (hh == 0){
		swap(a[1],a[l[0]]);
	}
	else if (ll == 0){
		swap(a[n],a[h[0]]);
	}
	else swap(a[h[0]],a[l[0]]);
	for (int i=1; i<=n; ++i)
		if (a[i]<a[i-1]) {
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}
