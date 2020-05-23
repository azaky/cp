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

const int MAXN = 211;
int tc,r,c,a[MAXN][MAXN],x,sum[MAXN][MAXN],cot[2],ans,xx[MAXN];

int main(){
	scanf("%d",&tc);
	while (tc--){
		scanf("%d%d",&r,&c);
		for (int i=1; i<=r; ++i)
			for (int j=1; j<=c; ++j){
				scanf("%d",&x);
				a[i][j] = x & 1;
			}
		for (int i=1; i<=r; ++i){
			sum[i][0] = 0;
			for (int j=1; j<=c; ++j) sum[i][j] = (sum[i][j-1] + a[i][j]) & 1;
		}
		ans = 0;
		for (int ll=1; ll<=c; ++ll)
			for (int rr=ll; rr<=c; ++rr){
				debug("L=%d; R=%d\n",ll,rr);
				cot[0] = 1; cot[1] = 0;
				xx[0] = 0;
				for (int i=1; i<=r; ++i){
					xx[i] = (xx[i-1]+sum[i][rr]-sum[i][ll-1]+2) & 1;
					debug("%d\n",xx[i]);
					ans += cot[xx[i]];
					++cot[xx[i]];
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}
