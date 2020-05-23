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

#define MAXN 111111
int k,b,n,sum[MAXN],a[MAXN],tar[MAXN];
map <int,int> cot;
long long ans,ans0;

int main(){
	scanf("%d%d%d",&k,&b,&n);
	sum[0] = 0; tar[0] = b % (k-1);
	for (int i=1; i<=n; ++i){
		scanf("%d",&a[i]);
		sum[i] = (sum[i-1] + a[i]) % (k-1);
		tar[i] = (sum[i] + b) % (k-1);
	}
	for (int i=0; i<=n; ++i) debug ("%d ",sum[i]); debug("\n");
	for (int i=0; i<=n; ++i) debug ("%d ",tar[i]); debug("\n");
	
	debug("\n");
	for (int i=n; i>=0; --i){
		if (cot.count(tar[i])) ans += (long long)cot[tar[i]];
		debug("%I64d\n",ans);
		cot[sum[i]]++;
	}
	
	int c = 0;
	for (int i=1; i<=n; ++i){
		if (a[i]!=0){
			ans0 += ((long long)c*(long long)(c+1))/2;
			c = 0;
		}
		else ++c;
	}
	ans0 += ((long long)c*(long long)(c+1))/2;
	
	if (b==0) ans = ans0;
		else if (b==k-1) ans -= ans0;
	if (ans<0) ans = 0;
	printf("%I64d\n",ans);
}
