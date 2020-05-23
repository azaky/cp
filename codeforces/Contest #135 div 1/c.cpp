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

#define MAXN 100100

int n,a[MAXN],b[MAXN],pa[MAXN],pb[MAXN],l[MAXN],r[MAXN],ansl[MAXN],ansr[MAXN],ans[MAXN],last,_last;

int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for (int i=1; i<=n; ++i) scanf("%d",&b[i]);
	for (int i=1; i<=n; ++i) pa[a[i]] = i;
	for (int i=1; i<=n; ++i) pb[b[i]] = i;
	//leftshift
	for (int i=1; i<=n; ++i) {
		l[i] = pb[i] - pa[i];
		r[i] = pa[i] - pb[i];
		if (l[i]<=0) l[i] += n;
		if (r[i]<=0) r[i] += n;
	}
	sort(l+1,l+(n+1));
	sort(r+1,r+(n+1));
	l[n+1] = r[n+1] = n+1; l[0] = r[0] = 0;
	for (int i=0; i<=n+1; ++i) debug("%d ",l[i]); debug("\n");
	for (int i=0; i<=n+1; ++i) debug("%d ",r[i]); debug("\n");
	memset(ansl,127,sizeof(ansl));
	memset(ansr,127,sizeof(ansr));
	last = -1;
	for (int i=1; i<=n; ++i){
		//if (l[i]==l[i-1]) continue;
		ansl[l[i]] = 0;
		for (_last = l[i-1]; _last<l[i]; ++_last){
			ansl[_last] = min(ansl[_last],l[i] - _last);
		}
		last = _last;
	}
	last = -1;
	for (int i=1; i<=n; ++i){
		//if (r[i]==r[i-1]) continue;
		ansr[r[i]] = 0;
		for (_last = r[i-1]; _last<r[i]; ++_last){
			ansr[_last] = min(ansr[_last],r[i] - _last);
		}
		last = _last;
	}
	for (int i=0; i<=n; ++i) debug("%d ",ansl[i]); debug("\n");
	for (int i=0; i<=n; ++i) debug("%d ",ansr[i]); debug("\n");
	for (int i=0; i<=n; ++i){
		ans[i] = min(ansl[i],ansr[n-i]);
		if (ans[i] == n) ans[i] = 0;
	}
	for (int i=0; i<n; ++i) printf("%d\n",ans[i]);
	
	return 0;
}
