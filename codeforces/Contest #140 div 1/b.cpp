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
long long a[MAXN],sum[MAXN],p,t,mul,l,k,ans,ans1;
int n,q;

long long getsum(int l,int r){
	return sum[r]-sum[l-1];
}

int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; ++i) scanf("%I64d",&a[i]);
	sort(a+1,a+(n+1));
	sum[0] = 0;
	for (int i=0; i<n; ++i) sum[i] = sum[i-1]+a[i];
	scanf("%d",&q);
	ans1 = 0;
	for (int i=1; i<n; ++i) ans1 += (n-i)*a[i];
	while (q--){
		scanf("%I64d",&k);
		if (k+1 > n){
			printf("%I64d ",getsum(1,n-1));
			continue;
		}
		if (k==1){
			printf("%I64d ",ans1);
			continue;
		}
		ans = 0;
		p = n; t = 1; mul = 0;
		while (p > 1){
			t *= k;
			++mul;
			l = max(1LL,p-t);
			ans += mul*getsum(l,p-1);
			p -= t;
		}
		printf("%I64d ",ans);
	}
	return 0;
}
